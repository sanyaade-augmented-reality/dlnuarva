using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;

namespace ASMDocTest {

    class Program2 {
        public static void Run() {
            int errors = 0, warnings = 0;
            SldWorks swApp = new SldWorks();
            SolidWorksMacro works = new SolidWorksMacro();
            works.swApp = swApp;

            /*
            works.swApp.OpenDoc6(
                "C:\\Users\\dongye\\Desktop\\装配体2.SLDASM",
                (int)swDocumentTypes_e.swDocASSEMBLY,
                (int)swOpenDocOptions_e.swOpenDocOptions_Silent,
                "Default",
                ref errors,
                ref warnings
            );
            */

            works.Run();
            Console.ReadKey();
        }
    }

    class SolidWorksMacro {
        /* public void TraverseFeatures2(Feature swFeat, long nLevel)
         {
             if (swFeat == null)
             {
                 return;
             }

             Feature swSubFeat;
             string sPadStr = "";
             long i = 0;

             for (i = 0; i <= nLevel; i++)
             {
                 sPadStr = sPadStr + "\t";
             }

             // To extract mate infomation.
             if (swFeat.GetTypeName2().IndexOf("Mate") != -1 && swFeat.GetTypeName2() != "MateGroup")
             {
                 Debug.Print("[------------MateInfo:" + swFeat.Name + "[" + swFeat.GetTypeName2() + "]------------]");
                 Mate2 swMate = swFeat.GetSpecificFeature2();
                 if (swMate != null)
                 {
                     Debug.Print("Aligment:" + swMate.Alignment);
                     Debug.Print("CanBeFlipped:" + swMate.CanBeFlipped);
                     Debug.Print("Type:" + swMate.Type);
                     Debug.Print("MaximumVariation:" + swMate.MaximumVariation);
                     Debug.Print("MinimumVariation:" + swMate.MinimumVariation);
                     //以上是配合的一些参数，下面获取配合的实体

                     Debug.Print("Entities:");
                     //To output entities.
                     int mateEntityCount = 0;
                     MateEntity2[] entities = null;
                     mateEntityCount = swMate.GetMateEntityCount();//配合实体数量
                     Face2[] supplementalFaces = null;
                     entities = new MateEntity2[mateEntityCount];
                     for (int j = 0; j < mateEntityCount; ++j)
                     {
                         entities[j] = swMate.MateEntity(j);//得到配合的第j个实体
                         Debug.Print("\tEntity[" + j + "] Name:" + entities[j].ReferenceComponent.Name2);//实体部件名
                         Debug.Print("\t\tEntity Params Size:" + entities[j].GetEntityParamsSize());//实体参数个数
                         Debug.Print("\t\tLocation[x, y, z]:" + (double)entities[j].EntityParams[0] + ","
                             + (double)entities[j].EntityParams[1] + "," + (double)entities[j].EntityParams[2]);
                         Debug.Print("\t\tV1,V2,V3:" + (double)entities[j].EntityParams[3] + ","
                             + (double)entities[j].EntityParams[4] + "," + (double)entities[j].EntityParams[5]);
                         Debug.Print("\t\tR1,R2:" + (double)entities[j].EntityParams[6] + ","
                             + (double)entities[j].EntityParams[7]);//配合的位置，向量和角度。
                         supplementalFaces = (Face2[])swMate.GetSupplementalFaces(j);
                     }
                 }
             }

             Debug.Print(sPadStr + swFeat.Name + " [" + swFeat.GetTypeName2() + "]");
             if ((swSubFeat = swFeat.IGetFirstSubFeature()) != null)
             {
                 TraverseFeatures2(swSubFeat, nLevel + 1);
             }

             if (nLevel == 1)
             {
                 if ((swFeat = swFeat.IGetNextFeature()) != null)
                 {
                     TraverseFeatures2(swFeat, nLevel);
                 }
             }
             else
             {
                 if ((swFeat = swFeat.GetNextSubFeature()) != null)
                 {
                     TraverseFeatures2(swFeat, nLevel);
                 }
             }

         }

         //提取面片的顶点坐标和法向量
         public void TraverseFeatures3(Feature swFeat, long nLevel)
         {
             if (swFeat == null) return;

             Feature swSubFeat;
             string sPadStr = "";
             long i = 0;
             int iFeatFaceNum = 0;
             Face2 swFeatFace;

             for (i = 0; i < nLevel; i++)
             {
                 sPadStr += "\t";
             }
             Debug.Print(sPadStr + swFeat.Name + " [" + swFeat.GetTypeName2() + "]");

             if (swFeat.GetTypeName2() == "MateGroup")
             {
                 swSubFeat = swFeat.GetFirstSubFeature();
                 while (swSubFeat != null)
                 {
                     int j = 0;
                     IMate2 mate2 = swSubFeat.GetSpecificFeature2();
                     MateEntity2 entity = mate2.MateEntity(j);

                     object[] objectface = (object[])mate2.GetSupplementalFaces(j);
                     // Debug.Print("  " + objectface.Length);
                     double[] entityParams = entity.EntityParams;
                     //Component2 component = entity.ReferenceComponent;
                    // Debug.Print("1 " + component.Name2);
                     j++;
                     entity = mate2.MateEntity(j);
                     entityParams = entity.EntityParams;
                     //component = entity.ReferenceComponent;
                    // Debug.Print(" 2 " + component.Name2);
                     swSubFeat = swSubFeat.GetNextSubFeature();
                 }
             }

             StreamWriter sw = File.AppendText("E:\\myText.txt");
             //获取与特征有关的几何面
             iFeatFaceNum = swFeat.GetFaceCount();
             object[] faceobject = (object[])swFeat.GetFaces();
             if (faceobject != null)
             {
                 for (i = 0; i < iFeatFaceNum; i++)
                 {

                     swFeatFace = (Face2)faceobject[i];

                     //通过几何面获取三角面片
                     float[] trianglesobject = swFeatFace.GetTessNorms();//获取每个三角形面片的法向量
                     float[] triangle = swFeatFace.GetTessTriangles(true);
                     for (int j = 0; j < (trianglesobject.Length) / 9; j++)
                     {
                         // Debug.Print("\t 三角面顶点坐标1 x,y,z=" + triangle[3 * j] + triangle[3 * j + 1] + triangle[3 * j + 2] + "\n");
                         // Debug.Print("\t 三角面顶点坐标2 x,y,z=" + triangle[3 * (j + 1)] + triangle[3 * (j + 1) + 1] + triangle[3 * (j + 1) + 2] + "\n");
                         //Debug.Print("\t 三角面顶点坐标3 x,y,z=" + trianglesobject[3 * (j + 2)] + trianglesobject[3 * (j + 2) + 1] + trianglesobject[3 * (j + 2) + 2] + "\n");
                         Debug.Print("\t 三角面法相量 x,y,z=" + trianglesobject[3 * j] + trianglesobject[3 * j + 1] + trianglesobject[3 * j + 2] + "\n");
                         sw.WriteLine(triangle[3 * j] + "," + triangle[3 * j + 1] + "," + triangle[3 * j + 2] + ",");
                         sw.WriteLine(triangle[3 * (j + 1)] + "," + triangle[3 * (j + 1) + 1] + "," + triangle[3 * (j + 1) + 2] + ",");
                         sw.WriteLine(triangle[3 * (j + 2)] + "," + triangle[3 * (j + 2) + 1] + "," + triangle[3 * (j + 2) + 2] + ";");
                         sw.Flush();
                     }
                 }
             }
             sw.Close();


             if ((swSubFeat = swFeat.IGetFirstSubFeature()) != null)
             {
                 TraverseFeatures3(swSubFeat, nLevel + 1);
             }

             if (nLevel == 1)
             {
                 if ((swFeat = swFeat.IGetNextFeature()) != null)
                 {
                     TraverseFeatures3(swFeat, nLevel);
                 }
             }
             else
             {
                 if ((swFeat = swFeat.GetNextSubFeature()) != null)
                 {
                     TraverseFeatures3(swFeat, nLevel);
                 }
             }
             //  swFeat = swFeat.IGetNextFeature();
             // TraverseFeatures3(swFeat, nLevel);

         }


         public void TraverseFeatures(Feature swFeat, long nLevel)
         {
             Feature swSubFeat;
             string sPadStr = "";
             long i = 0;

             for (i = 0; i <= nLevel; i++)
             {
                 sPadStr = sPadStr + "\t";
             }

             while ((swFeat != null))
             {
                 Debug.Print(sPadStr + swFeat.Name + " [" + swFeat.GetTypeName2() + "]");
                 swSubFeat = (Feature)swFeat.GetFirstSubFeature();

                 if ((swSubFeat != null))
                 {
                     TraverseFeatures(swSubFeat, nLevel + 1);
                 }

                 if (nLevel == 1)
                 {
                     swFeat = (Feature)swFeat.GetNextFeature();
                 }
                 else
                 {
                     swFeat = (Feature)swFeat.GetNextSubFeature();
                 }
             }
         }

         public void TraverseComponentFeatures(Component2 swComp, long nLevel)
         {
             Feature swFeat;
             swFeat = (Feature)swComp.FirstFeature();
             //TraverseFeatures(swFeat, nLevel);
             // TraverseFeatures2(swFeat, nLevel);
             TraverseFeatures3(swFeat, nLevel);
         }
         */

