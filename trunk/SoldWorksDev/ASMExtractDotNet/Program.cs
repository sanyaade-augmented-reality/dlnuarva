using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

using SldWorks;
using SwConst;

namespace ASMExtractDotNet {
    class Program {
        public static void Main() {
            //int errors = 0, warnings = 0;
            SldWorks.SldWorks swApp = new SldWorks.SldWorks();
            SolidWorksMacro works = new SolidWorksMacro();
            works.swApp = swApp;
            /*
            works.swApp.OpenDoc6(
                "D:\\Program Files\\SolidWorks Corp\\SolidWorks\\samples\\tutorial\\PDMWorks",
                (int)swDocumentTypes_e.swDocASSEMBLY,
                (int)swOpenDocOptions_e.swOpenDocOptions_Silent,
                "Default",
                ref errors,
                ref warnings
            );
             * */
            works.Run();
            Console.ReadKey();
        }
    }

    class SolidWorksMacro {
        public void TraverseFeatures2(Feature swFeat, long nLevel) {
            if (swFeat == null) {
                return;
            }
            
            Feature swSubFeat;
            string sPadStr = "";
            long i = 0;

            for (i = 0; i <= nLevel; i++) {
                sPadStr = sPadStr + "\t";
            }

            // To extract mate infomation.
            if (swFeat.GetTypeName2().IndexOf("Mate") != -1 && swFeat.GetTypeName2() != "MateGroup") {
                Debug.Print("[------------MateInfo:" + swFeat.Name + "[" + swFeat.GetTypeName2() + "]------------]");
                Mate2 swMate = swFeat.GetSpecificFeature2();
                if (swMate != null) {
                    Debug.Print("Aligment:" + swMate.Alignment);
                    Debug.Print("CanBeFlipped:" + swMate.CanBeFlipped);
                    Debug.Print("Type:" + swMate.Type);
                    Debug.Print("MaximumVariation:" + swMate.MaximumVariation);
                    Debug.Print("MinimumVariation:" + swMate.MinimumVariation);

                    Debug.Print("Entities:");
                    //To output entities.
                    int mateEntityCount = 0;
                    MateEntity2[] entities = null;
                    mateEntityCount = swMate.GetMateEntityCount();
                    Face2[] supplementalFaces = null;
                    entities = new MateEntity2[mateEntityCount];
                    for (int j = 0; j < mateEntityCount; ++j) {
                        entities[j] = swMate.MateEntity(j);
                        Debug.Print("\tEntity[" + j + "] Name:" + entities[j].ReferenceComponent.Name2);
                        Debug.Print("\t\tEntity Params Size:" + entities[j].GetEntityParamsSize());
                        Debug.Print("\t\tLocation[x, y, z]:" + (double)entities[j].EntityParams[0] + ","
                            + (double)entities[j].EntityParams[1] + "," + (double)entities[j].EntityParams[2]);
                        Debug.Print("\t\tV1,V2,V3:" + (double)entities[j].EntityParams[3] + ","
                            + (double)entities[j].EntityParams[4] + "," + (double)entities[j].EntityParams[5]);
                        Debug.Print("\t\tR1,R2:" + (double)entities[j].EntityParams[6] + ","
                            + (double)entities[j].EntityParams[7]);
                        supplementalFaces = (Face2[])swMate.GetSupplementalFaces(j);
                    }
                }
            }

            Debug.Print(sPadStr + swFeat.Name + " [" + swFeat.GetTypeName2() + "]");
            if ((swSubFeat = swFeat.IGetFirstSubFeature()) != null) {
                TraverseFeatures2(swSubFeat, nLevel + 1);
            }

            if (nLevel == 1) {
                if ((swFeat = swFeat.IGetNextFeature()) != null) {
                    TraverseFeatures2(swFeat, nLevel);
                }
            } else {
                if ((swFeat = swFeat.GetNextSubFeature()) != null) {
                    TraverseFeatures2(swFeat, nLevel);
                }
            }
            
        }
        
        
        public void TraverseFeatures(Feature swFeat, long nLevel) {
            Feature swSubFeat;
            string sPadStr = "";
            long i = 0;

            for (i = 0; i <= nLevel; i++) {
                sPadStr = sPadStr + "\t";
            }

            while ((swFeat != null)) {
                Debug.Print(sPadStr + swFeat.Name + " [" + swFeat.GetTypeName2() + "]");
                swSubFeat = (Feature)swFeat.GetFirstSubFeature();

                if ((swSubFeat != null)) {
                    TraverseFeatures(swSubFeat, nLevel + 1);
                }

                if (nLevel == 1) {
                    swFeat = (Feature)swFeat.GetNextFeature();
                } else {
                    swFeat = (Feature)swFeat.GetNextSubFeature();
                }
            }
        }

        public void TraverseComponentFeatures(Component2 swComp, long nLevel) {
            Feature swFeat;
            swFeat = (Feature)swComp.FirstFeature();
            //TraverseFeatures(swFeat, nLevel);
            TraverseFeatures2(swFeat, nLevel);
        }

        public void TraverseComponent(Component2 swComp, long nLevel) {
            object[] vChildComp;
            Component2 swChildComp;

            string sPadStr = "";
            long i = 0;

            for (i = 0; i < nLevel; i++) {
                sPadStr = sPadStr + "\t";
            }

            vChildComp = (object[])swComp.GetChildren();

            for (i = 0; i < vChildComp.Length; i++) {
                swChildComp = (Component2)vChildComp[i];
                Debug.Print(sPadStr + "+" + swChildComp.Name2 + " <" + swChildComp.ReferencedConfiguration + ">");
                TraverseComponentFeatures(swChildComp, nLevel);
                TraverseComponent(swChildComp, nLevel + 1);
            }
        }

        public void TraverseModelFeatures(ModelDoc2 swModel, long nLevel) {
            Feature swFeat;
            swFeat = (Feature)swModel.FirstFeature();
            //TraverseFeatures(swFeat, nLevel);
            TraverseFeatures2(swFeat, nLevel);
        }

        public void Run() {
            ModelDoc2 swModel;
            ConfigurationManager swConfMgr;
            Configuration swConf;
            Component2 swRootComp;

            swModel = (ModelDoc2)swApp.ActiveDoc;
            swConfMgr = (ConfigurationManager)swModel.ConfigurationManager;
            swConf = (Configuration)swConfMgr.ActiveConfiguration;
            swRootComp = (Component2)swConf.GetRootComponent3(true);

            System.Diagnostics.Stopwatch myStopwatch = new Stopwatch();
            myStopwatch.Start();
            Debug.Print("File = " + swModel.GetPathName());

            TraverseModelFeatures(swModel, 1);

            /*
            if (swModel.GetType() == (int)swDocumentTypes_e.swDocASSEMBLY) {
                TraverseComponent(swRootComp, 1);
            }
             * */

            myStopwatch.Stop();
            TimeSpan myTimespan = myStopwatch.Elapsed;
            Debug.Print("Time = " + myTimespan.TotalSeconds + " sec");
        }

        /// <summary> 
        /// The SldWorks swApp variable is pre-assigned for you. 
        /// </summary> 
        public SldWorks.SldWorks swApp;
    }
}
