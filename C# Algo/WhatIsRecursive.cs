using System;
using System.Text;
using System.Collections.Generic;

namespace WhatIsRecursive
{
    class Program
    {
        static string[] str = { "\"����Լ��� ������?\"",
                                "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
                                "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
                                "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""};

        static void Recursive(int n, int barCnt)
        {
            if (n == 0)
            {
                string baseBar = "";
                for (int i = 0; i < barCnt * 4; i++)
                    baseBar += '_';

                Console.WriteLine(baseBar + "\"����Լ��� ������?\"");
                Console.WriteLine(baseBar + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"");
                Console.WriteLine(baseBar + "��� �亯�Ͽ���.");

                return;
            }

            string bar = "";

            for (int j = 0; j < barCnt * 4; j++)
                bar += '_';

            for (int i = 0; i < str.Length; i++)
                Console.WriteLine(bar + str[i]);

            Recursive(n - 1, barCnt + 1);

            Console.WriteLine(bar + "��� �亯�Ͽ���.");
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            Console.WriteLine("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.");
            Recursive(n, 0);
        }
    }
}
