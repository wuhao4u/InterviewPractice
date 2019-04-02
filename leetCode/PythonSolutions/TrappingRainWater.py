import sys


class Solution:
    """
    @param heights: a list of integers
    @return: a integer
    """

    def trapRainWater(self, heights):
        if not heights:
            return 0

        left_max = []
        curt_max = -sys.maxsize
        for height in heights:
            curt_max = max(curt_max, height)
            left_max.append(curt_max)

        right_max = []
        curt_max = -sys.maxsize
        for height in reversed(heights):
            curt_max = max(curt_max, height)
            right_max.append(curt_max)

        right_max = right_max[::-1]

        water = 0
        n = len(heights)
        for i in range(n):
            # water += (min(left_max[i], right_max[i]) - heights[i])
            lower_edge = min(left_max[i], right_max[i])
            diff = lower_edge - heights[i]
            water += diff

        return water


if __name__ == '__main__':
    l1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    solution = Solution()
    print(solution.trapRainWater(l1))
