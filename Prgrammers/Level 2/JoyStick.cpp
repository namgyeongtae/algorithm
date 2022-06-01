#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int turn = name.size() - 1;
    int next = 0;
    
    while (name[turn] == 'A' && turn > 0)
        turn -= 1;
    
    if (turn < 0)
        return answer;
    
    for (int i = 0; i < name.size(); i++)
    {   
        // 알파벳 하나 변경하는 카운트
        if (name[i] - 'A' <= 'Z' - name[i])
	answer += name[i] - 'A';
        else
	answer += 'Z' - name[i] + 1;
        
        // 반복문을 돌면서 제일 움직임이 적은 경우 도출
        next = i + 1;
        while (next < name.size() && name[next] == 'A')
            next++;
        
        int mini = 0;
        if (i < name.size() - next)
            mini = i;
        else
            mini = name.size() - next;
        
        if (turn > i + name.size() - next + mini)
            turn = i + name.size() - next + mini;
     }
    answer += turn;
    
    return answer;
}