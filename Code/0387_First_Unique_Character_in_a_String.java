class Solution {
    public int firstUniqChar(String s) {
        final int ALPHAEBET = 26;
        List<Integer> letters = new ArrayList<Integer>();

        for(int i = 0; i < ALPHAEBET; i++){
            letters.add(0);
        }

        for(int i = 0; i < s.length(); i++){
            int index = (int)s.charAt(i) - (int)'a';
            letters.set(index, letters.get(index) + 1);
        }

        for(int i = 0; i < s.length(); i++){
            int index = (int)s.charAt(i) - (int)'a';
            if(letters.get(index) == 1)
                return i;
        }

        return -1;
    }
}