using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices; // Needed

namespace Lab9_Pinvoke
{
    public class MessageBeepWrapper
    {
        [DllImport("User32.dll")]
        public static extern Boolean MessageBeep(UInt32 beepType);
    }

    public class BeepWrapper
    {
        [DllImport("Kernel32.dll")]
        public static extern Boolean Beep(UInt32 freq, UInt32 duration);
    }

    public class MathWrapper
    {
        [DllImport("UnmanagedDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double Add(double a, double b);
    }

    public delegate double CallBackFunction(double pf);

    public class CallBackWrapper
    {
        [DllImport("DllWithCallBack.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SomeUnmanagedFunctionUsingCallback(double x, CallBackFunction pF);

        public static double DoubleX2(double x)
        {
            return x*2;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //MessageBeepWrapper.MessageBeep(0);
            //BeepWrapper.Beep(750,300);
            //Console.WriteLine(MathWrapper.Add(2, 4));
            CallBackWrapper.SomeUnmanagedFunctionUsingCallback(2, new CallBackFunction(CallBackWrapper.DoubleX2));

            Console.ReadKey();
        }
    }
}
