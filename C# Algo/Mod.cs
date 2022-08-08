using System;
using System.Text;

namespace Mod
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] mods = new int[42];
            int answer = 0;

            for (int i = 0; i < 10; i++)
            {
                int num = int.Parse(Console.ReadLine());

                if (mods[num % 42] != 1)
                {
                    mods[num % 42] = 1;
                    answer += 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
