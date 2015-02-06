using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Configuration;
using System.Text;
using System.Threading.Tasks;

namespace CprDLL
{
    public class CprCheck
    {
        public enum CprError
        {
            NoError, FormatError, DateError, Check11Error
        };

        public bool Check(string cprTxt, out CprError error)
        {
            error = CprError.NoError;

            if(CheckFormat10Test(cprTxt) != CprError.NoError)
            {
                error = CprError.FormatError;
            }

            if (CheckDateTest(cprTxt) != CprError.NoError)
            {
                error = CprError.DateError;
            }

            if(Check11Test(cprTxt) != CprError.NoError)
            {
                error = CprError.Check11Error;
            }
            return error == CprError.NoError;
        }

        private CprError CheckFormat10Test(string cprTxt)
        {
            CprError cprError = CprError.NoError;

            if (cprTxt.Length != 10)
            {
                cprError = CprError.FormatError;                   
            }
            
            return cprError;
        }

        private CprError CheckDateTest(string cprTxt)
        {
            CprError cprError = CprError.NoError;

            try
            {
                DateTime cprDate = new DateTime(Int32.Parse(cprTxt.Remove(0, 4).Remove(2)), Int32.Parse(cprTxt.Remove(0, 2).Remove(2)), Int32.Parse(cprTxt.Remove(2)));
            }
            catch (ArgumentOutOfRangeException)
            {
                cprError = CprError.DateError;
            }
            
            return cprError;
        }

        /// <summary>
        /// The CPR check sum algorithm is calculated by mulitiplying each digit with a factor
        /// and then add all results and divide the sum by 11.
        /// Factors: 4327654321
        /// CPR: 0609240121
        /// Sum: 0 + 18 + 0 + 72 + 12 + 20 + 0 + 1 + 4 + 1 = 121 / 11 = 11.0 -> CPR is OK
        /// </summary>
        ///
        private CprError Check11Test(string cprTxt)
        {
            CprError cprError = CprError.NoError;
            int sum = 0;
            for (int i = 0; i < 3; i++)
                sum += int.Parse(cprTxt.Substring(i, 1)) * (4 - i);
            for (int i = 3; i < 10; i++)
                sum += int.Parse(cprTxt.Substring(i, 1)) * (10 - i);
            if (sum % 11 != 0)
                cprError = CprError.Check11Error;
            return cprError;
        }
    }
}
