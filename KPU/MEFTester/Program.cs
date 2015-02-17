using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.Composition;
using System.ComponentModel.Composition.Hosting;
using System.Reflection;
using MEFLab;

namespace MEFTester
{
    public class Program
    {
        [ImportMany]
        public IDLLContract DllContract { get; set; }
        static void Main(string[] args)
        {
            Program blub = new Program();
            blub.Compose();
            blub.DllContract.Init(new AppUtil());
            blub.DllContract.Run();
            blub.DllContract.TearDown();
        }

        public void Compose()
        {
            var catalog = new AssemblyCatalog(Assembly.GetExecutingAssembly());
            var container = new CompositionContainer(catalog);
            container.ComposeParts(this);
        }
    }
}
