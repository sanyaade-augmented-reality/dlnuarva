using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SWDataModel {
    /// <summary>
    /// 组件的主体框架
    /// </summary>
    public class SWBody {
        #region 成员变量

        /// <summary>
        /// 名称
        /// </summary>
        private string _name = string.Empty;

        /// <summary>
        /// Body所包含的面
        /// </summary>
        private List<SWFace> _faces = new List<SWFace>();

        /// <summary>
        /// Body所包含的边
        /// </summary>
        private List<SWEdge> _edges = new List<SWEdge>();

        #endregion

        #region 属性

        /// <summary>
        /// 名称
        /// </summary>
        public string Name {
            get {
                return _name;
            }
            set {
                _name = value;
            }
        }

        /// <summary>
        /// Body所包含的面
        /// </summary>
        public List<SWFace> Faces {
            get {
                return _faces;
            }
            set {
                _faces = value;
            }
        }

        /// <summary>
        /// Body所包含的边
        /// </summary>
        public List<SWEdge> Edges {
            get {
                return _edges;
            }
            set {
                _edges = value;
            }
        }

        #endregion
    }
}
