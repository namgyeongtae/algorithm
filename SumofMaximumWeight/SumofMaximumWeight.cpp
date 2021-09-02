// SumofMaximumWeight.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    return p1.second < p2.second;
}

int GetParent(int* parent, int x)
{
    if (parent[x] == x)  return x;
    return parent[x] = GetParent(parent, parent[x]); 
}

void unionParent(int* parent, int* rank, int a, int b)
{
    a = GetParent(parent, a);
    b = GetParent(parent, b);
    if (rank[a] < rank[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;

        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int findParent(int* parent, int a, int b)
{
    a = GetParent(parent, a);
    b = GetParent(parent, b);
    if (a == b) return 1;
    else return 0;
}

int main()
{
    int n; 
    cin >> n;
    
    vector<pair<pair<int, int>, int>> pairVec;

    int u, v;
    long long w;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        pairVec.push_back(make_pair(make_pair(u, v), w));
    }
    
    sort(pairVec.begin(), pairVec.end(), compare);

    long long answer = 0;
    int* parent = new int[n + 1]{ 0 };
    int* rank = new int[n + 1]{ 0 };
    for (int i = 0; i < n + 1; i++)
        parent[i] = i;

    vector<long long> mul(n + 1, 1);

    for (int i = 0; i < pairVec.size(); i++)
    {
        answer += pairVec[i].second * mul[GetParent(parent, pairVec[i].first.first)] * mul[GetParent(parent, pairVec[i].first.second)];
        long long temp = mul[GetParent(parent, pairVec[i].first.first)] + mul[GetParent(parent, pairVec[i].first.second)];
        unionParent(parent, rank, pairVec[i].first.first, pairVec[i].first.second);
        mul[GetParent(parent, pairVec[i].first.first)] = temp;
        mul[GetParent(parent, pairVec[i].first.second)] = temp;

    }

    cout << answer << endl;
    
}
