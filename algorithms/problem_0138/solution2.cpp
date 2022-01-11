class Solution {
public:
    unordered_map<Node*, Node*> cache;
    
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        auto it = cache.find(head);
        if (it != cache.end())
            return it->second;
        auto node = new Node(head->val);
        cache[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};
