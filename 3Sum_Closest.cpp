//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
//Return the sum of the three integers. You may assume that each input would have exactly one solution.

/*Solution
The first step, we sort the array to reduce the search space. We can assume that the three elements we are looking for has the increasing order. We allow the first element loop through the array from the 0-index position, we are looking for the two remain elements whose sum is equal to complement of the first element. To find those two elements, we start from the both sides of the sub-array, we check how far of the two sum to the target complement and update the result if it is, so far, the smallest. 
*/

class Solution {
public:
    static int compare (const void * a, const void * b)
    {
      return ( *(int*)a - *(int*)b );
    }

    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==0)
        return 0;
        int numSize = nums.size();
        qsort(&nums[0], numSize, sizeof(int), compare);
        int min_dst = INT_MAX;
        for(auto i=0;i<nums.size()-2;++i)
        {
            int new_target = target - nums[i];
            int first = i + 1;
            int last = nums.size()-1;
            
            
            while(first<last)
            {
                if(nums[first]+ nums[last] == new_target)
                {
                    return target;
                }
                if(std::abs(nums[first]+ nums[last] - new_target) < std::abs(min_dst))
                {
                    min_dst = nums[first]+ nums[last] - new_target;
                }
                if(nums[first]+ nums[last] - new_target <0)
                first++;
                else last--;
            }
 
            
        }
        
        return target+min_dst;
        
    }
    
};
