class Solution:
    def longestPalindrome(self, s: str) -> str:
        resIdx, resLen = 0, 0
        n = len(s)

        dp = []
        for _ in range(n):
            row = [False] * n
            dp.append(row)

        for i in range(n-1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i <= 2 or dp[i+1][j-1]):
                    dp[i][j] = True

                    if resLen < j - i + 1:
                        resIdx = i 
                        resLen = j - i + 1

        return s[resIdx : resIdx + resLen]                
        