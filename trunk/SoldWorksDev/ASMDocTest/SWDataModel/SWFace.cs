using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SWDataModel {
    /// <summary>
    /// 三维面
    /// </summary>
    class SWFace {
        #region 成员变量

        /// <summary>
        /// ID
        /// </summary>
        private int _id;

        #endregion

        #region 属性

        /// <summary>
        /// ID
        /// </summary>
        public int ID {
            get {
                return _id;
            }
            set {
                _id = value;
            }
        }

        #endregion
    }
}
