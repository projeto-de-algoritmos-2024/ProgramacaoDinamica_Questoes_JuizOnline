class Solution:
    def isMatch(self, string: str, pattern: str) -> bool:
        lenString = len(string)
        lenPattern = len(pattern)

        matchTable = [[False] * (lenPattern + 1) for _ in range(lenString + 1)]
        matchTable[0][0] = True

        def matches(i: int, j: int) -> bool:
            return j >= 0 and (pattern[j] == '.' or string[i] == pattern[j])

        for j, char in enumerate(pattern):
            if char == '*' and matchTable[0][j - 1]:
                matchTable[0][j + 1] = True

        for i in range(lenString):
            for j in range(lenPattern):
                if pattern[j] == '*':
                    noRepeatMatch = matchTable[i + 1][j - 1]  # índice mínimo de '*' é 1
                    repeatMatch = matches(i, j - 1) and matchTable[i][j + 1]
                    matchTable[i + 1][j + 1] = noRepeatMatch or repeatMatch
                elif matches(i, j):
                    matchTable[i + 1][j + 1] = matchTable[i][j]

        return matchTable[lenString][lenPattern]