        /*public void WriteInto(string filename, object content)
        {
            StreamWriter streamw = File.AppendText(filename);//已追加的方式写文件
            streamw.Write(" )");
            streamw.Flush();
            streamw.Close();
        }*/

        public void TraverseBody(Component2 swComp) {
            StreamWriter streamw = File.AppendText("E:\\body.txt");//已追加的方式写文件

            object[] vBodies;
            object vBodyInfo;
            int[] BodiesInfo = null;
            int j;
            Body2 swBody;
            int BodyType = 0;

            // Get the solid bodies in the component 
            //这里的getBodies3只能取得零件的body
            vBodies = (object[])swComp.GetBodies3((int)swBodyType_e.swSolidBody, out  vBodyInfo);
            // vBodies = (object[])swComp.GetBodies2((int)swBodyType_e.swSolidBody);

            BodiesInfo = (int[])vBodyInfo;
            if (vBodies == null) {
                streamw.Flush();
                streamw.Close();
                return;
            }

            Debug.Print(" Number of solid bodies: " + vBodies.Length);
            streamw.WriteLine(swComp.Name2 + "  " + vBodies.Length);


            for (j = 0; j < vBodies.Length; j++) {
                Debug.Print(" Body number: " + (j + 1));
                swBody = (Body2)vBodies[j];
                Debug.Print(" Body name: " + swBody.Name);

                /*  /////////////////////////////////////////////////////////
                  object[] vedge = (object[])swBody.GetEdges();
                  for (int i = 0; i < vedge.Length; i++ )
                  {
                      Edge swedge  = (Edge)vedge[i];
                      //显示边界。
                      swedge.Display(2, 1.0, 0.0, 0.0, true);
                  }
                  ////////////////////////////////////////////////////////////*/

                streamw.WriteLine("# the " + (j + 1) + "  body \n");
                streamw.Flush();
                streamw.Close();

                //输出bodyface
                getFaceTriangle(swBody);

                streamw = File.AppendText("E:\\body.txt");//已追加的方式写文件

                // Print the type of body 

                BodyType = (int)BodiesInfo[j];

                switch (BodyType) {
                    case 0:
                        Debug.Print(" Body type: user");
                        break;
                    case 1:
                        Debug.Print(" Body type: normal");
                        break;
                }
            }

            streamw.Flush();
            streamw.Close();
        }

