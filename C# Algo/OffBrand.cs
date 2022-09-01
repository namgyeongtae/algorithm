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
            StringBuilder sb = new StringBuilder();

            int[] NM = Console.ReadLine().Split().Select(int.Parse).ToArray();

            Dictionary<string, int> dict = new Dictionary<string, int>();
            SortedSet<string> ss = new SortedSet<string>();

            for (int i = 0; i < NM[0]; i++)
            {
                string name = Console.ReadLine();
                if (!dict.ContainsKey(name))
                {
                    dict.Add(name, 1);
                }
                else
                    dict[name]++;
            }

            for (int i = 0; i < NM[1]; i++)
            {
                string name = Console.ReadLine();
                if (dict.ContainsKey(name))
                    ss.Add(name);
            }

            Console.WriteLine(ss.Count());

            foreach (string str in ss)
                sb.Append(str + "\n");

            Console.WriteLine(sb);
        }
    }
}
