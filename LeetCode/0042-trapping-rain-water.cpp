#include <vector>
using std::vector;
// https://en.cppreference.com/w/cpp/container/vector

#include <algorithm>
// https://en.cppreference.com/w/cpp/algorithm/min
// https://en.cppreference.com/w/cpp/algorithm/max

class Solution {
public:
    // e.g.
    //    |
    // |__|_|__
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        while (l < r)
        {
            if (leftMax < rightMax)
            {
                l++;
                leftMax = std::max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else
            {
                r--;
                rightMax = std::max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};