class Solution {
    public List<String> commonChars(String[] A) {
        List<String> returnList = new ArrayList<String>();
        for (int i = 'a'; i <= 'z'; i++){
            
            int iLength = A[0].length();
            for (int j = 0; j < A.length; j++){
                int iTmp = 0;
                for (int k = 0; k < A[j].length(); k++){
                    if (A[j].charAt(k) == i)
                        iTmp++;
                }
                if (iTmp == 0){
                    iLength = 0;
                    break;
                }
                else if (iTmp < iLength)
                    iLength = iTmp;
            }
            for (int l = 0; l < iLength; l++){
                StringBuffer sbTmp = new StringBuffer();
                sbTmp.append((char)i);
                returnList.add(sbTmp.toString());
            }   
        }
        return returnList;
    }
}
