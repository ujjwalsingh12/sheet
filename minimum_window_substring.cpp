#include <iostream>
#include <string>
#include <vector>
//IMPORTANT
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;            // when the count has already become zero and it comes back here .. it will only remove
                                    // the solution where bottom part has increased hence effectively only remvoing the required element
            }

            while (count == 0) {  // here while is needed for the map start++ line so that it keeps moving forward till it reaches a matching
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++; // so this is making the map to add the letter which is at next start 
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

int main() {
    Solution solution;

    // Test cases
    std::string s1 = "ADOBECODEBANC";
    std::string t1 = "ABC";

    std::string s2 = "a";
    std::string t2 = "a";

    std::string s3 = "a";
    std::string t3 = "aa";

    // Output results for each test case
    std::cout << "Test 1 - s: " << s1 << ", t: " << t1 << std::endl;
    std::cout << "Minimum window substring: " << solution.minWindow(s1, t1) << std::endl;

    std::cout << "\nTest 2 - s: " << s2 << ", t: " << t2 << std::endl;
    std::cout << "Minimum window substring: " << solution.minWindow(s2, t2) << std::endl;

    std::cout << "\nTest 3 - s: " << s3 << ", t: " << t3 << std::endl;
    std::cout << "Minimum window substring: " << solution.minWindow(s3, t3) << std::endl;

    return 0;
}