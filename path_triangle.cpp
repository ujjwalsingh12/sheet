//THIS IS SPACE COMPLEXITY IMPROVED
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(triangle.back()); // Initialize with the last row
        
        // Start from the second-last row and move upwards
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        // The minimum path sum will be stored at dp[0]
        return dp[0];
    }
};


//MY SOLUTION HAD MORE SPACE COMPLEXITY 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> tab0, tab1;
        tab0.push_back(triangle[0][0]);

        if (m == 1) { 
            return triangle[0][0]; 
        }
        
        // Calculate other paths
        for (int i = 1; i < m; i++) {
            tab1.clear();
            
            // First element in each row
            tab1.push_back(triangle[i][0] + tab0[0]);
            
            // Middle elements
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                tab1.push_back(triangle[i][j] + min(tab0[j-1], tab0[j]));
            }
            
            // Last element in each row
            tab1.push_back(triangle[i].back() + tab0.back());
            
            // Update tab0 with the new row's values
            tab0 = tab1;
        }
        
        // Return the minimum value from the last row
        return *min_element(tab0.begin(), tab0.end());
    }
};