class Solution
{
public:
    vector<int> findErrorNums(vector<int> &a)
    {
        vector<int> ans;
        unordered_map<int, int> freqMap;
        sort(a.begin(), a.end());
        for (int i = 1; i <= a.size(); i++)
            freqMap[i] = 0;
        for (auto &it : a)
            freqMap[it]++;
        for (auto &it : freqMap)
        {
            if (it.second == 2)
            {
                ans.push_back(it.first);
                break;
            }
        }
        for (auto &it : freqMap)
        {
            if (it.second == 0)
            {
                ans.push_back(it.first);
                break;
            }
        }
        return ans;
    }
};