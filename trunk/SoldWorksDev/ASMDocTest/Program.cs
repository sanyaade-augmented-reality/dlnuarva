using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;

using SWDataModel;

namespace ASMDocTest {
    class Program {
        public static SldWorks swApp;

        static void Main(string[] args) {
            swApp = new SldWorks();
            //GetMates();
            //ExtractOrigin();
            //Program2.Run();
            ExtractTree();
        }

        /// <summary>
        /// 遍历组件的配合
        /// </summary>
        public static void GetMates() {
            ModelDoc2 swModel;
            Component2 swComponent;
            AssemblyDoc swAssembly;
            object[] Components = null;
            object[] Mates = null;
            Mate2 swMate;
            MateInPlace swMateInPlace;
            int numMateEntities = 0;
            int typeOfMate = 0;
            int i = 0;

            swModel = (ModelDoc2)swApp.ActiveDoc;
            swAssembly = (AssemblyDoc)swModel;
            Components = (Object[])swAssembly.GetComponents(false);

            foreach (Object SingleComponent in Components) {
                swComponent = (Component2)SingleComponent;
                Debug.Print("Name of component: " + swComponent.Name2);
                Mates = (Object[])swComponent.GetMates();

                if ((Mates != null)) {
                    foreach (Object SingleMate in Mates) {
                        if (SingleMate is SolidWorks.Interop.sldworks.Mate2) {
                            swMate = (Mate2)SingleMate;
                            typeOfMate = swMate.Type;
                            OutPutMateType(typeOfMate);
                        }  
                        
                        if (SingleMate is SolidWorks.Interop.sldworks.MateInPlace) {
                            swMateInPlace = (MateInPlace)SingleMate;
                            numMateEntities = swMateInPlace.GetMateEntityCount();

                            for (i = 0; i <= numMateEntities - 1; i++) {
                                Debug.Print(" Mate component name: " + swMateInPlace.get_MateComponentName(i));
                                Debug.Print(" Type of mate inplace: " + swMateInPlace.get_MateEntityType(i));
                            }

                            Debug.Print("");
                        }
                    }
                }
                Debug.Print("");
            }
        }

        /// <summary>
        /// 提取原点
        /// </summary>
        public static void ExtractOrigin() {
            ModelDoc2 swModel;
            Component2 rootComponent;
            object[] subComponents = null;
            //AssemblyDoc swAssembly;
            //object[] Components = null;
            List<Feature> features = null ;

            swModel = (ModelDoc2)swApp.ActiveDoc;
            rootComponent = swModel.ConfigurationManager.ActiveConfiguration.GetRootComponent3(true);
            subComponents = rootComponent.GetChildren();
            
            features = GetFeaturesOfComponent(rootComponent);

            Debug.Print(rootComponent.Name2);
            foreach (Feature feature in features) {
                Debug.Print(feature.Name + ": " + feature.GetTypeName2());
                if (feature.GetTypeName2() == "OriginProfileFeature") {
                    feature.GetSpecificFeature2();
                }
            } 
        }

        /// <summary>
        /// 提取装备文件拓扑结构
        /// </summary>
        public static void ExtractTree() {
            ModelDoc2 swModel = default(ModelDoc2);
            Component2 rootComponent = default(Component2);
            SWComponent newComponent = default(SWComponent);

            swModel = swApp.ActiveDoc;
            rootComponent = swModel.ConfigurationManager.ActiveConfiguration.GetRootComponent3(true);
            newComponent = new SWComponent();

            CreateTree(rootComponent, ref newComponent);

            Debug.Print("");
        }

        /// <summary>
        /// 获取组件的特征
        /// </summary>
        public static List<Feature> GetFeaturesOfComponent(Component2 component) {
            if (component == null)  {
                return null;
            }

            List<Feature> features = new List<Feature>();
            Feature feature = null;
            ModelDoc2 doc = component.GetModelDoc2();

            feature = doc.FirstFeature();

            while (feature != null) {
                features.Add(feature);
                feature = feature.GetNextFeature();
            }

            return features;
        }

