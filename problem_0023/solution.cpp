/*
23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generateList() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int listsize = std::rand() % 100;
    vector<int> nums;
    for (int i = 0; i < listsize; ++i)
        nums.push_back(std::rand());
    sort(nums.begin(), nums.end());
    ListNode *head = NULL, *node, *tail;

    for(const auto& n: nums)
    {
        node = new ListNode(n);
        if (head == NULL)
            head = node;
        else
            tail->next = node;
        tail = node;
    }

    return head;
}

bool checkSorted(ListNode* node)
{
    while (node)
    {
        if (node->next && node->next->val < node->val)
            return false;
        node = node->next;
    }
    return true;
}

void printList(ListNode* node) {
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* head = NULL, *tail;
        multimap<int, int> lookup;

        int listsize = static_cast<int>(lists.size());
        for (int index = 0; index < listsize; ++index)
        {
            ListNode* node = lists[index];
            if (node)
                lookup.emplace(node->val, index);
        }

        while (lookup.size())
        {
            map<int,int>::iterator it = lookup.begin();
            int index = it->second;
            ListNode* node = lists[index];
            if (head == NULL)
                head = node;
            else
                tail->next = node;
            tail = node;
            lists[index] = node->next;
            if (node->next)
                lookup.emplace(node->next->val, index);
            lookup.erase(it);
        }

        return head;
    }
};

int main()
{
    Solution sol;
    vector<ListNode*> lists;
    int K;

    cout << "Input K: ";
    cin >> K;
    for (int k = 0; k < K; ++k)
        lists.push_back(generateList());
 
    ListNode* ret = sol.mergeKLists(lists);
    cout << "List is " << (checkSorted(ret) ? "sorted" : "not sorted") << endl;
    ListNode* node = ret;
    while (ret)
    {
        node = ret->next;
        delete ret;
        ret = node;
    }

    return 0;
}

