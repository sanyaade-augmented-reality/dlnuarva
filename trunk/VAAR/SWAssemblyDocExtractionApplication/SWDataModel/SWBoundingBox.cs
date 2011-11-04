using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SWAssemblyDocExtractionApplication.SWDataModel {
    /// <summary>
    /// 包围盒
    /// </summary>
    public class SWBoundingBox {
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
