class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        if (arr.empty() || n == 0) return 0;
        
        int m = arr[0].size(); // Number of activities
        vector<vector<int>> tab(n, vector<int>(m, 0));
        
        // Initialize the first day's activities
        for (int j = 0; j < m; ++j) {
            tab[0][j] = arr[0][j];
        }
        
        // Fill the DP table
        for (int i = 1; i < n; ++i) { // Iterate through days
            for (int j = 0; j < m; ++j) { // Iterate through current day's activities
                tab[i][j] = 0; // Initialize the current cell
                for (int k = 0; k < m; ++k) { // Check previous day's activities
                    if (k != j) { // Ensure different activity on consecutive days
                        tab[i][j] = max(tab[i][j], tab[i - 1][k] + arr[i][j]);
                    }
                }
            }
        }
        
        // Compute the maximum points on the last day
        int maxPoints = 0;
        for (int j = 0; j < m; ++j) {
            maxPoints = max(maxPoints, tab[n - 1][j]);
        }
        
        return maxPoints;
    }
};