        /// <summary>
        /// 递归创建装配树
        /// </summary>
        /// <param name="component"></param>
        /// <param name="swComponet"></param>
        private static void CreateTree(Component2 component, ref SWComponent swComponent) {
            if (component == null) {
                return;
            }

            //复制组件相关信息

            //名称
            swComponent.Name = component.Name2;
            //是否根组件
            swComponent.IsRoot = component.IsRoot();
            //包围盒
            double[] box = null;
            try {
                box = component.GetBox(false, false);
            } catch (Exception e) {
                //发生异常，说明该组件（根组件）没有包围盒
                box = null;
            }

            if (box != null) {
                //乘以1000转换到mm进制
                swComponent.BoundingBox = new SWBoundingBox() {
                    LowerCorner = new SWPoint() {
                        X = box[0] * 1000,
                        Y = box[1] * 1000,
                        Z = box[2] * 1000
                    },
                    UpperCorner = new SWPoint() {
                        X = box[3] * 1000,
                        Y = box[4] * 1000,
                        Z = box[5] * 1000
                    }
                };
            }

            object bodyInfo;
            object[] bodies = component.GetBodies3((int)swBodyType_e.swSolidBody, out bodyInfo);
            if (bodies != null) {
                foreach (object obj in bodies) {
                    Body2 body = (Body2)obj;
                    int faceCount = body.GetFaceCount();
                    Face2 face = body.GetFirstFace();

                    while (face != null) {

                        OutPutSurfaceType(face.GetSurface());

                        face = face.GetNextFace();
                    }
                }
            }
            
            //继续遍历
            object[] subComponents = component.GetChildren();

            foreach (object obj in subComponents) {
                SWComponent newComponent = new SWComponent();
                CreateTree((Component2)obj, ref newComponent);
                swComponent.SubComponents.Add(newComponent); 
            }
        }

        /// <summary>
        ///  输出配合类型
        /// </summary>
        /// <param name="typeOfMate"></param>
        public static void OutPutMateType(int typeOfMate) {
            switch (typeOfMate) {
                case 0:
                    Debug.Print(" Mate type: Coincident");
                    break;
                case 1:
                    Debug.Print(" Mate type: Concentric");
                    break;
                case 2:
                    Debug.Print(" Mate type: Perpendicular");
                    break;
                case 3:
                    Debug.Print(" Mate type: Parallel");
                    break;
                case 4:
                    Debug.Print(" Mate type: Tangent");
                    break;
                case 5:
                    Debug.Print(" Mate type: Distance");
                    break;
                case 6:
                    Debug.Print(" Mate type: Angle");
                    break;
                case 7:
                    Debug.Print(" Mate type: Unknown");
                    break;
                case 8:
                    Debug.Print(" Mate type: Symmetric");
                    break;
                case 9:
                    Debug.Print(" Mate type: CAM follower");
                    break;
                case 10:
                    Debug.Print(" Mate type: Gear");
                    break;
                case 11:
                    Debug.Print(" Mate type: Width");
                    break;
                case 12:
                    Debug.Print(" Mate type: Lock to sketch");
                    break;
                case 13:
                    Debug.Print(" Mate type: Rack pinion");
                    break;
                case 14:
                    Debug.Print(" Mate type: Max mates");
                    break;
                case 15:
                    Debug.Print(" Mate type: Path");
                    break;
                case 16:
                    Debug.Print(" Mate type: Lock");
                    break;
                case 17:
                    Debug.Print(" Mate type: Screw");
                    break;
                case 18:
                    Debug.Print(" Mate type: Linear coupler");
                    break;
                case 19:
                    Debug.Print(" Mate type: Universal joint");
                    break;
                case 20:
                    Debug.Print(" Mate type: Coordinate");
                    break;
                case 21:
                    Debug.Print(" Mate type: Slot");
                    break;
                case 22:
                    Debug.Print(" Mate type: Hinge");
                    break;
                // Add new mate types introduced after SolidWorks 2010 FCS here
            }
        }

