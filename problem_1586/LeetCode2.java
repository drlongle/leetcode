/*
Algorithm

* Constructor:
Initialize the last processed node as root: last = root.
Initialize a list to store already processed nodes: arr.
Initialize service data structure stack to be used during the iterative inorder traversal.
Initialize pointer: pointer = -1. This pointer serves as indicator if we're in the already parsed area or not.
We're in the parsed area if pointer + 1 < len(arr).

* hasNext:
Return true if last node is not null, or the stack is not empty, or we're in the already parsed area: pointer + 1 < len(arr).

* next:
Increase the pointer by 1: pointer += 1.
If we're not in the precomputed part of the tree, parse the bare minimum: the leftmost subtree of the last node:
Go left till you can, while the last node is not null:
Push the last node into the stack: stack.append(last).
Go left: last = left.last.
Pop the last node out of the stack: curr = stack.pop().
Append this node value to the list of the parsed nodes: arr.append(curr.val).
Go one step to the right: last = curr.right.
Otherwise, return arr[pointer].

* hasPrev:
Compare the pointer to zero: return pointer > 0.

* prev: decrease the pointer by one and return arr[pointer].
*/

class BSTIterator {

    Deque<TreeNode> stack;
    List<Integer> arr;
    TreeNode last;
    int pointer;

    public BSTIterator(TreeNode root) {
        last = root;
        stack = new ArrayDeque();
        arr = new ArrayList();
        pointer = -1;
    }
    
    public boolean hasNext() {
        return !stack.isEmpty() || last != null || pointer < arr.size() - 1;
    }
    
    public int next() {
        ++pointer;
        // if the pointer is out of precomputed range
        if (pointer == arr.size()) {
            // process all predecessors of the last node:
            // go left till you can and then one step right
            while (last != null) {
                stack.push(last);
                last = last.left;                
            }
            TreeNode curr = stack.pop();
            last = curr.right;
        
            arr.add(curr.val);
        }
            
        return arr.get(pointer);
    }
    
    public boolean hasPrev() {
        return pointer > 0;
    }
    
    public int prev() {
        --pointer;
        return arr.get(pointer);
    }
}
