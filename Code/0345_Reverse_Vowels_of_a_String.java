class Solution {
    public String reverseVowels(String s) {
        StringBuilder sb = new StringBuilder(s);

        int left = 0;
        int right = sb.length()-1;

        while(left < right){
            boolean isVowelL = isVowel(sb.charAt(left));
            boolean isVowelR = isVowel(sb.charAt(right));
            if(isVowelL && isVowelR){
                char c = sb.charAt(right);
                sb.setCharAt(right, sb.charAt(left));
                sb.setCharAt(left, c);

                left++;
                right--;
            } else if(isVowelL && !isVowelR){
                right--;
            } else if(!isVowelL && isVowelR){
                left++;
            } else {
                left++;
                right--;
            }
        }

        return sb.toString();
    }

    boolean isVowel(char c){
        boolean res = switch(c){
            case 'a','e','i','o','u' -> true;
            case 'A','E','O','I','U' -> true;
            default -> false;
        };

        return res;
    }
}