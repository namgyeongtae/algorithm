using System;
using System.Text;
using System.Collections.Generic;

namespace Factorial
{
    class Program
    {
        static int factorial(int n)
        {
            if (n == 1 || n == 0)
                return 1;

            return n * factorial(n - 1);
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            Console.WriteLine(factorial(n));
        }
    }
}
