class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<pair<int, int>> priQue;
        for (int i = 0; i < score.size(); i++)
        {
            priQue.push_back({score[i], i});
        }
        sort(priQue.rbegin(), priQue.rend());
        vector<string> answer(score.size());
        int n = score.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                answer[priQue[i].second] = "Gold Medal";
            }
            else if (i == 1)
            {
                answer[priQue[i].second] = "Silver Medal";
            }

            else if (i == 2)
            {
                answer[priQue[i].second] = "Bronze Medal";
            }
            else
            {
                answer[priQue[i].second] = to_string(i + 1);
            }
        }
        return answer;
    }
};