class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX =  2147483647
        INT_MIN = -2147483648

        res = 0
        residue = 0

        isPositive = True

        if((dividend < 0 and divisor >= 0) or (dividend >= 0 and divisor < 0)) :
            isPositive = False

        if(dividend < 0) :
            if(dividend == INT_MIN) :
                dividend = INT_MAX
                residue = 1
            else :
                dividend = -dividend
        if(divisor < 0) :
            if(divisor == INT_MIN) :
                if(residue == 0) :
                    return 0
                divisor = INT_MAX
            else :
                divisor = -divisor

        step = 1
        div = divisor

        while(dividend >= divisor) :
            if(dividend - div >= 0) :
                dividend -= div - residue

                if(residue > 0) :
                    residue -= 1
    
                res += step

                step += step
                div += div
            else :
                step = 1
                div = divisor
                dividend -= div
                if((isPositive and res < INT_MAX) or (not isPositive and -res > INT_MIN)) :
                    res += step

                #print("else res:: ", res)
        
        if(not isPositive) :
            return -res
        return res