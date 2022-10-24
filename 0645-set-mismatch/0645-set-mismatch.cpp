class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = 0;
        while(n<nums.size())
        {
            int correct = nums[n]-1;
            if( nums[n]!=nums[correct])
            {
                swap(nums[n],nums[correct]);
            }
            else
            {
                n++;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1 )
            {
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};