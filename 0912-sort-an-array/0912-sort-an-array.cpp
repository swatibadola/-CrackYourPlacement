class Solution {
public:    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        
        for(int &num : nums){
            mpp[num]++;
        }
        
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        
        int i=0;
        for(int num = minElement; num <= maxElement; num++){
            while(mpp[num] > 0){
                nums[i] = num;
                i++;
                mpp[num]--;
            }
        }
        return nums;
    }
};