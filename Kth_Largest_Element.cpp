//Kth Largest Element 
//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//Solution: Using max_priority_queue give us the linear complexity. 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();
    }
}; 
