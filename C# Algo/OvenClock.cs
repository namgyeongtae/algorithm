using System;

namespace OvenClock
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            int m = int.Parse(Console.ReadLine());

            int hour = int.Parse(s[0]);
            int minute = int.Parse(s[1]);

            minute += m;

            while (minute >= 60)
            {
                minute -= 60;
                hour += 1;
            }

            if (hour >= 24)
                hour -= 24;

            Console.Write(hour);
            Console.Write(" ");
            Console.WriteLine(minute);
        }
    }
}
