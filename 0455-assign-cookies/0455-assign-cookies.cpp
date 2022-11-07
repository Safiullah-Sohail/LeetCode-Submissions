class Solution
{
    void sort(vector<int> &array) // insertion sort
    {
        for (int i = 1; i < array.size(); i++)
        {
            int key = array[i];
            int j;
            if(key < array[i-1])
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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g);
        sort(s);
        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};