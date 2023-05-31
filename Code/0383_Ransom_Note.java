class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> resources = new HashMap();

        for(int i = 0; i < magazine.length(); i++){
            Integer count = resources.get(magazine.charAt(i));
            if(count != null){
                count++;
                resources.put(magazine.charAt(i), count);
            } else {
                resources.put(magazine.charAt(i), 1);
            }
        }

        for(int i = 0; i < ransomNote.length(); i++){
            Integer count = resources.get(ransomNote.charAt(i));
            if(count != null && count > 0){
                count--;
                resources.put(ransomNote.charAt(i), count);
            } else {
                return false;
            }
        }

        return true;
    }
}