        /// <summary>
        /// 得到三角形面片的信息
        /// </summary>
        /// <param name="swBody"></param>
        public void getFaceTriangle(Body2 swBody) {
            StreamWriter streamw = File.AppendText("E:\\body.txt");//已追加的方式写文件
            //输出bodyface
            int iFaceCount = swBody.GetFaceCount();
            Debug.Print(" facecount: " + iFaceCount);
            object[] vobjectface = swBody.GetFaces();
            int i;
            Face2 face;

            for (i = 0; i < vobjectface.Length; i++) {

                face = (Face2)vobjectface[i];
                int k = face.GetFaceId();
                streamw.WriteLine("the  " + (i + 1) + "  bodyface");
                float[] TriangleSobject = face.GetTessNorms();//获取每个三角形面片的法向量
                float[] TrianglePoint = face.GetTessTriangles(false);//获得三角面片的顶点
                for (int j = 0; j < TrianglePoint.Length / 3; j++) {
                    streamw.WriteLine(TrianglePoint[j * 3] + " " + TrianglePoint[j * 3 + 1] + " " + TrianglePoint[j * 3 + 2]
                    + "\\" + TriangleSobject[j * 3] + " " + TriangleSobject[j * 3 + 1] + " " + TriangleSobject[j * 3 + 2]);
                }

            }
            streamw.Flush();
            streamw.Close();
        }

