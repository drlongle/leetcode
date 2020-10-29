/*
Essentially, we need to check for a maximum possible prefix sum in an array where each element is a time slot
possibly accumulating the +1/-1 updates from previous successful bookings, and finding the maximum possible
prefix sum can be done in log-arithmetic time using a radix tree.

This makes time complexity of each update O(log N) and overall time complexity O(N log N).

For those unfamiliar with the concept of radix tree: you can essentially picture each possible time slot
(t = 0 through t = INT_MAX) as a leaf node of a really large full binary tree, the path from the root node
to each leaf node x as the binary expansion of x, where a 0 bit means descending from a parent node to its
left subtree, 1 bit means descending to the right. Obviously we cannot materialize this entire binary tree
in memory, but for each book(start, end) call, only the paths from root to t = start and root to t = end need
to be materialized (if not present already), and then the problem can be solved quite easily if we just track
the overall sum and max prefix sum within each subtree.
*/

constexpr size_t kMaxNumIntervals = 1000;
constexpr size_t kIntBits = sizeof(int) * CHAR_BIT;
constexpr int kMaxConcurrency = 2;

class MyCalendarTwo {
private:
    struct Node {
        Node* nxt[2] = {};
        int subtreeSum = 0;
        int maxPrefixSumInSubtree = 0;
    };
public:
    MyCalendarTwo() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    bool book(int const start, int const end) {
        update(start, 1); update(end, -1);
        if (maxPrefixSum() > kMaxConcurrency) {
            // current modification is not feasible, so, undo it and return false
            update(start, -1); update(end, 1);
            return false;
        }
        return true;
    }
private:
    int subtreeSum(Node const* n) const {
        return n ? n->subtreeSum : 0;
    }
    int maxPrefixSumInSubtree(Node const* n) const {
        return n ? n->maxPrefixSumInSubtree : 0;
    }
    void update(int const x, int const diff) {
        Node* ptr = root_;
        Node* path_from_root[kIntBits];

        unsigned int bitmask = (1 << (kIntBits - 1));
        for (int i = 0; i < kIntBits; ++i, bitmask >>= 1) {
            auto const b = (x & bitmask) ? 1 : 0;
            auto& nxt = ptr->nxt[b];
            if (!nxt) nxt = &mem_[memOffset_++];
            nxt->subtreeSum += diff;
            path_from_root[i] = nxt;
            ptr = nxt;
        }

        auto* const leaf_node = path_from_root[kIntBits - 1];
        leaf_node->maxPrefixSumInSubtree = leaf_node->subtreeSum;
        for (int i = kIntBits - 2; i >= 0; --i, bitmask <<= 1) {
            auto* const node = path_from_root[i];
            node->maxPrefixSumInSubtree = std::max(
                    maxPrefixSumInSubtree(node->nxt[0]),
                    subtreeSum(node->nxt[0]) + maxPrefixSumInSubtree(node->nxt[1])
            );
        }
    }
    int maxPrefixSum() const {
        return std::max(
                maxPrefixSumInSubtree(root_->nxt[0]),
                subtreeSum(root_->nxt[0]) + maxPrefixSumInSubtree(root_->nxt[1])
        );
    }

    // pre-allocate maximum possible amount of required memory to avoid realloc
    Node mem_[2 * kMaxNumIntervals * kIntBits];
    Node* const root_ = &mem_[0];
    size_t memOffset_ = 1;
};
