class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        for (int i = 1; i < heights.size(); i++)
        {
            int key = heights[i];
            string name = names[i];
            int j;
            for ( j=i-1; j>=0 ; j--)
            {
                heights[j + 1] = heights[j];
                names[j + 1] = names[j];
                if(key < heights[j])
                    break;
            }
            heights[j + 1] = key;
            names[j + 1] = name;
        }
        return names;
    }
};