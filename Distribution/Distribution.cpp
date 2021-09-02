// Distribution.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int* S = new int[n];
    int* T = new int[n];

    for (int i = 0; i < n; i++)
        cin >> S[i];

    for (int i = 0; i < n; i++)
        cin >> T[i];

    int* answers = new int[n];
    answers[0] = T[0];

    for (int i = 1; i < 2 * n; i++)
    {
        int save = answers[(i - 1) % n] + S[(i - 1) % n];
        if (T[i % n] < save)
            answers[i % n] = T[i % n];
        else
            answers[i % n] = save;
    }

    for (int i = 0; i < n; i++)
        cout << answers[i] << " ";
    cout << endl;
}

