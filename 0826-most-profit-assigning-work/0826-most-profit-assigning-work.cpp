class Solution
{
    void sort(vector<pair<int, int>> &vec) // insertion sort
    {
        for (int i = 1; i < vec.size(); i++)
        {
            int key = vec[i].first;
            pair<int, int> temp = vec[i];
            int j;
            if (key < vec[i - 1].first)
            {
                for (j = i - 1; j >= 0; j--)
                {
                    vec[j + 1] = vec[j];
                    if (key > vec[j].first)
                        break;
                }
                vec[j + 1] = temp;
            }
        }
    }
    void sort(vector<int> &array) // insertion sort
    {
        for (int i = 1; i < array.size(); i++)
        {
            int key = array[i];
            int j;
            if (key < array[i - 1])
            {
                for (j = i - 1; j >= 0; j--)
                {
                    array[j + 1] = array[j];
                    if (key > array[j])
                        break;
                }
                array[j + 1] = key;
            }
        }
    }

public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); i++)
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        sort(jobs);
        sort(worker);
        int maxProfit = 0,curProf = 0,curJob = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            while (curJob < difficulty.size() && jobs[curJob].first <= worker[i])
            {
                curProf = max(curProf, jobs[curJob].second);
                curJob++;
            }
            maxProfit += curProf;
        }
        return maxProfit;
    }
};