class Solution
{
    void sort(vector<int> &array) // bubble
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < array.size(); j++)
            {
                if (array[i] < array[j])
                {
                    swap(array[i],array[j]);
                }
            }
        }
    }

public:
    double average(vector<int> &salary)
    {
        sort(salary);
        double sum = 0;
        for(int i=1 ; i<salary.size()-1 ; i++)
            sum = sum + salary[i];
        return sum/(salary.size()-2);
    }
};