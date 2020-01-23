struct Node {
    int val;
    vector<Node*> forwards;    // pointers to successor nodes, and forwards.size() is the level of the Node
    Node(int _val, int _level) : val(_val), forwards(_level, nullptr) {}
    int level() { return forwards.size(); }
};


class Skiplist {
public:
    Skiplist() : m_head(new Node(INT_MIN, 0)) {}

    bool search(int target) {
        Node* node = m_head;
        int level = m_head->forwards.size() - 1;

        while (level >= 0) {
            // find the node with maximum value less than target or equal to target
            while (node->forwards[level] && node->forwards[level]->val <= target)
                node = node->forwards[level];
            if (node->val == target) break;
            --level;
        }
        return node->val == target;
    }

    void add(int num) {
        int level = randomLevel();      // random number of levels for current node
        while (level > m_head->level()) {          // insert new level
            m_head->forwards.push_back(nullptr);
        }

        Node* inst = new Node(num, level);  // the node to insert
        Node* node = m_head;
        level = m_head->level() - 1;
        while (level >= 0) {
            // find the node with maximum value less than num
            while (node->forwards[level] && node->forwards[level]->val < num)
                node = node->forwards[level];
            if (level < inst->level()) {         // insert new node into current level
                inst->forwards[level] = node->forwards[level];
                node->forwards[level] = inst;
            }
            --level;
        }
    }

    bool erase(int num) {
        Node* node = m_head;
        Node* delt = nullptr;   // the node to delete
        int level = m_head->level() - 1;
        while (level >= 0) {
            if (!delt) {    // find the node with maximum value less than num
                while (node->forwards[level] && node->forwards[level]->val < num)
                    node = node->forwards[level];
                // succeed to find the node to delete
                if (node->forwards[level] && node->forwards[level]->val == num) {
                    delt = node->forwards[level];       
                    node->forwards[level] = delt->forwards[level];
                }
            }
            else {  // erase delt in current level
                while (node->forwards[level] != delt) node = node->forwards[level];
                node->forwards[level] = delt->forwards[level];
            }
            --level;
        }
		delete delt;    // erase delt in the skip list
        return delt;
    }

private:
    // p = 1/2
    int randomLevel() {
        int ret = 1;
        while (rand() & 1) ++ret;
        return ret;
    }

    // the head of skip list, and the level of skip list is m_head->forwards.size()
    Node* m_head;   
};
