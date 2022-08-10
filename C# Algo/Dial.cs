using System;
using System.Text;
using System.Collections.Generic;

namespace Dial
{
    class Program
    {
        static void Main(string[] args)
        {
            int answer = 0;
            string grandmother = Console.ReadLine();
            int[] alphabet = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

            for (int i = 0; i < grandmother.Length; i++)
            {
                answer += alphabet[grandmother[i] - 'A'];
            }

            Console.WriteLine(answer);
        }
    }
}
