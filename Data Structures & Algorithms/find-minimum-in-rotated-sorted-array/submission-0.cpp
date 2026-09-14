class Solution {
public:
    int findMin(vector<int> &nums) {
        //try to arrange it into a pass / fail format
        //find the first value where it's <= than the last index
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid = (high + low) / 2;
            if(nums[mid] <= nums.back()){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        //edge case for where no pass is found
        if(nums.back() > nums[0]){
            return nums[0];
        }
        return nums[low];
    }
};
