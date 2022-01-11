class Solution {
    public NestedInteger deserialize(String s) {
        if (s == null || s.length() == 0){
            return new NestedInteger();
        }

        if (s.charAt(0) != '['){
            return new NestedInteger(Integer.parseInt(s));
        }

        Stack<NestedInteger> stack = new Stack<>();
        NestedInteger cur = null;

        int len = s.length();

        for (int i = 0; i < len; i ++) {
            char c = s.charAt(i);
            if (c == '+' || c == '-' || Character.isDigit(c)) {
                int end = i + 1;
                while (end < len && Character.isDigit(s.charAt(end))){
                    end ++;
                }
                int num = Integer.parseInt(s.substring(i, end));
                cur.add(new NestedInteger(num));
                i = end - 1;
            } else if (c == '[') {
                if (cur != null){
                    stack.push(cur);
                }
                cur = new NestedInteger();
            } else if (c == ']') {
                if (stack.size() > 0){
                    stack.peek().add(cur);
                    cur = stack.pop();
                }
            }
        }

        return stack.size() == 0 ? cur : stack.pop();
    }
}