        /// <summary>
        /// 若是零件调用该函数，则输出特征，当遇到mategroup时调用GetMateEntity;
        /// 若是配件则输出配件的特征，当遇到mategroup时调用GetMateEntity;
        /// </summary>
        /// <param name="swFeat"></param>
        /// <param name="nLevel"></param>
        public void TraverseFeature(Feature swFeat, long nLevel) {
            Feature subFeat = swFeat;
            string sPadStr = "";
            int i;
            Feature firstsubFeat;

            for (i = 0; i <= nLevel; i++) {
                sPadStr = sPadStr + "\t";
            }

            while (subFeat != null) {
                Debug.Print(sPadStr + subFeat.Name + " [" + subFeat.GetTypeName2() + "]");
                //获取配合对象
                if (subFeat.Name == "Tutor2-1" || subFeat.Name == "Tutor1-1") {
                    MateReference swMateReference = default(MateReference);
                    swMateReference = subFeat.GetSpecificFeature2();
                    Debug.Print(swMateReference.Name);
                }

                if (subFeat.GetTypeName2() == "MateGroup") {
                    List<MateEntity2> entity = GetMateEntity(subFeat, nLevel + 1);
                }

                firstsubFeat = swFeat.GetFirstSubFeature();
                //判断是为零件还是装配体
                if (firstsubFeat != null) {
                    TraverseFeature(firstsubFeat, nLevel + 1);
                } else {
                    subFeat = subFeat.GetNextFeature();
                }
            }
        }

        /// <summary>
        /// 得到mategroup下得所有的配合的entity
        /// </summary>
        /// <param name="swFeat"></param>
        /// <param name="nLevel"></param>
        /// <returns></returns> 
        public List<MateEntity2> GetMateEntity(Feature swFeat, long nLevel) {
            MateReference swMateReference = default(MateReference);
            Feature subFeat = swFeat.GetFirstSubFeature();
            List<MateEntity2> entity = new List<MateEntity2>();

            while (subFeat != null) {
                // Mate2 swMate = (Mate2)subFeat.GetSpecificFeature2();

                /*配合类型
                switch (swMate.Type)
                {
                    case (int)swMateType_e.swMateCOINCIDENT:
                        entity = MateCOINCIDENT(swMate);
                        break;
                    case (int)swMateType_e.swMateCONCENTRIC:
                        entity = MateCONCENTRIC(swMate);
                        break;
                    case (int)swMateType_e.swMatePERPENDICULAR:
                        entity = MatePERPENDICULAR(swMate);
                        break;
                }*/

                //swMateReference = (MateReference)subFeat.GetSpecificFeature2();
                swMateReference = subFeat.GetSpecificFeature2();
                Debug.Print(swMateReference.Name);
                swMateReference.get_ReferenceType(0);
                subFeat = subFeat.GetNextSubFeature();
            }

            return entity;
        }

        /// <summary>
        /// 配合类型为重合
        /// </summary>
        /// <param name="swMate"></param>
        /// <returns></returns>
        List<MateEntity2> MateCOINCIDENT(Mate2 swMate) {
            List<MateEntity2> entity = new List<MateEntity2>();
            int EntityCount = swMate.GetMateEntityCount();
            MateEntity2 swMateEntity;
            int i;

            Debug.Print("  mateType : 重合 \n");

            for (i = 0; i < EntityCount; i++) {
                swMateEntity = swMate.MateEntity(i);
                entity.Add(swMate.MateEntity(i));
                Component2 swComp = swMateEntity.ReferenceComponent;

                switch (swMateEntity.ReferenceType2) {
                    case (int)swSelectType_e.swSelEDGES:
                        GetMateEdgesFromComp(swComp, swMateEntity);
                        break;
                    case (int)swSelectType_e.swSelFACES:
                        GetMateFacesFromComp(swComp, swMateEntity);
                        break;
                    case (int)swSelectType_e.swSelVERTICES:
                        GetMateVerticesFromComp(swComp, swMateEntity);
                        break;
                }

            }

            return entity;
        }
        /// <summary>
        /// 配合类型为同心
        /// </summary>
        /// <param name="swMate"></param>
        /// <returns></returns>
        List<MateEntity2> MateCONCENTRIC(Mate2 swMate) {
            List<MateEntity2> entity = new List<MateEntity2>();
            int EntityCount = swMate.GetMateEntityCount();
            MateEntity2 swMateEntity;
            int i;

            Debug.Print("  mateType : 同心 \n");

            for (i = 0; i < EntityCount; i++) {
                swMateEntity = swMate.MateEntity(i);
                entity.Add(swMate.MateEntity(i));
                Component2 swComp = swMateEntity.ReferenceComponent;

                switch (swMateEntity.ReferenceType2) {
                    case (int)swSelectType_e.swSelEDGES:
                        GetMateEdgesFromComp(swComp, swMateEntity);
                        break;
                    case (int)swSelectType_e.swSelFACES:
                        GetMateFacesFromComp(swComp, swMateEntity);
                        break;
                    case (int)swSelectType_e.swSelVERTICES:
                        GetMateVerticesFromComp(swComp, swMateEntity);
                        break;
                }

            }

            return entity;
        }
        /// <summary>
        /// 配合类型为垂直
        /// </summary>
        /// <param name="swMate"></param>
        /// <returns></returns>
        List<MateEntity2> MatePERPENDICULAR(Mate2 swMate) {
            List<MateEntity2> entity = new List<MateEntity2>();
            int EntityCount = swMate.GetMateEntityCount();
            int i;

            Debug.Print("  mateType : 垂直 \n");

            for (i = 0; i < EntityCount; i++) {
                entity.Add(swMate.MateEntity(i));
            }
            return entity;
        }

