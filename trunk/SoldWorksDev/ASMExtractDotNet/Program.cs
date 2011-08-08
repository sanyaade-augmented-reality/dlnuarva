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
            SldWorks.SldWorks swApp = new SldWorks.SldWorks();
            swApp.Visible = true;

            SolidWorksASMExtractor extractor = new SolidWorksASMExtractor(swApp);
            /*
            List<Feature> mateFeatures = extractor.GetFeaturesOfMateGroup();
            foreach (Feature feat in mateFeatures) {
                Debug.Print(feat.Name + ": " + feat.GetFaceCount());
            }
             * */

            
            List<Mate2> mates = extractor.GetMates();
            foreach (Mate2 mate in mates) {
                /*
                List<MateEntity2> entities = extractor.GetMateEntityOfMate(mate);
                Debug.Print(" "  + entities.Count);
                 * */
                Debug.Print(" " + mate.MateLoadReference.GetFacesCount(0));
                Debug.Print(" " + mate.MateLoadReference.GetFacesCount(1));
            }
           

            Console.WriteLine("程序已运行结束，按任意键退出。");
            Console.ReadKey();
        }
    }

    
}
