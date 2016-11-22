L = [2, 3, 4]

def solve(n):
    dp = [[0] * n for i in range(max(L) + 1)]
    for i in range(n - 1, -1, -1):
        for l in L:
            if i + l <= n:
                dp[l][i] += 1

                for l1 in L:
                    for j in range(i + l, n):
                        dp[l][i] += dp[l1][j]
    return sum([sum(dp[l]) for l in L]) + 1

n = 50
sol = solve(n)
print(sol)
