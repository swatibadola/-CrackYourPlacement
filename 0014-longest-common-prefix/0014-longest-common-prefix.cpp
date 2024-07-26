class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        // sort
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs.back();
        
        int n = first.length();
        
        int i=0;
        while(i < n && first[i] == last[i]){
            i++;
        }
        return first.substr(0, i);
    }
};