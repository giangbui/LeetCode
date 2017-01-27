//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
//Return the sum of the three integers. You may assume that each input would have exactly one solution.

/*Solution
The first step, we sort the array. We iterate the index of  the smallest one, i, from 0 to size of array - 2. The index of the second
number starts at i + 1 and the last one start at the end of the array. At every step, we update the closest distance of 3sum and the targe.
Base on the sign of the distance, we decide to update the index of the second and the third numbers
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
