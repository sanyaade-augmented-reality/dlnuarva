using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;

namespace ASMDocTest {
    /// <summary>
    /// 对SolidWorks Assembly模型进行提取的类
    /// 目前版本不适用于拥有子装配体的文件。
    /// <author>杨雨</author>
    /// </summary>
    class SolidWorksASMExtractor {
        #region Members

        /// <summary>
        /// SolidWorks的全局对象
        /// </summary>
        private SldWorks _swApp = null;

        /// <summary>
        /// 模型文件对象
        /// </summary>
        private ModelDoc2 _swModel = null;

        /// <summary>
        /// 配置管理器
        /// </summary>
        private ConfigurationManager _swConfMgr = null;

        /// <summary>
        /// 根节点组件
        /// </summary>
        private Component2 _swRootComp = null;

        #endregion

        #region Properties

        /// <summary>
        /// 获取或设置SldWorks对象
        /// </summary>
        public SldWorks SwApp {
            get {
                return _swApp;
            }
            set {
                _swApp = value;
            }
        }

        /// <summary>
        /// 获取当前SolidWorks环境下的文档
        /// </summary>
        public ModelDoc2 ActiveDoc {
            get {
                return _swModel;
            }
        }

        /// <summary>
        /// 获取根节点组件
        /// </summary>
        public Component2 RootComponent {
            get {
                return _swRootComp;
            }
        }

        #endregion

        #region Constructor

        /// <summary>
        /// 构造函数
        ///     初始化成员变量并空值和文件类型进行检查。
        /// </summary>
        /// <param name="swApp"></param>
        public SolidWorksASMExtractor(SldWorks swApp) {
            if (swApp == null) {
                throw new Exception("参数swApp的值不能为空。");
            }

            _swApp = swApp;
            _swModel = (ModelDoc2)_swApp.ActiveDoc;

            if (_swModel == null) {
                throw new Exception("没有打开的装配体文件。");
            }
            if (_swModel.GetType() != (int)swDocumentTypes_e.swDocASSEMBLY) {
                throw new Exception("文件类型错误。");
            }

            _swConfMgr = _swModel.ConfigurationManager;
            _swRootComp = _swConfMgr.ActiveConfiguration.GetRootComponent3(true);
        }

        #endregion

        #region Operations

        /// <summary>
        /// 获取装配文件的所有配合特征
        /// </summary>
        /// <returns>Feature类型数组（可以使用GetSpecificFeature2方法获得Mate2类型）。</returns>
        public List<Feature> GetFeaturesOfMateGroup() {
            List<Feature> features = new List<Feature>();
            Feature mateGroupFeature = GetMateGroupFeature();

            if (mateGroupFeature == null) {
                return null;
            }

            Feature mateFeature = mateGroupFeature.GetFirstSubFeature();
            while (mateFeature != null) {
                features.Add(mateFeature);
                mateFeature = mateFeature.GetNextSubFeature();
            }
            return features;
        }

        /// <summary>
        /// 获取装配文件的所有配合
        /// </summary>
        /// <returns></returns>
        public List<Mate2> GetMates() {
            List<Mate2> mates = new List<Mate2>();
            Mate2 mate = null;
            Feature mateGroupFeature = GetMateGroupFeature();

            if (mateGroupFeature == null) {
                return null;
            }

            Feature mateFeature = mateGroupFeature.GetFirstSubFeature();
            while (mateFeature != null) {
                mate = (Mate2)mateFeature.GetSpecificFeature2();
                mates.Add(mate);
                mateFeature = mateFeature.GetNextSubFeature();
            }

            return mates;
        }

        /// <summary>
        /// 获取组件对象的特征
        /// </summary>
        /// <param name="component"></param>
        /// <returns></returns>
        public List<Feature> GetFeaturesOfComponent(Component2 component) {
            List<Feature> features = new List<Feature>();
            Feature feature = null;
            //if (component.IsRoot() == true) {
                feature = component.FirstFeature();
                while (feature != null) {
                    features.Add(feature);
                    feature = feature.GetNextFeature();
                }
            //} else {
                
            //}
            return features;
        }

        /// <summary>
        /// 获得父节点的孩子节点
        /// </summary>
        /// <param name="parentFeature"></param>
        /// <returns></returns>
        public List<Feature> GetSubFeaturesOfParentFeature(Feature parentFeature) {
            List<Feature> features = new List<Feature>();
            Feature feature = parentFeature.GetFirstSubFeature();
            while (feature != null) {
                features.Add(feature);
                feature = feature.GetNextFeature();
            }
            return features;
        }

        /// <summary>
        /// 获得与配合相关的零件实体
        /// </summary>
        /// <param name="mate"></param>
        /// <returns></returns>
        public List<MateEntity2> GetMateEntityOfMate(Mate2 mate) {
            int mateEntityCount = 0;
            List<MateEntity2> entities = null;

            mateEntityCount = mate.GetMateEntityCount();
            entities = new List<MateEntity2>();
            for (int i = 0; i < mateEntityCount; ++i) {
                entities.Add(mate.MateEntity(i));
            }

            return entities;
        }

        #endregion

        #region Functions

        /// <summary>
        /// 获得MateGroup节点下的特征
        /// </summary>
        /// <returns>MateGroup节点</returns>
        private Feature GetMateGroupFeature() {
            /*
            Feature swFeat = (Feature)_swModel.FirstFeature();

            while (swFeat != null && swFeat.GetTypeName2() != "MateGroup") {
                swFeat = swFeat.GetNextFeature();
            }
                      
            return swFeat;
             *   */
            return GetFeaturesByTypeName("MateGroup")[0];
        }

        /// <summary>
        /// 通过类型名称获取特征对象
        /// </summary>
        /// <param name="typeName"></param>
        /// <returns></returns>
        private List<Feature> GetFeaturesByTypeName(String typeName) {
            Feature swFeat = (Feature)_swModel.FirstFeature();
            Feature subFeat = null;
            Feature nextFeat = null;
            List<Feature> res = new List<Feature>();
            Stack<Feature> stkFeature = new Stack<Feature>();

            if (swFeat != null) {
                stkFeature.Push(swFeat);
            }

            while (stkFeature.Count != 0) {
                swFeat = stkFeature.Pop();

                if (swFeat.GetTypeName2() == typeName) {
                    res.Add(swFeat);
                }

                nextFeat = swFeat.GetNextFeature();
                if (nextFeat != null) {
                    stkFeature.Push(nextFeat);
                }

                subFeat = swFeat.GetFirstSubFeature();
                if (subFeat != null) {
                    stkFeature.Push(subFeat);
                }
            }

            return res;
        }

        /// <summary>
        /// 通过名称获取特征对象
        /// </summary>
        /// <param name="typeName"></param>
        /// <returns></returns>
        private List<Feature> GetFeaturesByName(String name) {
            Feature swFeat = (Feature)_swModel.FirstFeature();
            Feature subFeat = null;
            Feature nextFeat = null;
            List<Feature> res = new List<Feature>();
            Stack<Feature> stkFeature = new Stack<Feature>();

            if (swFeat != null) {
                stkFeature.Push(swFeat);
            }

            while (stkFeature.Count != 0) {
                swFeat = stkFeature.Pop();

                if (swFeat.Name == name) {
                    res.Add(swFeat);
                }

                nextFeat = swFeat.GetNextFeature();
                if (nextFeat != null) {
                    stkFeature.Push(nextFeat);
                }

                subFeat = swFeat.GetFirstSubFeature();
                if (subFeat != null) {
                    stkFeature.Push(subFeat);
                }
            }

            return res;
        }

        #endregion

    }
}
