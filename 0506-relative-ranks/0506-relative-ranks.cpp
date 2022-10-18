class priorityQueue
{
    vector<pair<int,int>> heapArr;
    int size;
public:
    priorityQueue()
    {
        size = 0;
    }
    int parentIndex(int i)
    {
        return (i - 1);
    }
    int leftChildIndex(int i)
    {
        return (2 * i) + 1;
    }
    int rightChildIndex(int i)
    {
        return (2 * i) + 2;
    }
    void swap(int a, int b)
    {
        pair<int,int> temp  = heapArr[a];
        heapArr[a] = heapArr[b];
        heapArr[b] = temp;
    }
    void siftUp(int index)
    {
        while (index > 0)
        {
            int pIdx = parentIndex(index);
            if (heapArr[index].first > heapArr[pIdx].first)
            {
                swap(index, pIdx);
                index = pIdx;
            }
            else
            {
                break;
            }
        }
    }

    void insert(pair<int,int> value)
    {
        heapArr.push_back(value);
        int index = size;
        size++;
        siftUp(index);
    }

    vector<pair<int,int>> getQueue()
    {
        return heapArr;
    }
};
class Solution
{
    priorityQueue q = priorityQueue();
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        for (int n = 0; n < score.size(); n++)
        {
            pair<int,int> t(score[n],n);
            q.insert(t);
        }
        vector<pair<int,int>> temp = q.getQueue();
        string medal = "";
        vector<string> answer(temp.size());
        for(int n = 0 ; n < temp.size() ; n++)
        {
            if(n == 0)
                medal = "Gold Medal";
            else if(n == 1)
                medal = "Silver Medal";
            else if(n == 2)
                medal = "Bronze Medal";
            else
                medal = to_string(n + 1);
            answer[temp[n].second] = medal;
        }
        return answer;
    }
};