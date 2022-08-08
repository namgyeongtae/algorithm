using System;
using System.Text;

namespace MinMax
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = new int[n];
            string[] s = Console.ReadLine().Split();

            for (int i = 0; i < s.Length; i++)
            {
                arr[i] = int.Parse(s[i]);
            }

            Array.Sort(arr);

            Console.Write($"{arr[0]} {arr[n - 1]}\n");
        }
    }
}
