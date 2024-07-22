class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pair;
        int n = names.size();
        for(int i=0; i<n; ++i){
            pair.push_back({heights[i], names[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<string> res;
        for(const auto& person:pair){
            res.push_back(person.second);
        }
        return res;
    }
};