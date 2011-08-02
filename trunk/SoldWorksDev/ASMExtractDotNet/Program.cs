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
        public void TraverseFeatures(Feature swFeat, long nLevel) {
            Feature swSubFeat;
            string sPadStr = " ";
            long i = 0;

            for (i = 0; i <= nLevel; i++) {
                sPadStr = sPadStr + " ";
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
            TraverseFeatures(swFeat, nLevel);
        }

        public void TraverseComponent(Component2 swComp, long nLevel) {
            object[] vChildComp;
            Component2 swChildComp;

            string sPadStr = " ";
            long i = 0;

            for (i = 0; i <= nLevel - 1; i++) {
                sPadStr = sPadStr + " ";
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
            TraverseFeatures(swFeat, nLevel);
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

            if (swModel.GetType() == (int)swDocumentTypes_e.swDocASSEMBLY) {
                TraverseComponent(swRootComp, 1);
            }

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
