using System;
using System.Text;
using System.Collections.Generic;

namespace StarPoint
{
    class Program
    {
        static void starPoint(int nowY, int nowX, int n, StringBuilder sb)
        {
            if (n == 1)
            {
                //Console.Write('*');
                sb.Append('*');
                return;
            }

            if ((nowY % n >= n / 3 && nowY % n < (n / 3) * 2) && (nowX % n >= n / 3 && nowX % n < (n / 3) * 2))
            {
                //Console.Write(' ');
                sb.Append(' ');
            }
            else
                starPoint(nowY, nowX, n / 3, sb);
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    starPoint(i, j, n, sb);
                }
                sb.Append('\n');
            }

            Console.WriteLine(sb.ToString());
        }
    }
}
