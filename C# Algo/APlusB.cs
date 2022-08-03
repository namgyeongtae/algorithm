using System;

namespace Plus
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());

            for (int i = 1; i <= num; i++)
            {
                string[] line = Console.ReadLine().Split();

                Console.WriteLine($"Case #{i}: {line[0]} + {line[1]} = {int.Parse(line[0]) + int.Parse(line[1])}");
            }
        }
    }
}
