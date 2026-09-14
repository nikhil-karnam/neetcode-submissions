class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        //find lowest value that's greater than or equal to target.
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target){ //passed
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        if(low == nums.size() || nums[low] != target){
            return -1;
        }
        return low;
    }
};
