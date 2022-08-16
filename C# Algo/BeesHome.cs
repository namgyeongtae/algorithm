using System;
using System.Text;
using System.Collections.Generic;

namespace BeesHome
{
    class Program
    {
        static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());
            int start = 2;
            int layer = 1;

            int i = 1;
            while (start <= input)
            {
                start += 6 * i;
                i++; layer++;
            }

            Console.WriteLine(layer);
        }
    }
}
