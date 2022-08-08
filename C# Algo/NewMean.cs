using System;
using System.Text;

namespace NewMean
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            double[] arr = new double[n];
            string[] str = Console.ReadLine().Split();

            for (int i = 0; i < n; i++)
            {
                arr[i] = int.Parse(str[i]);
            }

            Array.Sort(arr);

            double hap = 0;

            for (int i = 0; i < n; i++)
            {
                arr[i] = arr[i] / arr[n - 1] * 100;
                hap += arr[i];
            }

            double answer = hap / n;

            Console.WriteLine(answer);
        }
    }
}
