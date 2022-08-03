using System;
using System.Text;

namespace Number
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());

            StringBuilder answer = new StringBuilder();

            for (int i = num; i > 0; i--)
            {
                answer.AppendLine(i.ToString());
            }

            Console.WriteLine(answer);
        }
    }
}
