using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleComponent
{
    public sealed class Eventful
    {
        public event EventHandler<TestEventArgs> Test;
        public void OnTest(string msg, long number)
        {
            EventHandler<TestEventArgs> temp = Test;
            if (temp != null)
            {
                temp(this, new TestEventArgs()
                {
                    Value1 = msg,
                    Value2 = number
                });
            }
        }
    }

    public sealed class TestEventArgs
    {
        public string Value1 { get; set; }
        public long Value2 { get; set; }
    }
}
