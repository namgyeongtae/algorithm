#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = people.size() - 1;
    
    bool visited[50000];
    
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());
    
    // 그리디에서 은근히 이런 투포인터 형식을 잘 쓰는 듯 하니
    // 염두해두자
    // 특히 여기서는 총 2명이서 탈 수 있는데 가장 가벼운 사람과 탈 수 있는지
    // 무거운 순으로 탐색하며 탈 수 있는 사람을 찾는다
    // 그리고 같이 타는 2명을 1로 카운트하고 나머지는 1명만 탈 수 있으니
    // 전체 인원 수에서 2명 쌍 개수를 차감
    int i = 0;
    int j = people.size() - 1;
    
    while (i < j)
    {
        if (people[i] + people[j] <= limit)
        {
            j -= 1;
            answer++;
        }
        i++;
    }
    
    return people.size() - answer;
}