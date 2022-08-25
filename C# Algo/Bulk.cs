using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace AlarmClock
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] height = new int[n];
            int[] weight = new int[n];
            int[] answer = new int[n];

            for (int i = 0; i < n; i++)
            {
                int[] nums = Console.ReadLine().Split().Select(int.Parse).ToArray();
                height[i] = nums[0];
                weight[i] = nums[1];
            }

            for (int i = 0; i < n; i++)
            {
                int rank = 1;

                for (int j = 0; j < n; j++)
                {
                    if (height[i] < height[j] && weight[i] < weight[j])
                    {
                        rank++;
                    }
                }

                answer[i] = rank;
            }

            for (int i = 0; i < answer.Length; i++)
                Console.Write(answer[i] + " ");
            Console.WriteLine();
        }
    }
}
