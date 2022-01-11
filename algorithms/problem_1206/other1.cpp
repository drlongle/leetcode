/*
Node has two pointers (right and down)
2D list with directions of right and down (multi-row and multi-col lists)
 */

struct Node {
    int val;
    Node* right, * down;

    Node(int _val, Node* _right = nullptr, Node* _down = nullptr)
        : val(_val), right(_right), down(_down) {}
};


class Skiplist {
public:
    Skiplist(): m_head(nullptr), m_level(0) {}

    bool search(int target) {
        Node* node = m_head;
        while (node) {
            // find the node with maximum value less than target or equal to target
            while (node->right && node->right->val <= target)
                node = node->right;
            if (node->val == target) break;
            node = node->down;
        }
        return node && node->val == target;
    }

    void add(int num) {
        int level = randomLevel();      // random number of levels for current node
        if (level > m_level) {          // insert new level
            m_head = new Node(INT_MIN, nullptr, m_head);
            ++m_level;
        }

        Node* node = m_head, * up = nullptr;
        while (node) {
            // find the node with maximum value less than num
            while (node->right && node->right->val < num) node = node->right;
            if (level >= m_level) {     // insert new node to current level
                node->right = new Node(num, node->right);
                if (up) up->down = node->right;
                up = node->right;
            }
            node = node->down;
            ++level;
        }
    }

    bool erase(int num) {
        bool ret = false;
        Node* node = m_head, *delt = nullptr;
        while (node) {
            if (!delt) {
                // find the node with maximum value less than num
                while (node->right && node->right->val < num) node = node->right;
                if (node->right && node->right->val == num) {
                    delt = node->right;
                    ret = true;
                }
            }
            if (delt) { // erase delt in current level
                while (node->right != delt) node = node->right;
                Node* temp = node->right;
                delt = node->right->down;
                node->right = node->right->right;
                delete temp;
            }
            node = node->down;
        }
        return ret;
    }

private:

    // p = 1/2
    int randomLevel() {
        int ret = 1;
        while (rand() & 1) ++ret;
        return ret;
    }

    Node* m_head;   // the head of skip list
    int m_level;    // the total level of skip list
};
