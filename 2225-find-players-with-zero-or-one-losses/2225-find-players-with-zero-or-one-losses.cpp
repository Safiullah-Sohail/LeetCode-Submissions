class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int> freq;
        vector<vector<int>> ans(2);
        for(int i=0 ; i<matches.size() ; i++)
        {
            freq[matches[i][0]];
            freq[matches[i][1]]++;
        }
        for(auto i:freq)
        {
            if(i.second == 0)
                ans[0].push_back(i.first);
            if(i.second == 1)
                ans[1].push_back(i.first);
        }
        return ans;
    }
};