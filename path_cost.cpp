//MY SOLUTION
// ##64L
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //dividing the problem into paths which
        //can lead to some a,b in least cost
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> tab(m,vector<int>(n,0));
        //initialize
        tab[0][0] = grid[0][0];
        for(int i=1;i<m;i++) tab[i][0] = grid[i][0] + tab[i-1][0];
        for(int i=1;i<n;i++) tab[0][i] = grid[0][i] + tab[0][i-1];
        //calculate
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                tab[i][j] = grid[i][j] + min(tab[i-1][j],tab[i][j-1]);
            }
        }
        return tab[m-1][n-1];
    }
};

//this is SPACE OPTIMIZED SOLUTION FOR IT
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0); // 1D array to store current row's minimum path sums

        dp[0] = grid[0][0];
        
        // Initialize the first row
        for (int i = 1; i < n; ++i) {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        
        // Calculate the minimum path sums for each row
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0]; // Update the first column for the current row
            for (int j = 1; j < n; ++j) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        
        return dp[n - 1]; // The last element contains the result
    }
};