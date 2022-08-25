using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace MovieTitle
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 665;
            int n = int.Parse(Console.ReadLine());
            int count = 0;

            while (count < n)
            {
                num++;

                string s = num.ToString();

                if (s.Contains("666"))
                {
                    count++;
                }
            }

            Console.WriteLine(num);
        }
    }
}
