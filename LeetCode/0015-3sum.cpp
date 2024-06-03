#include <vector>
using std::vector;
// https://en.cppreference.com/w/cpp/container/vector

#include <algorithm>
// https://en.cppreference.com/w/cpp/algorithm/sort

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) continue;
            // proof by contradiction
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else
                {
                    res.push_back({ nums[i], nums[l] , nums[r] });
                    // nums[l] <= nums[l + 1], nums[r - 1] <= nums[r]
                    // if nums[l] == nums[l + 1]:
                    //    if nums[r - 1] == nums[r]:
                    //       nums[l + 1] + nums[r - 1] == nums[l] + nums[r], should skip
                    //    else if nums[r - 1] != nums[r]:
                    //       nums[l + 1] + nums[r - 1] != nums[l] + nums[r], should skip
                    l++;
                    r--;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                }
            }
        }
        return res;
    }
};