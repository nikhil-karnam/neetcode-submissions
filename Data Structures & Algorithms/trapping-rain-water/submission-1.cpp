class Solution {
public:
    int trap(vector<int>& height) {
        int collect = 0;

        int max_l = 0;
        int max_r = 0;

        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            max_l = std::max(max_l, height[l]);
            max_r = std::max(max_r, height[r]);
            /*for ls: we know the max seen on the left. unsure what's the max on
            the right. if what's seen on the left is shorter than what's seen so
            far on the right, what else is on the right will not matter at all
            anymore because we will always choose the one on the left as the rim.
            we can safely fill in that index l.*/
            if(max_l < max_r){
                collect += max_l - height[l];
                l++;
            }
            else{
                collect += max_r - height[r];
                r--;
            }
        }

        return collect;
    }
};
