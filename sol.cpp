class Solution {
    private:
        int n, m, target;
           const int MOD = 1e9 + 7;
        vector<vector<int>> gridinput;
     
        vector<vector<unordered_map<int, int>>> dp;
    
        int solve(int i, int j, int xr) {
            if (i >= n || j >= m) return 0;
    
            xr ^= gridinput[i][j];
    
        
            if (i == n - 1 && j == m - 1) {
                return (xr == target) ? 1 : 0;
            }
    
            // Check memoization
            if (dp[i][j].count(xr)) return dp[i][j][xr];
    
            int count = 0;
             count = (count + solve(i + 1, j, xr)) % MOD; // Move down
            count = (count + solve(i, j + 1, xr)) % MOD; // Move right
    
            return dp[i][j][xr] = count;
        }
    
    public:
        int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
            gridinput = grid;
            n = grid.size();
            m = grid[0].size();
            target = k;
    
            dp = vector<vector<unordered_map<int, int>>>(n, vector<unordered_map<int, int>>(m));
            return solve(0, 0, 0);
        }
    };