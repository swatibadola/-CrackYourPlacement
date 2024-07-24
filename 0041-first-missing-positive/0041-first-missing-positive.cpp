class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                // swap(nums[chair], nums[i]);
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(i+1 != nums[i]) return i+1;
        }
        return n+1; // for case nums = [1, 2, 3, 4, 5]
    }
};