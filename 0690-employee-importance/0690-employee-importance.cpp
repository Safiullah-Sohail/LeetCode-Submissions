/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int tlImp = 0;
    unordered_map<int, Employee *> map;
    void checkEmployee(int idx)
    {
        tlImp += map[idx]->importance;
        for (int x : map[idx]->subordinates)
            checkEmployee(x);
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto x : employees)
            map[x->id] = x;
        checkEmployee(id);
        return tlImp;
    }
};