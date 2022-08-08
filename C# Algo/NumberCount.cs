using System;
using System.Text;

namespace NumberCount
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numCount = new int[10];
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int c = int.Parse(Console.ReadLine());

            long res = a * b * c;

            string s = res.ToString();

            for (int i = 0; i < s.Length; i++)
            {
                numCount[s[i] - '0']++;
            }

            for (int i = 0; i < numCount.Length; i++)
            {
                Console.WriteLine(numCount[i]);
            }
        }
    }
}
