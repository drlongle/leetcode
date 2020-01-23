/*
1206. Design Skiplist
Hard

Design a Skiplist without using any built-in libraries.

A Skiplist is a data structure that takes O(log(n)) time to add, erase and search. Comparing with treap and red-black tree which has the same function and performance, the code length of Skiplist can be comparatively short and the idea behind Skiplists are just simple linked lists.

For example: we have a Skiplist containing [30,40,50,60,70,90] and we want to add 80 and 45 into it. The Skiplist works this way:

You can see there are many layers in the Skiplist. Each layer is a sorted linked list. With the help of the top layers, add , erase and search can be faster than O(n). It can be proven that the average time complexity for each operation is O(log(n)) and space complexity is O(n).

To be specific, your design should include these functions:

bool search(int target) : Return whether the target exists in the Skiplist or not.
void add(int num): Insert a value into the SkipList. 
bool erase(int num): Remove a value in the Skiplist. If num does not exist in the Skiplist, do nothing and return false. If there exists multiple num values, removing any one of them is fine.
See more about Skiplist : https://en.wikipedia.org/wiki/Skip_list

Note that duplicates may exist in the Skiplist, your code needs to handle this situation. 

Example:

Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // return false.
skiplist.add(4);
skiplist.search(1);   // return true.
skiplist.erase(0);    // return false, 0 is not in skiplist.
skiplist.erase(1);    // return true.
skiplist.search(1);   // return false, 1 has already been erased.

Constraints:

0 <= num, target <= 20000
At most 50000 calls will be made to search, add, and erase.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */


/*
https://www.geeksforgeeks.org/skip-list/
https://www.geeksforgeeks.org/skip-list-set-2-insertion/
https://www.geeksforgeeks.org/skip-list-set-3-searching-deletion/
 */

class Skiplist {
public:

    struct Node {
        Node(int v, int level): forward(level+1, nullptr), val(v) {}
        vector<Node*> forward; 
        int val;
    };

    Skiplist(): max_level(5), level(0), prob(0.5), header(new Node(numeric_limits<int>::min(), max_level)) { }

    ~Skiplist() {
        Node *current = header;
        while (current) {
            auto next = current->forward[0];
            delete current;
            current = next;
        }
    }
    
    int max_level;
    int level;
    double prob;
    Node *header;

    int randomLevel() {
        float r = (float) rand()/RAND_MAX;
        int lvl = 0;
        while (r < prob && lvl < max_level) {
            lvl++;
            r = (float)rand()/RAND_MAX;
        }
        return lvl;
    };
    
    bool search(int target) {
        Node *current = header;
  
        /*    start from highest level of skip list
              move the current pointer forward while key
              is greater than key of node next to current
              Otherwise inserted current in update and
              move one level down and continue search
        */
        for(int i = level; i >= 0; i--) {
            while(current->forward[i] && current->forward[i]->val < target)
                current = current->forward[i];
        }
  
        /* reached level 0 and advance pointer to
           right, which is possibly our desired node*/
        current = current->forward[0];
  
        // If current node have key equal to
        // search key, we have found our target node
        if(current && current->val == target) {
            return true;
        } else
            return false;
    }
    
