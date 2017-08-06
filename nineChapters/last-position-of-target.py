class Solution:
    # @param {int[]} A an integer array sorted in ascending order
    # @param {int} target an integer
    # @return {int} an integer
    def lastPosition(self, A, target):
        # Write your code here
        if (not A) or len(A) == 0:
            return -1
        
        start = 0
        end = len(A) - 1
        
        while start + 1 < end:
            mid = (start + end) / 2
            if target > A[mid]:
                start = mid
            elif target < A[mid]:
                end = mid
            else:
                start = mid

        if A[end] == target:
            return end
        
        if A[start] == target:
            return start
        
        return -1