class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        //Using two pointers to preserving the previous node
        Node* prev = head;
        Node* next = head->next;
        //When prev->val > next->val, we find the max and min(prev and next respectively)
        //Case 1: insertVal is between the min and max
        //Case 2: insertVal is larger than max
        //Case 3: insertVal is smaller than min
        while(!(prev->val <= insertVal && insertVal <= next->val) &&
                !(prev->val > next->val && insertVal < next->val) &&
                !(prev->val > next->val && insertVal > prev->val)){
            prev = prev->next;
            next = next->next;
            if(next == head) break;
        }

        prev->next = new Node(insertVal, next);
        return head;
    }
};
