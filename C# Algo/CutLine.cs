using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace CutLine
{
    class Program
    {
        public static int[] sorted = new int[1000];

        static void merge(int[] arr, int left, int mid, int right)
        {
            int i, j, k, l;
            i = left;
            j = mid + 1;
            k = left;

            // 분할 정렬된 arr의 합병
            while (i <= mid && j <= right)
            {
                if (arr[i] <= arr[j])
                    sorted[k++] = arr[i++];
                else
                    sorted[k++] = arr[j++];
            }

            // 남아 있는 값들을 복사
            if (i > mid)
                for (l = j; l <= right; l++)
                    sorted[k++] = arr[l];
            else
                for (l = i; l <= mid; l++)
                    sorted[k++] = arr[l];

            for (l = left; l <= right; l++)
                arr[l] = sorted[l];
        }

        static void merge_sort(int[] scores, int left, int right)
        {
            int mid;

            if (left < right)
            {
                mid = (left + right) / 2;
                merge_sort(scores, left, mid);
                merge_sort(scores, mid + 1, right);
                merge(scores, left, mid, right);
            }
        }

        static void Main(string[] args)
        {
            int[] num = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] scores = Console.ReadLine().Split().Select(int.Parse).ToArray();

            merge_sort(scores, 0, num[0] - 1);

            Console.WriteLine(sorted[scores.Length - num[1]]);

        }
    }
}
