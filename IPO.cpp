
/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.
*/
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto cmpProfit = [](pair<int, int> & a, pair<int, int> & b) {return a.first > b.first;};
        auto cmpCapital = [](pair<int, int> & a, pair<int, int> & b) {return a.first < b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmpProfit)> doable(cmpProfit);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmpProfit)> remain(cmpProfit);
        int N = Profits.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (Capital[i] <= W)
                doable.push(pair<int, int>(Profits[i], i));
            else
                remain.push(pair<int, int>(Capital[i], i));
        }
        while (k > 0 && !doable.empty()) {
            pair<int, int> u = doable.top(); doable.pop();
            ans += u.first;
            --k;
            while (!remain.empty() && remain.top().first <= ans) {
                pair<int, int> v = remain.top(); remain.pop();
                doable.push(pair<int, int>(Profits[v.second], v.second));
            }
        }
        return ans;
    }
};
