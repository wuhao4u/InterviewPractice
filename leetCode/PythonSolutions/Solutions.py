class Solution:
    def nextClosestTime(self, time: str) -> str:
        if time is None or len(time) == 0:
            return time

        timeChars = [c for c in time.strip()]
        timeChars.remove(':')
        timeChars.sort()
        results = []
        self.dfs(timeChars, 0, [], results)
        print(results)

        return

    def dfs(self, options, start, soFar, results):
        if start == len(options):
            results.append(soFar.copy())
            return

        for i in range(start, len(options)):
            soFar.append(options[i])
            self.dfs(options, i + 1, soFar, results)
            soFar.pop()


if __name__ == '__main__':
    # Input: "19:34"
    # Output: "19:39"

    # Input: "23:59"
    # Output: "22:22"

    sol = Solution()
    print(sol.nextClosestTime("19:34"))
    # print(sol.nextClosestTime("23:59"))
