class Solution:
    def spiralOrder(self, matrix):
        if matrix is None or len(matrix) == 0:
            return []
        else:
            self.m = matrix

        curDir = "right"

        visited = [[False for i in range(len(matrix[0]))] for j in range(len(matrix))]

        totalCell = 0
        for r in matrix:
            for cell in r:
                totalCell += 1

        r = 0
        c = 0
        visitedCount = 0
        result = []
        while visitedCount < totalCell:
            if visitedCount == totalCell - 1 and not visited[r][c]:
                result.append(matrix[r][c])
                return result
            if curDir == "right":
                if (not self.inBounds(r, c + 1)) or visited[r][c + 1]:
                    curDir = "down"
                else:
                    result.append(matrix[r][c])
                    visited[r][c] = True
                    c += 1
                    visitedCount += 1
            elif curDir == "down":
                if (not self.inBounds(r + 1, c)) or visited[r + 1][c]:
                    curDir = "left"
                else:
                    result.append(matrix[r][c])
                    visited[r][c] = True
                    r += 1
                    visitedCount += 1
            elif curDir == "left":
                if (not self.inBounds(r, c - 1)) or visited[r][c - 1]:
                    curDir = "up"
                else:
                    result.append(matrix[r][c])
                    visited[r][c] = True
                    c -= 1
                    visitedCount += 1
            elif curDir == "up":
                if (not self.inBounds(r - 1, c)) or visited[r - 1][c]:
                    curDir = "right"
                else:
                    result.append(matrix[r][c])
                    visited[r][c] = True
                    r -= 1
                    visitedCount += 1
            else:
                return result

        return result

    def inBounds(self, r, c):
        if r < 0 or c < 0:
            return False

        if r >= len(self.m):
            return False

        if c >= len(self.m[0]):
            return False

        return True


if __name__ == '__main__':
    s = Solution()
    print(s.spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))
