class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lp = 0, rp = 1;
        while (rp < nums.size() && lp < rp)
        {
            if (nums[lp] == 0 && nums[rp] != 0)
            {
                int temp = nums[lp];
                nums[lp++] = nums[rp];
                nums[rp++] = temp;
            }
            else if (nums[lp] == 0 && nums[rp] == 0)
            {
                rp++;
            }
            else if (nums[lp] != 0)
            {
                lp++;
                rp++;
            }
            else
            {
                lp++;
            }
        }
    }
};