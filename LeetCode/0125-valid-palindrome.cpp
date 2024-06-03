#include <string>
using std::string;
// https://en.cppreference.com/w/cpp/string/basic_string

#include <cctype>
// https://en.cppreference.com/w/cpp/string/byte/isalpha
// https://en.cppreference.com/w/cpp/string/byte/isdigit
// https://en.cppreference.com/w/cpp/string/byte/tolower
// https://en.cppreference.com/w/cpp/string/byte/isalnum

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            while (!std::isalnum(s[left]) && left < right)
            {
                left++;
            }
            while (!std::isalnum(s[right]) && left < right) 
            {
                right--;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) 
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};