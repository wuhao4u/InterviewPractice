class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        valIndexDict = {}
        for i in range(len(numbers)):
            if (target - numbers[i]) in valIndexDict:
                return [valIndexDict[(target - numbers[i])]+1, i+1]
            else:
                valIndexDict[numbers[i]] = i

        return [-1, -1]

    def twoSum_slow(self, numbers, target):
        # write your code here
        if not numbers:
            return [-1, -1]
        if len(numbers) < 2:
            return [-1, -1]

        for i in range(0, len(numbers)-1):
            j = i + 1
            while j < len(numbers):
                if (numbers[i] + numbers[j]) == target:
                    return [i+1, j+1]
                j += 1

        return [-1, -1]


sol = Solution()
test1 = [2, 7, 11, 15]
print(sol.twoSum(test1, 9))
print(sol.twoSum(test1, 17))
print(sol.twoSum(test1, 22))
print(sol.twoSum(test1, 26))
