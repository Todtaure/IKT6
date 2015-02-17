using System;
using System.Collections.Specialized;
using System.Runtime.InteropServices;
using System.ComponentModel.Composition;

namespace MEFLab
{
    [Export(typeof(IDLLContract))]
    class DllContract : IDLLContract
    {
        private IAppUtil _util;
        public void Init(IAppUtil util)
        {
            _util = util;
            _util.Name = "Alexander";
        }

        public bool Run()
        {
           Console.WriteLine(_util.GetName());
           Console.WriteLine(_util.MyAddString("Hej", "Sebastian"));
           return true;
        }

        public void TearDown()
        {
            _util = null;
        }
    }
}