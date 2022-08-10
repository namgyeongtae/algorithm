using System;
using System.Text;
using System.Collections.Generic;

namespace FindAlphabet
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int[] alphabet = new int[26];
            Array.Fill<int>(alphabet, -1);

            for (int i = 0; i < s.Length; i++)
            {
                if (alphabet[s[i] - 'a'] == -1)
                {
                    alphabet[s[i] - 'a'] = i;
                }
            }

            for (int i = 0; i < 26; i++)
            {
                Console.Write($"{alphabet[i]} ");
            }
            Console.WriteLine();
        }
    }
}
