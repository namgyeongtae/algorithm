// Puzzle_1525.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

map<string, int> mp;
vector<int> graph[10];

string str("999999999");

void Input()
{
    graph[1] = { 2, 4 };
    graph[2] = { 1, 3, 5 };
    graph[3] = { 2, 6 };
    graph[4] = { 1, 5, 7 };
    graph[5] = { 2, 4, 6, 8 };
    graph[6] = { 3, 5, 9 };
    graph[7] = { 4, 8 };
    graph[8] = { 5, 7, 9 };
    graph[9] = { 6, 8 };

    for (int i = 0; i < 9; i++)
    {
        int x;
        cin >> x;
        if (x != 0) str[i] = x + '0';
    }
}

void solution()
{
    mp[str] = 0;
    queue<string> q;
    q.push(str);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        int idx = cur.find("9");

        for (int i = 0; i < graph[idx + 1].size(); i++)
        {
            string nextStr = cur;

            swap(nextStr[idx], nextStr[graph[idx + 1][i] - 1]);

            if (!mp.count(nextStr) || mp[nextStr] > mp[cur] + 1)
            {
                mp[nextStr] = mp[cur] + 1;
                q.push(nextStr);
            }
        }
    }

    if (mp.count("123456789")) cout << mp["123456789"];
    else cout << -1;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    Input();

    solution();
}

