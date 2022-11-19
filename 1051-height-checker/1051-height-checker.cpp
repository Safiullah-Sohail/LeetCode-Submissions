class Solution
{
    vector<int> countSort(vector<int> array)
    {
        int size = array.size();
        vector<int> output(size);
        vector<int> count(size,0);
        int max = array[0];
        for (int i = 1; i < size; i++)
            if (array[i] > max)
                max = array[i];

        for (int i = 0; i < size; i++)
            count[array[i]]++;

        for (int i = 1; i <= max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }
        return output;
    }

public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sorted = heights;
        sort(sorted.begin(),sorted.end());
        int count = 0;
        for(int n=0 ; n<heights.size() ; n++)
            if(heights[n] != sorted[n])
                count++;
        return count;
    }
};