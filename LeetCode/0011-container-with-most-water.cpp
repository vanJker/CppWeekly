#include <vector>
using std::vector;
// https://en.cppreference.com/w/cpp/container/vector

#include <algorithm>
// https://en.cppreference.com/w/cpp/algorithm/min
// https://en.cppreference.com/w/cpp/algorithm/max

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int area = (right - left) * std::min(height[left], height[right]);
            res = std::max(res, area);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return res;
    }
};