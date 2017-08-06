"""
Definition of ArrayReader:
class ArrayReader:
    def get(self, index):
        # this would return the number on the given index
        # return -1 if index is less than zero.
"""
class Solution:
    # @param {ArrayReader} reader: An instance of ArrayReader 
    # @param {int} target an integer
    # @return {int} an integer
    def searchBigSortedArray(self, reader, target):
        # write your code here
        left, right = self.findRange(reader, target)
        
        while left + 1 < right:
            mid = (left + right) / 2
            if reader.get(mid) < target:
                left = mid
            elif reader.get(mid) > target:
                right = mid
            else:
                right = mid

        if reader.get(left) == target:
            return left
        
        if reader.get(right) == target:
            return right

        return -1
        
    def findRange(self, reader, target):
        if not reader:
            return None
        
        left = 0
        right = 1
        
        while True:
            if reader.get(right) < target:
                left = right
                right *= 2
            else:
                break
                
        return (left, right)
        