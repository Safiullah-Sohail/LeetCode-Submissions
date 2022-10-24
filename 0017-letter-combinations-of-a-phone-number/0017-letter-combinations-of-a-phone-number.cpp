class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> keyMap;
        keyMap['2'] = "abc";
        keyMap['3'] = "def";
        keyMap['4'] = "ghi";
        keyMap['5'] = "jkl";
        keyMap['6'] = "mno";
        keyMap['7'] = "pqrs";
        keyMap['8'] = "tuv";
        keyMap['9'] = "wxyz";
        int size = digits.size(), i = 0;
        vector<string> ans;
        string one = keyMap[digits[i]];
        for (int j = 0; j < one.size(); j++)
        {
            string temp = "";
            temp.push_back(one[j]);
            if (i + 1 < size)
            {
                string two = keyMap[digits[i + 1]];
                for (int k = 0; k < two.size(); k++)
                {
                    string temp2 = temp;
                    temp2.push_back(two[k]);
                    if (i + 2 < size)
                    {
                        string three = keyMap[digits[i + 2]];
                        for (int l = 0; l < three.size(); l++)
                        {
                            string temp3 = temp2;
                            temp3.push_back(three[l]);
                            if (i + 3 < size)
                            {
                                string four = keyMap[digits[i + 3]];
                                for (int m = 0; m < four.size(); m++)
                                {
                                    string temp4 = temp3;
                                    temp4.push_back(four[m]);
                                    ans.push_back(temp4);
                                }
                            }
                            else
                                ans.push_back(temp3);
                        }
                    }
                    else
                        ans.push_back(temp2);
                }
            }
            else
                ans.push_back(temp);
        }
        return ans;
    }
};