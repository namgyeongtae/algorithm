using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace DivideSum
{
    class Program
    {
        static int DivideSum(int n)
        {
            string str = n.ToString();
            int sum = 0;

            for (int i = 0; i < str.Length; i++)
            {
                sum += str[i] - '0';
            }


            return n + sum;
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int answer = 0;

            for (int i = 1; i <= n; i++)
            {
                if (DivideSum(i) == n)
                {
                    answer = i;
                    break;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
