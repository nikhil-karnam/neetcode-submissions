class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::deque<int> q;
        int low = 0;
        int high = arr.size();
        while(low < high){
            int mid = (low + high) / 2;
            if(arr[mid] >= x){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        int right = low;
        int left = low - 1;
        while(q.size() != k){
            if(left == -1 || right != arr.size() && arr[right]-x < x-arr[left]){
                q.push_back(arr[right]);
                right++;
            }
            else{
                q.push_front(arr[left]);
                left--;
            }
        }

        std::vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop_front();
        }
        return res;
    }
};