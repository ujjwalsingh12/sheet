class Solution {
public:
    int steal(long long int choose, vector<int>& hval, vector<long long int>& maxsteal, long long int end) {
        if (choose >= end) {  // Modified stopping condition to handle subarrays
            return 0;
        }
        
        if (maxsteal[choose] != -1) {  // Memoization check
            return maxsteal[choose];
        }

        // Option 1: Skip this house and move to the next
        long long int a = steal(choose + 1, hval, maxsteal, end);

        // Option 2: Rob this house and skip the next one
        long long int b = hval[choose] + steal(choose + 2, hval, maxsteal, end);

        // Take the maximum of both options
        maxsteal[choose] = max(a, b);
        
        return maxsteal[choose];
    }

    long long int rob(vector<int>& nums) {
        if (nums.size() == 1) {  // Base case, if only one house, rob it
            return nums[0];
        }

        // Scenario 1: Rob from house 0 to n-2 (excluding the last house)
        vector<long long int> maxsteal1(nums.size(), -1);
        long long int case1 = steal(0, nums, maxsteal1, nums.size() - 1);

        // Scenario 2: Rob from house 1 to n-1 (excluding the first house)
        vector<long long int> maxsteal2(nums.size(), -1);
        long long int case2 = steal(1, nums, maxsteal2, nums.size());

        // Return the maximum of the two cases
        return max(case1, case2);
    }
};