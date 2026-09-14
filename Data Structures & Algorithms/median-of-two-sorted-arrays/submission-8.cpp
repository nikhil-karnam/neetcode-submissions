class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> picks;
        int len = nums1.size() + nums2.size();
        int i = 0;
        int j = 0;
        while(picks.size() <= len / 2){
            if(j == nums2.size() || i < nums1.size() && nums1[i] < nums2[j]){
                picks.push_back(nums1[i]);
                i++;
            }
            else{
                picks.push_back(nums2[j]);
                j++;
            }
        }

        if(len % 2 == 0){
            return (picks.back() + *(picks.end() - 2)) / 2.0;
        }
        return picks.back();
    }
};
