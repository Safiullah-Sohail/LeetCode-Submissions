class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> errz;
        int n = 0;
        while (n < nums.size())
        {
            int temp = nums[n] - 1;
            if (nums[n] != nums[temp])
            {
                swap(nums[n], nums[temp]);
            }
            else
                n++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                errz.push_back(nums[i]);
                errz.push_back(i + 1);
            }
        }
        return errz;
    }
};