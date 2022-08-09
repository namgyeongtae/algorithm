using System;
using System.Text;

namespace SelfNum
{
    class Program
    {
        public static int d(int n)
        {
            int answer = 0;
            int temp = n;
            while (n > 0)
            {
                answer += n % 10;
                n /= 10;
            }
            answer += temp;

            return answer;
        }

        static void Main(string[] args)
        {
            int[] arr = new int[10000];

            for (int i = 1; i < 10000; i++)
            {
                if (d(i) < 10000)
                    arr[d(i)] = 1;
            }

            for (int i = 1; i < 10000; i++)
            {
                if (arr[i] != 1)
                    Console.WriteLine(i);
            }
        }
    }
}
