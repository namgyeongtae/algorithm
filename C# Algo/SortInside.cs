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
            string s = Console.ReadLine();

            int[] arr = new int[s.Length];

            for (int i = 0; i < s.Length; i++)
            {
                arr[i] = s[i] - '0';
            }

            for (int i = 0; i < s.Length; i++)
            {
                for (int j = 1; j < s.Length - i; j++)
                {
                    if (arr[j - 1] < arr[j])
                    {
                        int temp = arr[j - 1];
                        arr[j - 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            for (int i = 0; i < s.Length; i++)
                Console.Write(arr[i]);
            Console.WriteLine();
        }
    }
}
