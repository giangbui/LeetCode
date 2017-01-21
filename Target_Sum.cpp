/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.
Note:
    -The length of the given array is positive and will not exceed 20.
    -The sum of elements in the given array will not exceed 1000.
    -Your output answer is guaranteed to be fitted in a 32-bit integer.

Solution: Dynamic programming
Denote F[i,m] is the number of +/- assigments for the first i elements in the array so that the 
sum + f(a1,a2,...,ai) = sum +S
where f(.) is a linear combination of a1,a2,...ai for each +/- assignment
F[i,m] = F[i-1,m-a[i]] + F[i-1,m+a[i]];

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int N = nums.size();
        
        int sum = 0;        
        for(int i = 0;i <N; i++)
            sum = sum + nums[i];
            
        if(sum <abs(S))
            return 0;
        int F[20][4001];
        for (int i = 0; i<20; i++){
            for (int j = 0; j<4001; j++)
            F[i][j] = 0;
        }
        F[0][sum + nums[0]] = 1;
        F[0][sum - nums[0]] = 1;
        if(nums[0] ==0) F[0][sum+nums[0]] = 2;
        
        for(int i=1; i<N;i++){
            for(int j = 0; j<=2*sum;j++){                
                F[i][j] =s1+ (j>=nums[i]?F[i-1][j - nums[i]]:0);
            }
        }        
        return F[N-1][S+sum];
    }
};
