
class Solution {
public:
    int getPivot(vector<int>& nums, int n){
        int start = 0, end = n - 1;
        int mid = start + (end - start)/2;

        while(start < end){
            if(nums[mid] > nums[n-1]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return end;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target){
        int start = s;
        int end = e;
        int mid = s + (e - s)/2;

        while(s <= e){
            if(nums[mid] == target){
                return mid;
            }
            if(target > nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e - s)/2;
        }
        return -1;
    }


    int search(vector<int>& nums,int target) {
        int n = nums.size();
        int pivot = getPivot(nums, n);

        if(target >= nums[pivot] && target <= nums[n - 1]){
            return binarySearch(nums, pivot, n - 1, target);
        }
        else{
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};