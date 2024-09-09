```cpp
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
```
Let's break down the loop in the context of how the `dp` array is being updated and how the minimum path sum is being calculated for each cell in the grid:

### Setup

- `grid[i][j]` contains the value at cell \((i, j)\) in the grid.
- `dp[j]` represents the minimum path sum to reach the cell at column `j` in the current row (row `i`).

Initially, `dp` is filled with the minimum path sums for the first row, which means for the first row, you can only come from the left (since it's the first row).

The key idea in the loop is that to compute the minimum path sum at a cell \((i, j)\), you can either come from:

1. The cell directly above \((i-1, j)\) in the same column (move down).
2. The cell directly to the left \((i, j-1)\) in the same row (move right).

### Breakdown of the Code:

#### 1. Updating the First Column (`dp[0]`):
```cpp
dp[0] += grid[i][0]; // Update the first column for the current row
```

- In this step, you're updating the first column (`dp[0]`) for the current row `i`.
- Since there's no cell to the left in the first column, the only way to reach cell \((i, 0)\) is from the cell directly above it \((i-1, 0)\).
- Hence, you add the value of `grid[i][0]` to `dp[0]` (which already contains the minimum path sum to reach cell \((i-1, 0)\)).

This is the equivalent of calculating:
```cpp
dp[0] = dp[0] + grid[i][0]; // Just update with value from above
```

#### 2. Updating the Remaining Columns (`dp[j]` for `j > 0`):
```cpp
for (int j = 1; j < n; ++j) {
    dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
}
```

- For each column `j` (starting from the second column, `j=1`), you're calculating the minimum path sum to reach cell \((i, j)\).
- The two possible ways to get to this cell are:
  - From the cell directly above: \((i-1, j)\) → represented by the current value of `dp[j]` (because `dp[j]` holds the minimum path sum from the previous row).
  - From the cell to the left: \((i, j-1)\) → represented by `dp[j-1]` (since this has already been updated for the current row).
  
- You choose the smaller of these two values (whichever gives the least path sum) and add the value of the current cell (`grid[i][j]`) to it:
```cpp
dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
```

This step updates `dp[j]` to represent the minimum path sum to reach cell \((i, j)\).

### Example:

Let's take an example grid:

```
grid = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1]
]
```

- **Initialization**: After filling the first row:
  ```
  dp = [1, 4, 5]  // min path sums for the first row
  ```

Now let's go row by row:

- **Row 1** (`i = 1`):
  - First column (`j = 0`):
    ```cpp
    dp[0] = dp[0] + grid[1][0] = 1 + 1 = 2
    dp = [2, 4, 5]
    ```
  - Second column (`j = 1`):
    ```cpp
    dp[1] = grid[1][1] + min(dp[1], dp[0]) = 5 + min(4, 2) = 5 + 2 = 7
    dp = [2, 7, 5]
    ```
  - Third column (`j = 2`):
    ```cpp
    dp[2] = grid[1][2] + min(dp[2], dp[1]) = 1 + min(5, 7) = 1 + 5 = 6
    dp = [2, 7, 6]
    ```

- **Row 2** (`i = 2`):
  - First column (`j = 0`):
    ```cpp
    dp[0] = dp[0] + grid[2][0] = 2 + 4 = 6
    dp = [6, 7, 6]
    ```
  - Second column (`j = 1`):
    ```cpp
    dp[1] = grid[2][1] + min(dp[1], dp[0]) = 2 + min(7, 6) = 2 + 6 = 8
    dp = [6, 8, 6]
    ```
  - Third column (`j = 2`):
    ```cpp
    dp[2] = grid[2][2] + min(dp[2], dp[1]) = 1 + min(6, 8) = 1 + 6 = 7
    dp = [6, 8, 7]
    ```

At the end of the loop, the `dp` array contains the minimum path sums to reach the last row, and `dp[n-1]` (in this case `dp[2]`) gives the minimum path sum to reach the bottom-right corner, which is 7.

### Final Thoughts:

- The `dp` array is updated in place for each row, so after processing the last row, the array holds the minimum path sum for the last row, and the last element of `dp` gives the result.
- By doing this, you eliminate the need for a full 2D array, reducing space complexity from \(O(m \times n)\) to \(O(n)\).