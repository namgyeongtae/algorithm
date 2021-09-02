// InequalSign.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    cin >> input;

    vector<int> equalNums;
    equalNums.assign(input.size() + 1, 0);

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '<')
            equalNums[i + 1] = max(equalNums[i + 1], equalNums[i] + 1);
    }

    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (input[i] == '>')
            equalNums[i] = max(equalNums[i], equalNums[i + 1] + 1);
    }

    long long answer = 0;
    for (int i = 0; i < equalNums.size(); i++)
        answer += equalNums[i];

    cout << answer << endl;
}

