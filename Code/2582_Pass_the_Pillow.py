class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        dt = time
        numSteps = n - 1
        position = 1
        direction = 1

        while(dt > 0) :
            step = min(dt, numSteps) 
            dt -= step
            step *= direction
            position += step
            direction *= -1

        return position