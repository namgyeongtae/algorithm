#include <string>
#include <vector>
#include <cstring>

// 단체사진에 나올 수 있는 멤버들의 정렬 순서를 모두 탐색해가며 (순열 -> DFS)
// 하나씩 입력으로 주어진 조건에 부합하는지 검사하여 Count!

using namespace std;

int answer;
bool check[8];


void dfs(int cnt, char arr[], char friends[], vector<string> data)
{
    // base case
    if (cnt == 8)
    {
        for (int i = 0; i < data.size(); i++)
        {
            char first = data[i][0];
            char second = data[i][2];
            char value = data[i][3];
        
            int dist = data[i][4] - '0';
            
            dist++;
            
            int idx1 = -1;
            int idx2 = -1;
            
            for (int j = 0; j < 8; j++)
            {
                if (arr[j] == first) idx1 = j;
                if (arr[j] == second) idx2 = j;
                if (idx1 != -1 && idx2 != -1) break;
            }
            
            if (value == '=' && abs(idx1 - idx2) != dist) return;
            if (value == '<' && abs(idx1 - idx2) >= dist) return;
            if (value == '>' && abs(idx1 - idx2) <= dist) return;
        }
        
        answer++;
        return;
    }
    
    for (int i = 0; i < 8; i++)
    {
        if (check[i]) continue;
        check[i] = true;
        arr[cnt] = friends[i];
        dfs(cnt + 1, arr, friends, data);
        check[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    char arr[8] = {NULL, };
    char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    memset(check, false, sizeof(check));
    answer = 0;
    dfs(0, arr, friends, data);
    return answer;
}