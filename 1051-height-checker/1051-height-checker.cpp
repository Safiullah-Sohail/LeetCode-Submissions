class Solution
{
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