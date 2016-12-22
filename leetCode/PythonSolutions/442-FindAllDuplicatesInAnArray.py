# Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
# Find all the elements that appear twice in this array.
# Could you do it without extra space and in O(n) runtime?

# Example:
# Input:
# [4,3,2,7,8,2,3,1]

# Output:
# [2,3]


class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        for i, v in enumerate(nums):
            val = abs(nums[i])
            if nums[val-1] > 0:
                nums[val-1] = -nums[val-1]
            elif nums[val-1] < 0:
                ret.append(abs(v))

        return ret

    def findDuplicates_extra_space(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        appear_list = [-1 for x in range(0, len(nums))]
        for n in nums:
            appear_list[n-1] += 1

        for i, v in enumerate(appear_list):
            if v > 0:
                ret.append(i+1)
        return ret

    def findDuplicates_slow(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = set()
        appear_list = []
        for n in nums:
            if n not in appear_list:
                appear_list.append(n)
            else:
                ret.add(n)
        return list(ret)

    def test(self):
        tests = [[4,3,2,7,8,2,3,1], [1,2,3,3,4,5,6], [], [1,1]]
        for t in tests:
            print("-------------slow--------------")
            print(self.findDuplicates_slow(t))
            print("-------------extra_space--------------")
            print(self.findDuplicates_extra_space(t))
            print("-------------fast--------------")
            print(self.findDuplicates(t))

if __name__ == '__main__':
    s = Solution()
    s.test()
