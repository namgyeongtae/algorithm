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
            int N = int.Parse(Console.ReadLine());

            int[] arr = new int[N];

            for (int i = 0; i < N; i++)
                arr[i] = int.Parse(Console.ReadLine());

            Array.Sort(arr);

            for (int i = 0; i < arr.Length; i++)
                Console.WriteLine(arr[i]);
        }
    }
}
