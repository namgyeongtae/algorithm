using System;

namespace Cycle
{
    class Program
    {
        static void Main(string[] args)
        {
            int answer = 0;
            int num = int.Parse(Console.ReadLine());
            int temp = num;

            while (temp != num || answer == 0)
            {
                int share = temp / 10;
                int mod = temp % 10;

                temp = mod * 10 + (share + mod) % 10;
                answer += 1;
            }

            Console.WriteLine(answer);
        }
    }
}
