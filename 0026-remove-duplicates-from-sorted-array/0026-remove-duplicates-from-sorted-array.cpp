#include<vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //APPROACH 1
        int i = 0;
        
        int n = nums.size();
        for(int j=1; j<n; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;

    
        // APPROACH 2 
        // set<int> set;
        // int n = nums.size();
        //     for(int i=0; i<n; i++){
        //         set.insert(nums[i]);
        //     }
        //     int k = set.size();
        //     int j = 0;
        //     for(int x : set){
        //         nums[j++] = x;
        //     }
        // return k;
        

        // APPROACH 3
        // int k = 1;
        // sort(nums.begin(), nums.end());

        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i] != nums[i-1]){
        //         nums[k] = nums[i];
        //         k++;
        //     }
        // }
        // return k;
    }
}; 