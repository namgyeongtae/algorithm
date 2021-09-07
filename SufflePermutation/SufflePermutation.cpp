// SufflePermutation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

vector<vector<int>> _matrix;

void InitMatrix(int n)
{
    int input;
    vector<int> vec;
    _matrix.assign(n, vec);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            _matrix[i].push_back(input);
        }
    }
    
}

struct UnionFind
{
    vector<int> pa, rank, size;
    int _size;

    UnionFind(int n) : rank(n), size(n, 1)
    {
        for (int i = 0; i < n; i++)
            pa.push_back(i);   
        _size = n;
    }

    int Find(int x)
    {
        if (x == pa[x])
            return x;
        else
            return pa[x] = Find(pa[x]);
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if (x == y)
            return;

       
        
       if (x < y)
            pa[y] = x;
        else
            pa[x] = y;

        
    }

    void connectNode()
    {
        for (int i = 0; i < _size; i++)
        {
            pa[i] = Find(i);
        }
    }

};

long long factorial(long long x)
{
    if (x == 0) return 1;
    else if (x == 1) return x;
    else
        return x * factorial(x - 1) % MOD;
}

int main()
{
    int N, K;
    cin >> N >> K;

    InitMatrix(N);

    bool swapable = true;

    UnionFind rowUnion(N);
    UnionFind colUnion(N);   

    for (int x = 0; x < N; x++)
    {
        for (int y = x + 1; y < N; y++)
        {
            for (int i = 0; i < N; i++)
            {
                
                if (_matrix[i][x] + _matrix[i][y] > K)
                {
                    swapable = false;                   
                    break;
                }
                
            }

            if (swapable)
            {
                colUnion.Union(x, y);
                colUnion.connectNode();
            }
            swapable = true;
        }
    }
    

    for (int x = 0; x < N; x++)
    {
        for (int y = x + 1; y < N; y++)
        {
            for (int i = 0; i < N; i++)
            {              
                if (_matrix[x][i] + _matrix[y][i] > K)
                {
                    swapable = false;
                    break;
                }              
            }

            if (swapable)
            {
                rowUnion.Union(x, y);
                rowUnion.connectNode();
            }
            swapable = true;
        }
    }
    

    long long res = 1;
    vector<long long> fact;
    fact.assign(N, 0);

    for (int i = 0; i < N; i++)
        fact[colUnion.pa[i]] += 1;

    for (int i = 0; i < N; i++)
    {
        res *= factorial(fact[i]);
        //res *= factorial(colUnion.size[colUnion.Find(i)]);
    }

    fact.assign(N, 0);

    for (int i = 0; i < N; i++)
        fact[rowUnion.pa[i]] += 1;

    for (int i = 0; i < N; i++)
    {
        res *= factorial(fact[i]);
        // res *= factorial(rowUnion.size[rowUnion.Find(i)]);
    }

    cout << res % MOD << endl;
}


