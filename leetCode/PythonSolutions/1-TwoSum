class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if nums is None or len(nums) == 0:
            return []

        res = [-1, -1]

        d = {}
        index = 0
        for n in nums:
            d[n] = index
            index += 1
        
        index = 0
        for n in nums:
            needed = target - n
            if needed in d.keys() and d[needed] != index:
                return [index, d[needed]]
            index += 1
        
        return res