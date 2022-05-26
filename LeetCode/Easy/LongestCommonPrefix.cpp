class Solution {
public:
    string findCommonPrefix(string str1, string str2)
    {
        string ret = "";
        int minNum = min(str1.size(), str2.size());
        
        for (int i = 0; i < minNum; i++)
        {
            if (str1[i] == str2[i])
                ret += str1[i];
            else
                break;
        }
        
        return ret;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        
        for (int i = 1; i < strs.size(); i++)
        {
            answer = findCommonPrefix(answer, strs[i]);
            if (answer == "") break;
        }
        
        return answer;
    }
};