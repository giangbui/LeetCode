//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
//Return the sum of the three integers. You may assume that each input would have exactly one solution.

/*Solution
The first step, we sort the array. Keep the first one and the last one, we do binary search the second one so that the sum of three is closet
//to the target.
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
