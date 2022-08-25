using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace BlackJack
{
    class Program
    {
        static bool[] visited = new bool[101];

        static void BlackJack(int n, int m, ref int max, ref int output, int[] arr)
        {
            if (n == 3)
            {
                if (output <= m && output > max)
                    max = output;

                return;
            }

            for (int i = 0; i < arr.Length; i++)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    output += arr[i];
                    BlackJack(n + 1, m, ref max, ref output, arr);
                    output -= arr[i];
                    visited[i] = false;
                }
            }
        }

        static void Main(string[] args)
        {
            int[] nums = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();

            int output = 0;
            int max = 0;

            BlackJack(0, nums[1], ref max, ref output, arr);

            Console.WriteLine(max);
        }
    }
}
