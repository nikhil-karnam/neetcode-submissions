class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        std::vector<int> &a = nums1;
        std::vector<int> &b = nums2;

        int low = 0;
        int high = a.size();
        int len = a.size() + b.size();
        while(low < high){
            int mid = (low + high) / 2;
            //passed = second half, median = lowest passed
            if(a[mid] >= b[len/2 - mid - 1]){ 
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        if(len%2 == 0){
            if(a.empty()){
                return (b[len/2-1] + b[len/2]) / 2.0;
            }
            //all pass
            if(low == 0){
                if(b.size() == len/2){
                    return (b.back() + a.front()) / 2.0;
                }
                int left = b[len/2 - 1];
                int right = std::min(b[len/2], a.front());
                return (left + right) / 2.0;
            }
            //all fail
            if(low == a.size()){
                if(a.size() == len/2){
                    return (b.front() + a.back()) / 2.0;
                }
                int right = b[len/2 - a.size()];
                int left = std::max(a.back(), b[len/2 - a.size() - 1]);
                return (left + right)/2.0;
            }
            int right = std::min(a[low], b[len/2 - low]);
            int left = std::max(a[low-1], b[len/2 - low - 1]);
            return (left + right) / 2.0;
        }
        //odd length
        if(a.empty()){
            return b[len/2];
        }
        if(low==0){
            return std::min(b[len/2], a.front());
        }
        //all failed
        if(low == a.size()){
            return b[len/2 - a.size()];
        }
        return std::min(a[low], b[len/2 - low]);
    }
};