        /// <summary>
        /// 输出基础面类型
        /// </summary>
        /// <param name="typeOfSurface"></param>
        public static void OutPutSurfaceType(Surface surface) {
            if (surface == null) {
                return;
            }

            switch (surface.Identity()) {
                case (int)swSurfaceTypes_e.PLANE_TYPE:
                    Debug.Print("平面:");
                    Debug.Print("\t中心点：[" + (double)surface.PlaneParams[0] + "," + (double)surface.PlaneParams[1] + "," +
                        (double)surface.PlaneParams[2] + "]");
                    Debug.Print("\t法向量:[" + (double)surface.PlaneParams[3] + "," + (double)surface.PlaneParams[4] + "," +
                        (double)surface.PlaneParams[5] + "]");
                    break;
                case (int)swSurfaceTypes_e.SPHERE_TYPE:
                    Debug.Print("球面:");
                    Debug.Print("\t圆心:[" + (double)surface.SphereParams[0] + "," + (double)surface.SphereParams[1] + "," +
                        (double)surface.SphereParams[2] + "]");
                    Debug.Print("\t半径:[" + (double)surface.SphereParams[3] + "]");
                    break;
                case (int)swSurfaceTypes_e.CYLINDER_TYPE:
                    Debug.Print("圆柱面:");
                    Debug.Print("\t中心点:[" + (double)surface.CylinderParams[0] + "," + (double)surface.CylinderParams[1] + "," +
                        (double)surface.CylinderParams[2] + "]");
                    Debug.Print("\t旋转:[" + (double)surface.CylinderParams[3] + "," + (double)surface.CylinderParams[4] + "," +
                        (double)surface.CylinderParams[5] + "]");
                    Debug.Print("\t半径:[" + (double)surface.CylinderParams[6] + "]");
                    break;
                case (int)swSurfaceTypes_e.CONE_TYPE:
                    Debug.Print("圆锥面:");
                    Debug.Print("\t中心点:[" + (double)surface.ConeParams[0] + "," + (double)surface.ConeParams[1] + "," +
                        (double)surface.ConeParams[2] + "]");
                    Debug.Print("\t旋转:[" + (double)surface.ConeParams[3] + "," + (double)surface.ConeParams[4] + "," +
                        (double)surface.ConeParams[5] + "]");
                    Debug.Print("\t半径:[" + (double)surface.ConeParams[6] + "]");
                    Debug.Print("\t半角弧度:[" + (double)surface.ConeParams[7] + "]");
                    break;
                case (int)swSurfaceTypes_e.TORUS_TYPE:
                    Debug.Print("圆环面:");
                    Debug.Print("\t中心点:[" + (double)surface.TorusParams[0] + "," + (double)surface.TorusParams[1] + "," +
                        (double)surface.TorusParams[2] + "]");
                    Debug.Print("\t旋转:[" + (double)surface.TorusParams[3] + "," + (double)surface.TorusParams[4] + "," +
                        (double)surface.TorusParams[5] + "]");
                    Debug.Print("\t大圆半径:[" + (double)surface.TorusParams[6] + "]");
                    Debug.Print("\t小圆半径:[" + (double)surface.TorusParams[7] + "]");
                    break;
                case (int)swSurfaceTypes_e.SREV_TYPE:
                    Debug.Print("旋转曲面:");
                    break;
                case (int)swSurfaceTypes_e.BLEND_TYPE:
                    Debug.Print("混合曲面:");
                    break;
                case (int)swSurfaceTypes_e.BSURF_TYPE:
                    Debug.Print("平滑曲面:");
                    break;
                case (int)swSurfaceTypes_e.EXTRU_TYPE:
                    Debug.Print("挤压曲面:");
                    break;
                case (int)swSurfaceTypes_e.OFFSET_TYPE:
                    Debug.Print("偏移曲面:");
                    break;  
            }
        }
    }
}
