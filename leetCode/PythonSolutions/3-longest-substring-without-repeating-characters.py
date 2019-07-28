class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s or len(s) == 0:
            return 0

        chars = list(s)
        res = 0

        i = 0
        while i < len(chars):
            j = i
            s = set()
            while j < len(chars):
                if chars[j] not in s:
                    s.add(chars[j])
                    res = max(res, len(s))
                else:
                    break
                j += 1
            i += 1

        return res


if __name__ == '__main__':
    solution = Solution()
    a1 = solution.lengthOfLongestSubstring("abcabcbb")
    a2 = solution.lengthOfLongestSubstring("bbbbb")
    a3 = solution.lengthOfLongestSubstring("pwwkew")
    a4 = solution.lengthOfLongestSubstring("b")
    a0 = 0
