using System;
using System.Text;
using System.Collections.Generic;

namespace Croatia
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> list = new List<string>();
            list.Add("c=");
            list.Add("c-");
            list.Add("dz=");
            list.Add("d-");
            list.Add("lj");
            list.Add("nj");
            list.Add("s=");
            list.Add("z=");

            string input = Console.ReadLine();
            int answer = 0;
            int i;

            for (i = 0; i < input.Length - 2;)
            {
                for (int j = 2; j <= 4; j++)
                {
                    if (j == 4)
                    {
                        i += 1;
                        break;
                    }

                    string s = input.Substring(i, j);
                    if (list.Contains(s))
                    {
                        i += j;
                        break;
                    }
                }
                answer++;
            }

            if (i == input.Length - 2)
            {
                if (list.Contains(input.Substring(i, 2)))
                {
                    answer += 1;
                }
                else
                {
                    answer += 2;
                }
            }
            else if (i == input.Length - 1)
                answer += 1;

            Console.WriteLine(answer);
        }
    }
}
