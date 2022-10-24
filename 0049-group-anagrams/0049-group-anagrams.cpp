class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> ansmap;
        for (string str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            ansmap[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto itr : ansmap)
            ans.push_back(itr.second);
        return ans;
    }
};