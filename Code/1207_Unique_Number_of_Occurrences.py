class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occurrences = {}
        occvals = {}

        for value in arr :
            if(value in occurrences) :
                occurrences[value] = occurrences[value] + 1
            else :
                occurrences[value] = 1

        for value in occurrences.values() :
            if(value in occvals) : 
                return False
            else :
                occvals[value] = value
            
        return True