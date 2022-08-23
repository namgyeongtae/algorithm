using System;
using System.Text;
using System.Collections.Generic;

namespace Hanoi
{
    class Program
    {
        static void hanoi(StringBuilder sb, int from, int mid, int to, int n, ref int count)
        {
            if (n == 0)
                return;

            hanoi(sb, from, to, mid, n - 1, ref count);
            sb.Append(from + " " + to + '\n');
            count += 1;
            hanoi(sb, mid, from, to, n - 1, ref count);
        }

        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();

            int n = int.Parse(Console.ReadLine());
            int count = 0;

            hanoi(sb, 1, 2, 3, n, ref count);

            Console.WriteLine(count);
            Console.WriteLine(sb.ToString());
        }
    }
}
