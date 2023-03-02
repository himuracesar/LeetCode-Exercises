class Solution:
    def isPalindrome(self, s: str) -> bool:
        start = 0
        end = len(s) - 1

        text = s.lower()

        #print(s.lower())

        while(start < end) :
            if(ord(text[start]) < ord('a') or ord(text[start]) > ord('z')) :
                if(ord(text[start]) < ord('0') or ord(text[start]) > ord('9')) :
                    start += 1
                    continue
            
            if(ord(text[end]) < ord('a') or ord(text[end]) > ord('z')) :
                if(ord(text[end]) < ord('0') or ord(text[end]) > ord('9')) :
                    end -= 1
                    continue

            if(text[start] != text[end]) :
                return False

            start += 1
            end -= 1
        
        return True