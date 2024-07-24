class Solution {
public:
    int getMappedNum(int nums, vector<int> mapping){
        if(nums < 10) return mapping[nums];
        
        int mappedNum = 0;
        int placeValue = 1;
        
        while(nums){
            int lastDigit = nums%10;
            int mapDigit = mapping[lastDigit];
            mappedNum += mapDigit*placeValue;
            placeValue *= 10;
            nums /= 10;
        }
        return mappedNum;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        
        for(int i=0; i<n; i++){
            int mappedNum = getMappedNum(nums[i], mapping);
            vec.push_back({mappedNum, i});
        }
        sort(vec.begin(), vec.end());
        
        vector<int> result;
        for(auto &p : vec){
            int originalIndexNum = p.second;
            result.push_back(nums[originalIndexNum]);
        }
        return result;
    }
};