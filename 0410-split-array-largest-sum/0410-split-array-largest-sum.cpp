class Solution {
public:
    int countSubArrays(vector<int>& nums, int elements){
        int noOfSubArrays = 1;
        int n = nums.size();
        long long elementsInSubarrays = 0;
        for(int i=0; i<n; i++){
            if(elementsInSubarrays + nums[i] <= elements){
            elementsInSubarrays += nums[i];
            }
            else{
                noOfSubArrays += 1;
                elementsInSubarrays = nums[i];
            }
        }
        return noOfSubArrays;
    }
    
    int max_element(vector<int>& nums, int n){
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    
    int findElements(vector<int>& nums, int n, int k){
        if(k>n) return -1;
        int low = max_element(nums, n);
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int noOfSubArrays = countSubArrays(nums, mid);
            if(noOfSubArrays > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findElements(nums, nums.size(), k);
    }
};