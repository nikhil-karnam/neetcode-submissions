class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        std::vector<int> &a = nums1;
        std::vector<int> &b = nums2;

        /*given an element in A, we know how many are below it. we the median length. we
        know ow many in B are needed to make up median length. are those truly below the
        element A? if so, there's enough below A to make up the median length, so A is in
        the second hlaf. find the lowest A that's in the second half. we know explicitly how
        many As are in the first half because all below that A failed to be in the second
        half. therefore we know how many Bs are in the firsthalf: median length - how many
        first half As. we know the composition of the first half from each array. the first
        element of the second half can either be the next index in A or next in B. find teh
        lowest of those 2.*/
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
