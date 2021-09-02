// evenString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int n = input.size();

    while (n > 1)
    {
        input = input.substr(0, input.size() - 1);
        n = input.size();

        if (n % 2 != 0)
            continue;

        int mid = input.size() / 2;

        string a = input.substr(0, mid);
        string b = input.substr(mid, mid);

        if (a == b)
        {
            cout << n << endl;
            break;
        }
    }
}

