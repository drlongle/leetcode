public String shortestPalindrome(String s) {
    if(s.length() == 0 || s == null){
        return "";
    }
    int n = s.length();
    StringBuilder sb = new StringBuilder();
    sb.append(s);
    String r = sb.reverse().toString();
    for(int i = 0; i < s.length(); i++) {
        if(s.substring(0, s.length() - i).equals(r.substring(i))){
            return r.substring(0, i) + s;
        }
    }
    return "";
}

