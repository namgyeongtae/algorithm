using System;
using System.Text;
using System.Collections.Generic;

namespace SugarDelivery
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int big = 5;
            int small = 3;

            int answer = 0;

            while (true)
            {
                if (N % big == 0)
                {
                    answer += N / big;
                    break;
                }
                else if (N < small)
                {
                    answer = -1;
                    break;
                }

                N -= small;
                answer++;
            }

            Console.WriteLine(answer);
        }
    }
}
