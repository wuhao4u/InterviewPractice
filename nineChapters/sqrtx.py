class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        if x < 0:
            return -1
        
        if x == 0:
            return 0
            
        base = 1
        while base * base <= x:
            base += 1
        
        if base * base == x:
            return base
        else:
            return base-1


class Official_Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        if x < 0:
            return -1
        elif x == 0:
            return 0
        elif x == 1:
            return 1
            
        start = 1
        end = x
        
        mid = 0
        while start + 1 < end:
            mid = (start + end) / 2
            mid_sq = mid * mid
            if mid_sq < x:
                start = mid
            elif mid_sq > x:
                end = mid
            else:
                return mid
                
        if end * end <= x:
            return end
        else:
            return start
