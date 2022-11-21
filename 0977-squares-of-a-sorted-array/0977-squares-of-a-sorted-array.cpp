class Solution
{
    void countingSort(vector<int> &array, int place)
    {
        const int max = 10;
        int size = array.size();
        vector<int> output(size);
        vector<int> count(max);

        for (int i = 0; i < max; i++)
            count[i] = 0;

        for (int i = 0; i < size; i++)
            count[(array[i] / place) % 10]++;

        for (int i = 1; i < max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[(array[i] / place) % 10] - 1] = array[i];
            count[(array[i] / place) % 10]--;
        }

        for (int i = 0; i < size; i++)
            array[i] = output[i];
    }

    void radixsort(vector<int> &array)
    {
        int max = *max_element(array.begin(),array.end());
        for (int place = 1; max / place > 0; place *= 10)
            countingSort(array, place);
    }

public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for(int i=0 ; i<nums.size() ; i++)
            nums[i] *= nums[i];
        radixsort(nums);
        return nums;
    }
};