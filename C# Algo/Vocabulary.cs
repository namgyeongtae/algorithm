using System;
using System.Text;
using System.Collections.Generic;

namespace Vocablary
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int[] alphabet = new int[26];

            for (int i = 0; i < s.Length; i++)
            {
                if ((int)s[i] > 90)
                {
                    char c = (char)(s[i] - 32);
                    alphabet[c - 'A'] += 1;
                }
                else
                    alphabet[s[i] - 'A'] += 1;
            }

            int max = 0;
            int idx = -1;
            int count = 0;

            for (int i = 0; i < 26; i++)
            {
                if (alphabet[i] > max)
                {
                    max = alphabet[i];
                    idx = i;
                    count = 1;
                }
                else if (alphabet[i] == max)
                {
                    count++;
                }
            }

            if (count > 1)
                Console.WriteLine('?');
            else if (count == 1)
                Console.WriteLine((char)(idx + 'A'));
        }
    }
}
