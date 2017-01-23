/* Product of Array Except Self
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].

Solution: dynamic programing. 
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[1];dp[1] = nums[0]; 
        for(int i = 2; i< nums.size(); i++){
            int nextNum = 1;
            for(int j=0; j <i; j++)
            {
                dp[j] = dp[j]*nums[i];
                nextNum = nextNum*nums[j];
            }
            dp[i] = nextNum;
        }
        return dp;
    }
};
