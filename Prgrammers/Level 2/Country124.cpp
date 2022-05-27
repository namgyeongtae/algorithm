#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int arr[4] = {0, 1, 2, 4};
    
    vector<int> v;
    
    while (n != 0)
    {
        if (n % 3 == 0)
        {
            v.push_back(arr[3]);
            n = n / 3 - 1;
        }
        else
        {
            v.push_back(arr[n % 3]);
            n /= 3;
        }
    }
    
    for (int i = v.size() - 1; i >= 0; i--)
        answer += to_string(v[i]);
    
    return answer;
}