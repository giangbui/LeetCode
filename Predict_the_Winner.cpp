//Predict the Winner
//Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
//Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

//Solution
//Store the maximum score player1 can get for any sub array [i, j]

//DP formula:
//dp(i, j) = max(sum(i, j-1) - dp(i, j-1) + nums[j], sum(i+1, j) - dp(i+1, j) + nums[i])

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        vector<int> sums(n+1);
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            sums[i+1] = nums[i] + sums[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                int sum1 = sums[j+i] - sums[j] - dp[j][j+i-1] + nums[j+i];
                int sum2 = sums[j+i+1] - sums[j+1] - dp[j+1][j+i] + nums[j];
                dp[j][j+i] = max(sum1, sum2);
            }
        }
        return dp[0][n-1] >= sums[n] / 2 + sums[n] % 2;
    }
};
