class Solution
{
    int max_element(vector<pair<int, char>> vec)
    {
        int max = vec[0].first;
        for(int n=0 ; n<vec.size() ; n++)
            if(vec[n].first > max)
                max = vec[n].first;
        return max;
    }
    vector<pair<int, char>> countSort(vector<pair<int, char>> array)
    {
        int size = array.size();
        int max = max_element(array);
        vector<pair<int, char>> output(size);
        vector<int> count(max + 1, 0);
        for (int i = 0; i < size; i++)
            count[array[i].first]++;

        for (int i = 1; i <= max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[array[i].first] - 1] = array[i];
            count[array[i].first]--;
        }
        return output;
    }
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> vecPair;
        unordered_map<char, int> freq;
        for (auto i : s)
        {
            freq[i]++;
        }
        for (auto i : freq)
        {
            vecPair.push_back(make_pair(i.second, i.first));
        }
        sort(vecPair.begin(), vecPair.end());
        string ans = "";
        for (auto i : vecPair)
        {
            char k = i.second;
            while (i.first != 0)
            {
                ans += k;
                i.first--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};