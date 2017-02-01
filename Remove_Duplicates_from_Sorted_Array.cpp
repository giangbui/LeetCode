//Remove Duplicates from Sorted Array   Add to List QuestionEditorial Solution

/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size() == 0) return nums.size();
       int first = 0;
       int last = 0;
       while (true){
           while (last < nums.size() -1 && nums[last+1] == nums[first])
            last++;                   
           if(last>=nums.size())
            break;
           if(last > first)
           {
               nums.erase(nums.begin() + first,nums.begin() + last);
           }
           first = first +1;
           last = first;
            
       }
       return nums.size();
    }
};
