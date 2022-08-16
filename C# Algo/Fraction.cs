using System;
using System.Text;
using System.Collections.Generic;

namespace AlarmClock
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            int idx = 0;
            int sum = 0;

            while (sum < num)
            {
                sum += ++idx;
            }

            sum -= idx;

            int i = idx;
            int j = 1;

            for (int x = 0; x < num - sum - 1; x++)
            {
                i--;
                j++;
            }

            if (idx % 2 != 0)
                Console.WriteLine($"{i}/{j}");
            else
                Console.WriteLine($"{j}/{i}");
        }
    }
}
