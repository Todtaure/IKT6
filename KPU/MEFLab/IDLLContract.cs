using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MEFLab
{
    public interface IDLLContract
    {
        void Init(IAppUtil util);
        bool Run();
        void TearDown();
    }

    public interface IAppUtil
    {
        string Name { get; set; }
        string GetName();
        string MyAddString(string str1, string str2);
    }
}
