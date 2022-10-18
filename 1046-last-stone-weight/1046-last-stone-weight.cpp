class priorityQueue
{
    vector<int> heapArr;
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
    void swap(int a, int b)
    {
        int temp = heapArr[a];
        heapArr[a] = heapArr[b];
        heapArr[b] = temp;
    }
    void siftUp(int index)
    {
        while (index > 0)
        {
            int pIdx = parentIndex(index);
            if (heapArr[index] > heapArr[pIdx])
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
    void insert(int value)
    {
        heapArr.push_back(value);
        int index = size;
        size++;
        siftUp(index);
    }
    vector<int> getQueue()
    {
        return heapArr;
    }
    int length()
    {
        return heapArr.size();
    }
    int pop()
    {
        if(heapArr.size()>0)
        {
            int temp = heapArr[0];
            heapArr.erase(heapArr.begin());
            size--;
            return temp;
        }
        return -1;
    }
};
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priorityQueue q;
        int num1, num2;
        for (int n=0 ; n<stones.size() ; n++)
            q.insert(stones[n]);
        while (q.length() != 1)
        {
            num2 = q.pop();
            num1 = q.pop();
            q.insert(num2 - num1);
        }
        return q.pop();
    }
};