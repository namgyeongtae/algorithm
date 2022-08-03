using System;

namespace Xmin
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] firstLine = Console.ReadLine().Split();
            string[] secondLine = Console.ReadLine().Split();

            int count = int.Parse(firstLine[0]);
            int limit = int.Parse(firstLine[1]);

            for (int i = 0; i < count; i++)
            {
                if (int.Parse(secondLine[i]) < limit)
                {
                    Console.Write(secondLine[i] + " ");
                }
            }
            Console.WriteLine();
        }
    }
}
