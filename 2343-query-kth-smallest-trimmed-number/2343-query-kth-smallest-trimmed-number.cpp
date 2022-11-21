class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int small = queries[i][0];
            int trim = queries[i][1];
            priority_queue<pair<string, int>> pairQ;
            for (int j = 0; j < nums.size(); j++)
            {
                pairQ.push({nums[j].substr(nums[j].size() - trim, trim), j});
                if (pairQ.size() > small)
                    pairQ.pop();
            }
            ans.push_back(pairQ.top().second);
        }
        return ans;
    }
};