/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    int getSize(ImmutableListNode * head){
        int count = 0;
        while (head){
            ++count;
            head = head->getNext();
        }
        return count;
    }

    void printBlock(ImmutableListNode * head, int count){
        if (!head || !count)
            return;

        printBlock(head->getNext(), --count);
        head->printValue();
    }

    void printLinkedListInReverse(ImmutableListNode* head){
        int size = getSize(head);
        int block_count = ceil (sqrt(size));
        int block_size = ceil(size/block_count);

        stack<ImmutableListNode*> st;

        for (int i = 0; i <size; ++i){
            if (i%block_size == 0) st.push(head);
            head = head->getNext();
        }

        while(!st.empty()){
            printBlock(st.top(), block_size);
            st.pop();
        }
    }
};