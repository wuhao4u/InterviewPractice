# Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
# Find all the elements of [1, n] inclusive that do not appear in this array.
# Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
# Input:
# [4,3,2,7,8,2,3,1]
# Output:
# [5,6]

class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []

        n = len(nums)
        mark_list = [-1 for x in range(0,n+1)]
        for n in nums:
            mark_list[n] = 0

        result = []
        for index, val in enumerate(mark_list):
            if val == -1 and index != 0:
                result.append(index)

        return result

    def findDisappearedNumbers_in_place(self, nums):
        ret = []
        for i, v in enumerate(nums):
            val = abs(v) - 1
            if nums[val] > 0:
                nums[val] = -nums[val]

        for i, v in enumerate(nums):
            if v > 0:
                ret.append(i+1)

        return ret
        
    def findDisappearedNumbers_slow(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []

        n = len(nums)
        result = []
        for i in range(1,n+1):
            if i not in nums:
                result.append(i)
        return result

    def test(self):
        tests = [[4,3,2,7,8,2,3,1], [], [1,1], [0]]
        for t in tests:
            print("-------------slow--------------")
            print(self.findDisappearedNumbers_slow(t))
            print("-------------fast--------------")
            print(self.findDisappearedNumbers(t))

if __name__ == '__main__':
    s = Solution()
    s.test()
