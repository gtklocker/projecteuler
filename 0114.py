def solve(n, m):
    dp = [[0] * (n + 1) for i in range(2)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        if i - 1 >= 0:
            dp[0][i] = dp[0][i - 1] + dp[1][i - 1]
            dp[1][i] = dp[1][i - 1]
        if i - m >= 0:
            dp[1][i] += dp[0][i - m]

    return dp[0][n] + dp[1][n]

n = 50
l = 3
sol = solve(n, l)
print(sol)