        /// <summary>
        /// 得到配合下的实体的边界（edges）
        /// </summary>
        void GetMateEdgesFromComp(Component2 swComp, MateEntity2 swMateEntity) {
            Debug.Print("   edges ");
            Body2 swBody;
            object[] vBodies;
            object vBodyInfo;
            double[] retMateEntity = swMateEntity.EntityParams;
            int j;
            int no = swMateEntity.GetEntityParamsSize();

            //得到body
            vBodies = (object[])swComp.GetBodies3((int)swBodyType_e.swSolidBody, out  vBodyInfo);
            if (vBodies == null) {//如果vBodies不存在
                return;
            }
            for (j = 0; j < vBodies.Length; j++) {
                swBody = (Body2)vBodies[j];
                /////////////////////////////////////////////////////////
                object[] vedge = (object[])swBody.GetEdges();
                for (int i = 0; i < vedge.Length; i++) {
                    Edge swedge = (Edge)vedge[i];
                    swedge.Display(2, 1.0, 0.0, 0.0, true);
                    //swedge.Highlight(true);
                    Vertex swVer = swedge.GetStartVertex();
                    if (swVer == null) {//如果是圆
                        continue;
                    }
                    double[] point = swVer.GetPoint();
                    // swedge.Highlight(false);
                    //显示边界。
                    // swedge.Display(2, 1.0, 0.0, 0.0, true);
                }
                /////////////////////////////////////////////////////////////

                //输出bodyface
                // getFaceTriangle(swBody);

            }

        }

        /// <summary>
        /// 得到配合下的实体的面（faces）
        /// </summary>
        void GetMateFacesFromComp(Component2 swComp, MateEntity2 swMateEntity) {
            Debug.Print("   faces ");
        }

        /// <summary>
        /// 得到配合下的实体的面（faces）
        /// </summary>
        void GetMateVerticesFromComp(Component2 swComp, MateEntity2 swMateEntity) {
            Debug.Print("   vertices ");

            Body2 swBody;
            object[] vBodies;
            object vBodyInfo;
            double[] retMateEntity = swMateEntity.EntityParams;
            int j;
            Vertex swver;

            vBodies = (object[])swComp.GetBodies3((int)swBodyType_e.swSolidBody, out  vBodyInfo);
            if (vBodies == null) {//如果vBodies不存在
                return;
            }
            for (j = 0; j < vBodies.Length; j++) {
                swBody = (Body2)vBodies[j];
                object[] vVertex = (object[])swBody.GetVertices();

                for (int i = 0; i < vVertex.Length; i++) {
                    swver = (Vertex)vVertex[j];
                    double[] point = swver.GetPoint();
                    if (point[0] == retMateEntity[0] &&
                        point[1] == retMateEntity[1] &&
                        point[2] == retMateEntity[2]) {
                        Debug.Print("find point!");
                    }
                }
            }
        }

        /// <summary>
        /// 得到entity的参数
        /// </summary>
        /// <param name="swComp"></param>
        /// <param name="nLevel"></param>
        public void EntityParament(MateEntity2 entity) {
            double[] Parament = entity.EntityParams;
            Component2 swComp = entity.ReferenceComponent;
            //Component2 swComp = entity.GetComponent();
            string CompName = swComp.Name2;

            object ventity = swComp.GetCorrespondingEntity(entity);//得到装配体里entity的指针
            Entity swentity;
            Face2 swface = (Face2)ventity;
            float[] TriangleSobject = swface.GetTessNorms();//获取每个三角形面片的法向量
            float[] TrianglePoint = swface.GetTessTriangles(false);//获得三角面片的顶点

        }

