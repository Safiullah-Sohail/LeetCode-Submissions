class Solution
{
    vector<int> countSort(vector<int> array)
    {
        int size = array.size();
        int max = *max_element(array.begin(),array.end());
        vector<int> output(size);
        vector<int> count(max + 1, 0);
        for (int i = 0; i < size; i++)
            count[array[i]]++;

        for (int i = 1; i <= max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }
        return output;
    }
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        deck = countSort(deck);
        int n = deck.size();
        queue<int> q;
        int i = 0;
        while (i < n)
            q.push(i++);
        vector<int> ans(n);
        for (i = 0; i < n; i++)
        {
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};