class Solution {
    public String boldWords(String[] dict, String s) {
	int boldTill = -1;
	StringBuffer result = new StringBuffer();
	for (int i=0; i<s.length(); i++) {
		for (String word: dict)
			if (s.startsWith(word, i)) {
				if (boldTill<i) result.append("<b>");
				boldTill = Math.max(boldTill, i+word.length());
			}
		if (i==boldTill) result.append("</b>");
		result.append(s.charAt(i));
	}
	if (boldTill == s.length()) result.append("</b>");
	return result.toString();
    }
}

