using System;
using System.Text;
using System.Collections.Generic;

namespace Fibo
{
    class Program
    {
        static int fibo(int n)
        {
            if (n == 0)
                return 0;
            if (n == 1)
                return 1;

            return fibo(n - 2) + fibo(n - 1);
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            Console.WriteLine(fibo(n));
        }
    }
}
