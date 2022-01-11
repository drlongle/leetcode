    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> traversal = {};
        queue<pair<Node*, int>> print_queue;
        print_queue.push(make_pair(root,0));

        while (!print_queue.empty()) {
            auto pair = print_queue.front();
            print_queue.pop();
            Node* node = pair.first;
            if (!node) continue;
            int cur_level = pair.second;
            
            //resize
            if (cur_level >= traversal.size()) traversal.resize(traversal.size()+1);
            
            //push back current
            vector<int>& v = traversal[cur_level];
            v.push_back(node->val);
            
            //enqueue children
            for (auto n : node->children) {
                print_queue.push(make_pair(n, cur_level+1));
            }
        }
        return traversal;
    }
