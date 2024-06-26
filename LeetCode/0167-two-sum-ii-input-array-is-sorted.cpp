#include <vector>
using std::vector;
// https://en.cppreference.com/w/cpp/container/vector

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                break;
        }
        return { left + 1, right + 1 };
    }
};