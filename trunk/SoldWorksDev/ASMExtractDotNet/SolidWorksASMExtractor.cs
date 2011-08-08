using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

using SldWorks;
using SwConst;


namespace ASMExtractDotNet {
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
        private SldWorks.SldWorks _swApp = null;

        /// <summary>
        /// 模型文件对象
        /// </summary>
        private ModelDoc2 _swModel = null;

        #endregion

        #region Properties
        #endregion

        #region Constructor

        /// <summary>
        /// 构造函数
        ///     初始化成员变量并空值和文件类型进行检查。
        /// </summary>
        /// <param name="swApp"></param>
        public SolidWorksASMExtractor(SldWorks.SldWorks swApp) {
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
            Feature swFeat = (Feature)_swModel.FirstFeature();

            while (swFeat != null && swFeat.GetTypeName2() != "MateGroup") {
                swFeat = swFeat.GetNextFeature();
            }
            
            return swFeat;
        }

        #endregion

    }
}
