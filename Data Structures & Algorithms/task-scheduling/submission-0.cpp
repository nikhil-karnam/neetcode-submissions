#include <array>
#include <algorithm>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 26> counts{};
        for(auto i : tasks){
            counts[i-'A']++;
        }

        int max_count = *std::max_element(counts.begin(), counts.end());
        int max_frequency = std::count(counts.begin(), counts.end(), max_count);

        return std::max(int(tasks.size()), (max_count - 1) * (n + 1) + max_frequency);
    }
};
