Given scores of N athletes, find their relative ranks and the men with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        auto cmp = [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first?true:false;};
        vector<pair<int,int>> myvecs;
        for(int i = 0; i< nums.size(); ++i )
            myvecs.push_back(make_pair(nums[i],i));
        
        sort(myvecs.begin(),myvecs.end(),cmp);
         vector<string> res(nums.size());
         for(int i = 0 ; i< myvecs.size() ; i++)
         {
             if (i ==0)
                res[myvecs[i].second] = "Gold Medal";
             else if(i==1) res[myvecs[i].second] = "Silver Medal";
             else if(i==2) res[myvecs[i].second] = "Bronze Medal";
             else
             res[myvecs[i].second] = to_string(i+1);
         }
         
         
         return res;
    }
};
