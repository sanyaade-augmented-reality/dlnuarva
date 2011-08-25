﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SWDataModel {
    /// <summary>
    /// 组件类型
    /// </summary>
    class SWComponent {
        
        #region 成员变量
        /// <summary>
        /// 组件名称
        /// </summary>
        private string _name = string.Empty;

        /// <summary>
        /// 子组件列表
        /// </summary>
        private List<SWComponent> _subComponents = new List<SWComponent>();

        /// <summary>
        /// 是否为Root组件
        /// </summary>
        private bool _isRoot = false;

        /// <summary>
        /// 包围盒
        /// </summary>
        private SWBoundingBox _boundingBox = null;

        #endregion

        #region 属性

        /// <summary>
        /// 组件名称
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
        /// 自组件列表
        /// </summary>
        public List<SWComponent> SubComponents {
            get {
                return _subComponents;
            }
            set {
                _subComponents = value;
            }
        }

        /// <summary>
        /// 是否是Root组件
        /// </summary>
        public bool IsRoot {
            get {
                return _isRoot;
            }
            set {
                _isRoot = value;
            }
        }

        /// <summary>
        /// 包围盒
        /// </summary>
        public SWBoundingBox BoundingBox {
            get {
                return _boundingBox;
            }
            set {
                _boundingBox = value;
            }
        }

        #endregion
    }
}
