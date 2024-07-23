bool comparator(pair<int, int> a, pair<int, int> b){
        if(a.second < b.second){
            return true;
        }
        else if(a.second > b.second){
            return false;
        }
        else{
            return a.first >= b.first;
        }
    }

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> vp;
        for(auto it: mpp){
            vp.push_back({it.first, it.second});
        }
        sort(vp.begin(), vp.end(), comparator);
        vector<int> ans;
        for(auto it: vp){
            int val = it.first;
            int freq = it.second;
            while(freq--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};