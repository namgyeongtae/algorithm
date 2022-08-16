using System;
using System.Text;
using System.Collections.Generic;

namespace AlarmClock
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split();
            string a = str[0];
            string b = str[1];

            string bigStr = (a.Length > b.Length) ? a : b;
            int min = (a.Length > b.Length) ? b.Length : a.Length;
            int max = (a.Length > b.Length) ? a.Length : b.Length;
            int change = 0;

            string answer = "";
            for (int i = 0; i < min; i++)
            {
                int l = a[a.Length - i - 1] - '0';
                int r = b[b.Length - i - 1] - '0';

                int hap = l + r + change;
                if (hap >= 10)
                {
                    change = 1;
                    hap %= 10;
                }
                else
                    change = 0;

                answer += hap.ToString();
            }

            int remain = max - min;

            for (int i = remain - 1; i >= 0; i--)
            {
                int l = bigStr[i] - '0';
                int hap = l + change;

                if (hap >= 10)
                {
                    change = 1;
                    hap %= 10;
                }
                else
                    change = 0;

                answer += hap.ToString();
            }

            if (change >= 1)
                answer += change.ToString();

            char[] reverse = answer.ToCharArray();

            Array.Reverse(reverse);

            reverse.ToString();

            Console.WriteLine(reverse);
        }
    }
}
