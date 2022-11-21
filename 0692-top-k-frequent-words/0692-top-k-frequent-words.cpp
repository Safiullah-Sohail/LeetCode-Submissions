class Solution
{
public:
    static bool compare(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second == b.second)
        {
            return (a.first < b.first);
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        for (auto i : words)
        {
            freq[i]++;
        }
        vector<pair<string, int>> vecPair;
        for (auto i : freq)
        {
            vecPair.push_back({i.first, i.second});
        }
        sort(vecPair.begin(), vecPair.end(), compare);
        for(auto i: vecPair)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(vecPair[i].first);
        }
        return ans;
    }
};