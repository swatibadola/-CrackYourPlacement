class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            cnt += nums[end] - nums[start];
            start++;
            end--;
        }
        return cnt;
    }
};