class Solution {
    int i=1;
    public NestedInteger deserialize(String s) {
        if (s.charAt(0)!='[') return new NestedInteger(Integer.parseInt(s));
        NestedInteger res= new NestedInteger();
        Integer num=null, k=1;
        while(i<s.length()){
            char c= s.charAt(i++);
            switch (c){
                case '[':
                    res.add(deserialize(s));
                    break;
                case ']':
                    if (num!=null) res.add(new NestedInteger(k*num));
                    num=null;
                    k=1;
                    return res;
                case ',':
                    if (num!=null) res.add(new NestedInteger(k*num));
                    num=null;
                    k=1;
                    break;
                default:
                    if (c=='+'||c=='-') k=c=='+'?1:-1;
                    else{
                        if (num==null) num=0;
                        num=num*10+c-'0';
                    }
            }
        }
        return res;
    }
}


