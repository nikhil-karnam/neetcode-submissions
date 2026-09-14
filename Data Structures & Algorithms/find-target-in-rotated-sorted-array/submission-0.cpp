class Solution {
public:
    int transform(int i, int shift, std::vector<int> nums){
        return (i + shift) % nums.size();
    }
    
    int search(vector<int>& nums, int target) {
        //first find where the sort has moved.
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] <= nums.back()){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        int shift = low;
        //normal binary search with bounds adjusted
        low = 0;
        high = nums.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[transform(mid, shift, nums)] >= target){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        if(nums[transform(low, shift, nums)] == target){
            return transform(low, shift, nums);
        }
        return -1;
    }
};
