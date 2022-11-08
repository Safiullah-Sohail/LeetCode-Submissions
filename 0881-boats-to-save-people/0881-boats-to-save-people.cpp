class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        int st = 0, end = people.size()-1, boats = 0;
        while(st<=end) 
        {
            if(people[st] + people[end] <= limit) 
            {
                st++;
            }
            boats++;
            end--;
        }
        return boats;
    }
};