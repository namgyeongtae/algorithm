// HowMany.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    int s, t;
    cin >> s >> t;

    for (int a = 0; a < s + 1; a++)
    {
        for (int b = 0; b < s - a + 1; b++)
        {
            for (int c = 0; c < s - (a + b) + 1; c++)
            {
                if (a * b * c <= t)
                    count++;
            }
        }
    }

    cout << count << endl;
}

