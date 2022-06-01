#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    string temp = "";
    
    int start = 0;
    int end = k;
    
    
    
    while (end < number.size())
    {
        char max = '0';
        for (int i = start; i <= end; i++)
        {
            if (max - '0' < number[i] - '0')
            {
                max = number[i];
                start = i + 1;
            }
        }
        answer += max;
        end++;
    }
    
    
    return answer;
}