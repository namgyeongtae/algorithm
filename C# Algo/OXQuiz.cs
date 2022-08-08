using System;
using System.Text;

namespace OXQuiz
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int answer = 0;

            int acc = 0;
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();

                for (int j = 0; j < s.Length; j++)
                {
                    if (s[j] == 'O')
                    {
                        answer += (++acc);
                    }
                    else
                        acc = 0;
                }

                Console.WriteLine(answer);
                acc = 0;
                answer = 0;
            }
        }
    }
}
