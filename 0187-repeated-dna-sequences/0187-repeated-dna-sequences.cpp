class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> freqMap;
        for (int i = 0; i < s.size(); i++)
            freqMap[s.substr(i, 10)]++;

        vector<string> ans;
        for (auto i : freqMap)
        {
            if (i.second > 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};