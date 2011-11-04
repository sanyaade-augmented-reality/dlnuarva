using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SWAssemblyDocExtractionApplication.SWDataModel {
    /// <summary>
    /// 顶点
    /// </summary>
    public class SWVertex {
        #region 成员变量

        /// <summary>
        /// 空间中的位置
        /// </summary>
        private SWPoint _point = null;

        #endregion

        #region 属性

        /// <summary>
        /// 空间中的位置
        /// </summary>
        public SWPoint Point {
            get {
                return _point;
            }
            set {
                _point = value;
            }
        }

        #endregion
    }
}
