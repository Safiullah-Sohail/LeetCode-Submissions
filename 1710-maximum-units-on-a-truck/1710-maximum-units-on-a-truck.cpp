class Solution
{
    void sort(vector<vector<int>> &array) // insertion sort
    {
        for (int i = 1; i < array.size(); i++)
        {
            int key = array[i][1];
            vector<int> temp = array[i];
            int j;
            if (key > array[i - 1][1])
            {
                for (j = i - 1; j >= 0; j--)
                {
                    array[j + 1] = array[j];
                    if (key < array[j][1])
                        break;
                }
                array[j + 1] = temp;
            }
        }
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes);
        int count = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (boxTypes[i][0] >= truckSize)
            {
                count += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            else
            {
                truckSize -= boxTypes[i][0];
                count += boxTypes[i][0] * boxTypes[i][1];
            }
        }
        return count;
    }
};