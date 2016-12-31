class Solution:
    """
    @param A : a list of integers
    @param target : an integer to be searched
    @return : a list of length 2, [index1, index2]
    """
    def searchRange(self, A, target):
        if len(A) == 0:
            return [-1, -1]

        start, end = 0, len(A) - 1
        while start + 1 < end:
            mid = start + int((end - start) / 2)
            if A[mid] < target:
                start = mid
            else:
                end = mid

        if A[start] == target:
            leftBound = start
        elif A[end] == target:
            leftBound = end
        else:
            return [-1, -1]

        start, end = leftBound, len(A) - 1
        while start + 1 < end:
            mid = start + int((end - start) / 2)

            if A[mid] <= target:
                start = mid
            else:
                end = mid

        if A[end] == target:
            rightBound = end
        else:
            rightBound = start

        return [leftBound, rightBound]

    def searchRange_slow(self, A, target):
        # write your code here
        if len(A) == 0:
            return [-1,-1]

        start = 0
        end = len(A) - 1

        while (start + 1) < end:
            mid = start + (end - start) / 2

            if A[mid] == target:
                end = mid
            elif A[mid] < target:
                start = mid
            else:
                end = mid

        ret_left = -1
        ret_right = -1
        if A[start] == target:
            ret_left = start
            ret_right = start

        if A[end] == target:
            ret_left = end
            ret_right = end

        while ret_left > 0 and A[ret_left-1] == target:
            ret_left -= 1

        while (ret_right < len(A) - 1) and A[ret_right + 1] == target:
            ret_right += 1

        return [ret_left, ret_right]

    def test(self):
        tests = [
        ([5,7,7,8,8,10], 8, [3,4]),
        ([5,7,7,8,8,8,8,10], 8, [3,6]),
        ([5,7,7,8,8,8,8,10], 0, [-1,-1]),
        ([0,1,2,3,4], 0, [0,0])]

        for t in tests:
            ans = self.searchRange(t[0], t[1])
            print("------sol------")
            print(ans)
            print("------expected ans----")
            print(t[2])

if __name__ == '__main__':
    s = Solution()
    s.test()