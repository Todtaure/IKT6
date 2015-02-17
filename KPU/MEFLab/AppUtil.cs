using System;
using System.Runtime.InteropServices;

namespace MEFLab
{
    public class AppUtil : IAppUtil
    {
        private string _name;

        public string GetName()
        {
            return _name;
        }

        public string MyAddString(string str1, string str2)
        {
            return str1 + str2;
        }

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }
    }
}