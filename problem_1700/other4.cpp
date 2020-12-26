class Solution
{
public:
    int countStudents(vector<int> students, vector<int> sandwiches)
    {
        int cnt = 0;
        while (1)
        {
            if (students.size() == 0)
                return 0;
            else if (students[0] == sandwiches[0])
            {
                students.erase(students.begin(), students.begin() + 1);
                sandwiches.erase(sandwiches.begin(), sandwiches.begin() + 1);
                cnt = 0;
            }
            else
            {
                students.push_back(students[0]);
                students.erase(students.begin(), students.begin() + 1);
                cnt++;
                if (cnt == students.size())
                    break;
            }
        }
        return students.size();
    }
};
