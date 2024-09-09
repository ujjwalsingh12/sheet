/**
THING TO NOTE HERE IS HOW THE TAB IS INITIALISED 
SINCE IF THE START OF THE GRID HAD A OBSTACLE THERE WOULD BE NO PATH
AVAILABLE SO YOU NEED TO TAKE CARE OF THAT AS WELL
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //tab for storing path count
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> tab(m,vector<int>(n,0));
        //initializing the tab
        if(!obstacleGrid[0][0]) tab[0][0] = 1;
        for(int j=1;j<n;j++){
            if(!obstacleGrid[0][j])
            tab[0][j] = tab[0][j-1];
        }
        for(int i=1;i<m;i++){
            if(!obstacleGrid[i][0])
            tab[i][0] = tab[i-1][0];
        }
        //calculating other values
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!obstacleGrid[i][j]){
                    tab[i][j] = tab[i-1][j]+tab[i][j-1];
                }
            }
        }
        return tab[m-1][n-1];
    }
};