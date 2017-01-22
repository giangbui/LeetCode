//Predict the Winner
//Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
//Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

//Solution
//Store the maximum score player1 can get for any sub array [i, j]

//DP formula:
//dp(i, j) = max(sum(i, j-1) - dp(i, j-1) + nums[j], sum(i+1, j) - dp(i+1, j) + nums[i])
