# Given an array of n integers where n > 1, nums,
# return an array output such that output[i] is equal to
# the product of all the elements of nums except nums[i].
#
# Solve it without division and in O(n).
#
# For example, given [1,2,3,4], return [24,12,8,6].
#
# Follow up:
# Could you solve it with constant space complexity?
# (Note: The output array does not count as extra space for the purpose of space complexity analysis.)


class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        p = 1
        n = len(nums)
        output = []
        for i in range(0,n):
            output.append(p)
            p = p * nums[i]

        p = 1
        for i in range(n-1,-1,-1):
            output[i] = output[i] * p
            p = p * nums[i]
        return output

    def productExceptSelf_slow(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        for i, v in enumerate(nums):
            m = self.multi_helper(nums, i)
            ret.append(m)
        return ret

    def multi_helper(self, nums, not_i):
        ret = 1
        for i, v in enumerate(nums):
            if i == not_i:
                continue
            else:
                ret *= v

        return ret

    def productExceptSelf_div(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        total = 1
        for n in nums:
            total *= n

        return [int((total/n)) for n in nums]

    def test(self):
        tests = [[1,2,3,4]]#,
                 # [4,3,2,7,8,2,3,1],
                 # [1,2,3,3,4,5,6],
                 # [],
                 # [1,1]]

        for t in tests:
            print("-------------div--------------")
            print(self.productExceptSelf_div(t))
            print("-------------slow--------------")
            print(self.productExceptSelf_slow(t))
            print("-------------answer--------------")
            print(self.productExceptSelf(t))

if __name__ == '__main__':
    s = Solution()
    s.test()
