class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < candyType.size(); i++)
            m[candyType[i]]++;
        int allowed = candyType.size() / 2;
        if (allowed >= m.size())
            return m.size();
        auto it = m.begin();
        int eaten = 0;
        while (it != m.end())
        {
            eaten++;
            if (eaten > allowed)
                break;
            it++;
        }
        return eaten - 1;
    }
};
