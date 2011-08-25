using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SWDataModel {
    /// <summary>
    /// 包围盒
    /// </summary>
    class SWBoundingBox {
        /// <summary>
        /// 下对角点
        /// </summary>
        public SWPoint LowerCorner {
            get;
            set;
        }

        /// <summary>
        /// 上对角点
        /// </summary>
        public SWPoint UpperCorner {
            get;
            set;
        }
    }
}
