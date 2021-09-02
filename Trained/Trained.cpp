// Trained.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

struct Trained
{
    vector<int> ai;
    vector<bool> visited;
    int count = 0;

    Trained(int n) : visited(n, false), ai(n, 0) {}

    void Init(int n)
    {
        for (int idx = 1; idx < n; idx++)
            cin >> ai[idx];
    }

    int Training(int n, int start, int goal)
    {
        bool isLoop = true;
        int now = start;

        while (isLoop)
        {
            if (visited[now])
            {
                isLoop = false;
                return -1;
            }

            visited[now] = true;
            now = ai[now];
            count++;

            if (now == goal)
            {
                isLoop = false;
                return count;
            }

        }
    }
};

int main()
{
    int N;
    cin >> N;

    Trained tr(N + 1);
    tr.Init(N + 1);

    int res = tr.Training(N + 1, 1, 2);

    cout << res << endl;

}