    void add(int num) {
        Node *current = header;
  
        // create update array and initialize it
        vector<Node*> update(max_level+1, nullptr);
  
        /*    start from highest level of skip list
              move the current pointer forward while key
              is greater than key of node next to current
              Otherwise inserted current in update and
              move one level down and continue search
        */
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->val < num)
                current = current->forward[i];
            update[i] = current;
        }
  
        /* reached level 0 and forward pointer to
           right, which is desired position to
           insert key.
        */
        current = current->forward[0];
  
        /* if current is NULL that means we have reached
           to end of the level or current's key is not equal
           to key to insert that means we have to insert
           node between update[0] and current node */

        // Generate a random level for node
        int rlevel = randomLevel();
  
        // If random level is greater than list's current
        // level (node with highest level inserted in
        // list so far), initialize update value with pointer
        // to header for further use
        if (rlevel > level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = header;
  
            // Update the list current level
            level = rlevel;
        }
  
        // create new node with random level generated
        Node* n = new Node(num, rlevel);
  
        // insert node by rearranging pointers
        for (int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
    
    bool erase(int num) {
        Node *current = header;
  
        // create update array and initialize it
        vector<Node*> update(max_level+1, nullptr);
  
        /*    start from highest level of skip list
              move the current pointer forward while key
              is greater than key of node next to current
              Otherwise inserted current in update and
              move one level down and continue search
        */
        for(int i = level; i >= 0; i--)
        {
            while(current->forward[i] != nullptr && current->forward[i]->val < num)
                current = current->forward[i];
            update[i] = current;
        }
  
        /* reached level 0 and forward pointer to
           right, which is possibly our desired node.*/
        current = current->forward[0];
  
        // If current node is target node
        if(current != nullptr && current->val == num)
        {
            /* start from lowest level and rearrange
               pointers just like we do in singly linked list
               to remove target node */
            for(int i=0; i <= level; i++)
            {
                /* If at level i, next node is not target
                   node, break the loop, no need to move
                   further level */
                if(update[i]->forward[i] != current)
                    break;
                update[i]->forward[i] = current->forward[i];
            }
  
            // Remove levels having no elements
            while (level>0 && header->forward[level] == 0)
                level--;
            delete current;
            
            return true;
        } else
            return false;
    }

    void display()
    {
        cout<<"\n*****Skip List*****"<<"\n";
        for (int i=0;i<=level;i++)
        {
            Node *node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != NULL)
            {
                cout << node->val<<" ";
                node = node->forward[i];
            }
            cout << "\n";
        }
    }
};

void test_8() {
    vector<string> ops;
    vector<vector<int>> args;
    vector<bool> result;
    
    ops = {"Skiplist","add","add","add","add","add","add","add","add","add","erase","search","add","erase","erase","erase","add","search","search","search","erase","search","add","add","add","erase","search","add","search","erase","search","search","erase","erase","add","erase","search","erase","erase","search","add","add","erase","erase","erase","add","erase","add","erase","erase","add","add","add","search","search","add","erase","search","add","add","search","add","search","erase","erase","search","search","erase","search","add","erase","search","erase","search","erase","erase","search","search","add","add","add","add","search","search","search","search","search","search","search","search","search"};
    
    args = {{},{16},{5},{14},{13},{0},{3},{12},{9},{12},{3},{6},{7},{0},{1},{10},{5},{12},{7},{16},{7},{0},{9},{16},{3},{2},{17},{2},{17},{0},{9},{14},{1},{6},{1},{16},{9},{10},{9},{2},{3},{16},{15},{12},{7},{4},{3},{2},{1},{14},{13},{12},{3},{6},{17},{2},{3},{14},{11},{0},{13},{2},{1},{10},{17},{0},{5},{8},{9},{8},{11},{10},{11},{10},{9},{8},{15},{14},{1},{6},{17},{16},{13},{4},{5},{4},{17},{16},{7},{14},{1}};
    result = {0,0,0,0,0,0,0,0,0,0,true,false,0,true,false,false,0,true,true,true,true,false,0,0,0,false,false,0,false,false,true,true,false,false,0,true,true,false,true,true,0,0,false,true,false,0,true,0,true,true,0,0,0,false,false,0,true,false,0,0,true,0,false,false,false,true,true,false,true,0,true,false,false,false,true,true,false,false,0,0,0,0,true,true,true,true,true,true,false,false,true};

    Skiplist skl;
    int sz = ops.size();
    for (int i = 1; i < sz; ++i) {
        string& op = ops[i];
        bool res;

        //if (args[i][0] == 9)
        //    skl.display();
        
        if (op == "add")
            skl.add(args[i][0]);
        else if (op == "search")
            res = skl.search(args[i][0]);
        else if (op == "erase")
            res = skl.erase(args[i][0]);
        
        if (res != result[i] && (op == "search" || op == "erase"))
        //if (args[i][0] == 9)
            cout << i << ", op: " << op << ", arg: " << args[i][0] << ", result: " << result[i] << endl;

        //if (args[i][0] == 9)
        //    skl.display();
    }
    
    cout << "Test 8 completed!" << endl;
}

int main() {
    
    test_8();
    
    return 0;
}
