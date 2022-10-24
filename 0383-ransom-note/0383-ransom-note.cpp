class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> freqMap;
        for (int i = 0; i < magazine.length(); i++)
        {
            freqMap[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (freqMap[ransomNote[i]] > 0)
                freqMap[ransomNote[i]]--;
            else
                return false;
        }
        return true;
    }
};