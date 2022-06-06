// NGE_17298.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;

vector<int> v;
vector<int> ans;
stack<int> st;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x; 
        cin >> x;
        v.push_back(x);
    }
}

void solution()
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        // 처음부터 스택이 비어 있다면 ans에 -1 삽입
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(v[i]);
        }
        else
        {
            while (!st.empty())
            {
                // 현재 v의 원소가 스택의 top보다 작으면
                // ans에 top 삽입후 현재 v의 원소를 스택에 축적
                if (st.top() > v[i])
                {
                    ans.push_back(st.top());
                    st.push(v[i]);
                    break;
                }
                // top이 더 작으면 필요없으므로 pop
                else
                {
                    st.pop();
                }
            }
            
            // 반복문을 통과할 때 스택이 빌때까지 돌려졌다면
            // ans에 -1 삽입 후 스택에 현재 원소 삽입
            if (st.empty())
            {
                ans.push_back(-1);
                st.push(v[i]);
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    Input();

    solution();
}


