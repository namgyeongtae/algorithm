// PermutationAndCombination.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

char arr[4];
bool check[4];
vector<char> v;

void RepititionPermutation(int n, int r)
{
    if (n == r)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        v.push_back(arr[i]);
        RepititionPermutation(n + 1, r);
        v.pop_back();
    }
}

int main()
{
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';

    RepititionPermutation(0, 2);
}