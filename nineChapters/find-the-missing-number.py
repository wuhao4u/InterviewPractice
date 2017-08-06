class Solution:
    def bubbleSort(self, nums):
        ret = nums
        counter = 1
        nums_len = len(nums)

        while counter > 0:
            counter = 0
            i = 0

            while i < nums_len - 1:
                if nums[i] > nums[i+1]:
                    # swap
                    temp = nums[i]
                    nums[i] = nums[i+1]
                    nums[i+1] = temp

                    counter += 1
                i += 1

        return ret


    # @param nums: a list of integers
    # @return: an integer
    def findMissing(self, nums):
        # write your code here
        if not nums:
            return 0
        elif len(nums) == 0:
            return 0

        nums = self.bubbleSort(nums)

        for i, v in enumerate(nums):
            if v != i:
                return i


sol = Solution()
test1 = [0, 1, 3]
print(sol.findMissing(test1))

testSort1 = [5,2,1,3,6,4]
print(sol.bubbleSort(testSort1))