// LostBracket.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string expression;

vector<char> op;
vector<int> nums;

int answer = 0;

void Input()
{
    cin >> expression;

    string num = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '-' || expression[i] == '+')
        {
            op.push_back(expression[i]);
            nums.push_back(stoi(num));
            num = "";
        }
        else
        {
            num += expression[i];
        }
    }

    nums.push_back(stoi(num));
}

void solution()
{
    int start = -1;
    int end = -1;

    int temp = 0;

    vector<int> minuses;
    for (int i = 0; i < op.size(); i++)
    {
       // + 이면 계속 계산해 나간다
       if (op[i] == '+')
       {
           if (temp == 0)
               temp = nums[i];
           temp = temp + nums[i + 1];
       }
       // - 이면 쭉 더해왔던 temp를 뺄샘 연산할 숫자들 리스트에 삽입
       else
       {
           if (temp == 0)
               minuses.push_back(nums[i]);
           else
               minuses.push_back(temp);

           temp = 0;
       }
    }

    // 마지막 숫자 삽입
    if (temp != 0)
        minuses.push_back(temp);
    else
        minuses.push_back(nums[nums.size() - 1]);

    answer = minuses[0];
    for (int i = 1; i < minuses.size(); i++)
    {
        answer -= minuses[i];
    }
}

int main()
{
    Input();

    solution();

    cout << answer << endl;
}

