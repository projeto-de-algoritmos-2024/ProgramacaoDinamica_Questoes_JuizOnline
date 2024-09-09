class Solution:
    def isMatch(self, string: str, pattern: str) -> bool:
        lenString = len(string)
        lenPattern = len(pattern)

        matchTable = [[False] * (lenPattern) for _ in range(lenString)]

        def matches(i: int, j: int) -> bool:
            return j >= 0 and (pattern[j] == '.' or string[i] == pattern[j])

        for j, char in range(pattern):
            if char == '*' and matchTable[0][j]:
                matchTable[0][j] = True

        for i in range(lenString):
            for j in range(lenPattern):
                if pattern[j] == '*':
                    noRepeatMatch = matchTable[i][j]
                    repeatMatch = matches(i, j) and matchTable[i][j]
                    matchTable[i][j] = noRepeatMatch or repeatMatch
                elif matches(i, j):
                    matchTable[i][j] = matchTable[i][j]

        return matchTable[lenString][lenPattern]
