using System;

namespace AlarmClock
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();

            int hour = int.Parse(s[0]);
            int minute = int.Parse(s[1]);

            minute -= 45;

            if (minute < 0)
            {
                minute += 60;
                hour -= 1;
            }

            if (hour < 0)
                hour = 23;

            Console.Write(hour);
            Console.Write(" ");
            Console.WriteLine(minute);
        }
    }
}
