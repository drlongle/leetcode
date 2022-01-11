class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head -> next = head;
            return head;
        }
        Node *temp = head;
        while (temp -> next != head) {
            int next = temp -> next -> val;
            int curr = temp -> val;
            // If node should be between two nodes.
            // Or, it has reached end.
            if ((next > insertVal && curr <= insertVal) ||
                (next < curr && curr <= insertVal) ||
                (next < curr && next >= insertVal)) break;
            temp = temp -> next;
        }

        Node *temp1 = temp -> next;
        temp -> next = new Node(insertVal);
        temp -> next -> next = temp1;
        return head;

    }
};