        public void TraverseComponent(Component2 swComp, long nLevel) {
            StreamWriter streamw = File.AppendText("E:\\Component.txt");//已追加的方式写文件

            object[] vChildComp;
            Component2 swChildComp;
            ModelDoc2 swModelDoc;
            //  Feature swFeature;

            string sPadStr = "";//输出格式
            long i = 0;

            for (i = 0; i < nLevel; i++) {
                sPadStr = sPadStr + "\t";
            }
            Debug.Print(sPadStr + "+" + swComp.Name2 + " <" + swComp.ReferencedConfiguration + ">");

            streamw.Write(swComp.Name2 + "( ");

            //对配件获取特征
            swModelDoc = (ModelDoc2)swComp.GetModelDoc2();//只能取装配体的第一个特征。
            TraverseModelFeatures(swModelDoc, nLevel + 1);
            //  swFeature = swComp.FirstFeature();
            //  TraverseFeature(swFeature, nLevel + 1);

            vChildComp = (object[])swComp.GetChildren();

            for (i = 0; i < vChildComp.Length; i++) {
                object[] vswChildComp;
                swChildComp = (Component2)vChildComp[i];
                vswChildComp = (object[])swChildComp.GetChildren();

                //如果是零件则获取body
                if (vswChildComp.Length == 0) {
                    Debug.Print(sPadStr + "\t+" + swChildComp.Name2 + " <" + swChildComp.ReferencedConfiguration + ">");
                    streamw.Write(swChildComp.Name2 + " ");

                    //对零件获取特征
                    swModelDoc = null;
                    swModelDoc = (ModelDoc2)swChildComp.GetModelDoc2();//只能取装配体的第一个特征。
                    TraverseModelFeatures(swModelDoc, nLevel + 1);
                    // swFeature = null;
                    // swFeature = swChildComp.FirstFeature();
                    // TraverseFeature(swFeature, nLevel + 1);
                    TraverseBody(swChildComp);
                } else {
                    streamw.Flush();
                    streamw.Close();

                    TraverseComponent(swChildComp, nLevel + 1);

                    streamw = File.AppendText("E:\\Component.txt");//已追加的方式写文件
                    streamw.Write(") ");
                }

            }

            streamw.Flush();
            streamw.Close();
        }

        /// <summary>
        /// 通过后文件来遍历特征
        /// </summary>
        /// <param name="swModel"></param>
        /// <param name="nLevel"></param>
        public void TraverseModelFeatures(ModelDoc2 swModel, long nLevel) {
            Feature swFeat;
            swFeat = (Feature)swModel.FirstFeature();
            //TraverseFeatures(swFeat, nLevel);
            //TraverseFeatures2(swFeat, nLevel);
            Debug.Print("File = " + swModel.GetPathName());
            TraverseFeature(swFeat, nLevel);
        }

        public void Run() {
            ModelDoc2 swModel;
            ConfigurationManager swConfMgr;
            Configuration swConf;
            Component2 swRootComp;

            //获取rootcomponent
            swModel = (ModelDoc2)swApp.ActiveDoc;
            swConfMgr = (ConfigurationManager)swModel.ConfigurationManager;
            swConf = (Configuration)swConfMgr.ActiveConfiguration;
            swRootComp = (Component2)swConf.GetRootComponent3(true);

            //计算运行时间
            System.Diagnostics.Stopwatch myStopwatch = new Stopwatch();
            myStopwatch.Start();
            //输出文件名
            Debug.Print("File = " + swModel.GetPathName());

            //判断是否为assembly是则遍历conponent
            if (swModel.GetType() == (int)swDocumentTypes_e.swDocASSEMBLY) {
                TraverseComponent(swRootComp, 1);

                StreamWriter streamw = File.AppendText("E:\\Component.txt");//已追加的方式写文件
                streamw.Write(");");
                streamw.Flush();
                streamw.Close();

            }


            myStopwatch.Stop();
            TimeSpan myTimespan = myStopwatch.Elapsed;
            Debug.Print("Time = " + myTimespan.TotalSeconds + " sec");
        }

        /// <summary> 
        /// The SldWorks swApp variable is pre-assigned for you. 
        /// </summary> 
        public SldWorks swApp;
    }

}

