class Solution
{
    vector<vector<int>> countSort(vector<vector<int>> array)
    {
        int size = array.size();
        int max = array[0][2];
        for(int n=0 ; n<array.size() ; n++)
            if(array[n][2] > max)
                max = array[n][2];
        vector<vector<int>> output(size);
        vector<int> count(max + 1, 0);
        for (int i = 0; i < size; i++)
            count[array[i][2]]++;

        for (int i = 1; i <= max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[array[i][2]] - 1] = array[i];
            count[array[i][2]]--;
        }
        return output;
    }
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int diff = abs(rCenter - i) + abs(cCenter - j);
                ans.push_back({i, j, diff});
            }
        }
        ans = countSort(ans);
        for (vector<int> &curr : ans)
        {
            curr.pop_back();
        }
        return ans;
    }
};