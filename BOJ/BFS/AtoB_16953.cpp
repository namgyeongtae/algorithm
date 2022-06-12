// PracticeNote.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

#define MAX 1000000000

using namespace std;

long long start;
long long goal;

void Input()
{
    cin >> start >> goal;
}

// 거꾸로 탐색 
void solve()
{
    int answer = 1;

    while (start < goal)
    {
        // 일의 자리 숫자가 1일 때
        if (goal % 10 == 1)
        {
            goal /= 10;
            answer++;
        }
        // 일의 자리 숫자가 1이 아닐 때
        else
        {
            if (goal % 2 != 0)
                break;

            goal /= 2;
            answer++;
        }
    }

    if (start != goal) cout << -1 << '\n';
    else
    {
        cout << answer << '\n';
    }

}

// BFS 알고리즘 탐색
bool visited[MAX];
int bfsSolution()
{
    queue< pair < long long, long long > > q;
    q.push(make_pair(start, 1));
    visited[start] = true;

    while (!q.empty())
    {
        int nowNum = q.front().first;
        int cnt = q.front().second;
        
        q.pop();

        if (nowNum == goal)
            return cnt;

        if (nowNum * 2 <= goal && !visited[nowNum * 2])
        {
            q.push(make_pair(nowNum * 2, cnt + 1));
            visited[nowNum * 2] = true;
        }
        
        if (nowNum * 10 + 1 <= goal && !visited[nowNum * 10 + 1])
        {
            q.push(make_pair(nowNum * 10 + 1, cnt + 1));
            visited[nowNum * 10 + 1] = true;
        }
    }

    return -1;
}

int main()
{
    Input();
    
    cout << bfsSolution() << '\n';
}


