using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace AlarmClock
{
    class Program
    {
        static bool[] visited = new bool[9];

        static List<int> answerList = new List<int>();

        static void Combination(StringBuilder sb, int n, int k, int idx, int cnt)
        {
            if (cnt == k)
            {
                for (int i = 0; i < answerList.Count; i++)
                    sb.Append(answerList[i] + " ");

                Console.WriteLine(sb);

                sb.Clear();
            }


            for (int i = idx; i < n; i++)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    answerList.Add(i + 1);
                    Combination(sb, n, k, i, cnt + 1);
                    answerList.RemoveAt(answerList.Count - 1);
                    visited[i] = false;
                }
            }
        }

        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();

            Combination(sb, arr[0], arr[1], 0, 0);

        }
    }
}
