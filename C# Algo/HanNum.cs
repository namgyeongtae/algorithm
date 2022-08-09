using System;
using System.Text;

namespace HanNum
{
    class Program
    {
        public static int Darr(string s)
        {
            if (s.Length == 1)
                return 1;

            int d = (s[0] - s[1]) - '0';

            for (int i = 1; i < s.Length - 1; i++)
            {
                int nextD = (s[i] - s[i + 1]) - '0';

                if (nextD != d)
                    return 0;
            }

            return 1;
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int answer = 0;

            for (int i = 1; i <= n; i++)
            {
                if (Darr(i.ToString()) == 1)
                    answer += 1;
            }

            Console.WriteLine(answer);
        }
    }
}
