/*
Algorithm
- Iterate LinkedList from left to right
- Process each accumulative value in this datastructure. (unordered_map<int,ListNode*>um) um[ac] = currentNode;
- Given a current accumulative value check if exists in our map (get previous element).
- If they exist um[ac]->next = currentNode->next, then delete intermediate nodes in our map between um[ac] and
currentNode
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {

        ListNode* root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode*> um;
        um[0] = root;
        int ac = 0;

        while (head != NULL) {
            ac += head->val;

            // found value
            if (um.find(ac) != um.end()) {
                ListNode* prev = um[ac];
                ListNode* start = prev;

                // delete bad references
                int aux = ac;
                while (prev != head) {
                    prev = prev->next;
                    aux += prev->val;
                    if (prev != head)
                        um.erase(aux);
                }

                start->next = head->next;
            } else {
                um[ac] = head;
            }

            head = head->next;
        }

        return root->next;
    }
};
