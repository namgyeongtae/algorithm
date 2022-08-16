using System;
using System.Text;
using System.Collections.Generic;

namespace WomenPresident
{
    class Program
    {
        static int Recursive(int k, int n)
        {
            if (n == 1)
                return 1;

            if (k == 0)
                return n;

            return Recursive(k, n - 1) + Recursive(k - 1, n);
        }

        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int k = int.Parse(Console.ReadLine());
                int n = int.Parse(Console.ReadLine());

                Console.WriteLine(Recursive(k, n));
            }
        }
    }
}
