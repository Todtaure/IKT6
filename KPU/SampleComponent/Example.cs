using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;

namespace SampleComponent
{
    public sealed class Example
    {
        public static string GetAnswer()
        {
            return "The answer is 42";
        }

        public int SampleProperty { get; set; }

        public static IDictionary<int, string> GetMapOfNames()
        {
            Dictionary<int, string> retval = new Dictionary<int, string>();
            retval.Add(1, "one");
            retval.Add(2, "two");
            retval.Add(3, "three");
            retval.Add(42, "forty-two");
            retval.Add(100, "one hundred");
            return retval;
        }
        public static IAsyncOperationWithProgress<IList<long>, double> GetPrimesInRangeAsync(long start, long count)
        {
            if (start < 2 || count < 1) throw new ArgumentException();

            return AsyncInfo.Run<IList<long>, double>((token, progress) =>

                Task.Run<IList<long>>(() =>
                {
                    List<long> primes = new List<long>();
                    double onePercent = count / 100;
                    long ctProgress = 0;
                    double nextProgress = onePercent;

                    for (long candidate = start; candidate < start + count; candidate++)
                    {
                        ctProgress += 1;
                        if (ctProgress >= nextProgress)
                        {
                            progress.Report(ctProgress / onePercent);
                            nextProgress += onePercent;
                        }
                        bool isPrime = true;
                        for (long i = 2, limit = (long)Math.Sqrt(candidate); i <= limit; i++)
                        {
                            if (candidate % i == 0)
                            {
                                isPrime = false;
                                break;
                            }
                        }
                        if (isPrime) primes.Add(candidate);

                        token.ThrowIfCancellationRequested();
                    }
                    progress.Report(100.0);
                    return primes;
                }, token)
            );
        }
    }
}
