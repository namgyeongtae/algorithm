class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v;
        int idx = 0;
        
        for (int i = 0; i < numRows; i++)
        {
            vector<char> v2;
            v.push_back(v2);
        }
        
        
        while (idx < s.size())
        {
            for (int i = 0; i < numRows; i++)
            {
                v[i].push_back(s[idx++]);
                if (idx >= s.size()) break;
            }
            
            if (idx >= s.size()) break;
        
            for (int i = numRows - 2; i > 0; i--)
            {
                v[i].push_back(s[idx++]);
                if (idx >= s.size()) break;
            }
        }
        
        string answer = "";
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                answer += v[i][j];
            }
        }

        return answer;
    }
};