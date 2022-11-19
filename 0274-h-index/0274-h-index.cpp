class Solution
{
    void countSort(vector<int> &array)
    {
        int size = array.size();
        int max = *max_element(array.begin(),array.end());
        vector<int> output(size);
        vector<int> count(max + 1, 0);
        for (int i = 0; i < size; i++)
            count[array[i]]++;

        for (int i = 1; i <= max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }
        for (int i=0 ; i<size ; i++)
            array[i] = output[size-1-i];
    }

public:
    int hIndex(vector<int> &citations)
    {
        int index;
        countSort(citations);
        int n = citations.size();
        int count = 0;
        for (index = 0; index<n ; index++)
        {
            cout<<citations[index]<<"\t"<<index<<endl;
            if(index >= citations[index])
                break;
        }
        return index;
    }
};