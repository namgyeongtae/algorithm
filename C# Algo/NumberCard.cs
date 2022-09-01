using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace NumberCard
{
    class Program
    {
        static int BinarySearch(int[] cards, int n)
        {
            int left = 0;
            int right = cards.Length - 1;
            int mid;

            while (left <= right)
            {
                mid = (left + right) / 2;

                if (cards[mid] == n)
                    return 1;
                else if (cards[mid] < n)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            return 0;
        }

        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();

            int N = int.Parse(Console.ReadLine());
            int[] cards = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int M = int.Parse(Console.ReadLine());
            int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();

            Array.Sort(cards);

            for (int i = 0; i < arr.Length; i++)
            {
                int answer = BinarySearch(cards, arr[i]);
                sb.Append(answer + " ");
            }

            Console.WriteLine(sb);
        }
    }
}
