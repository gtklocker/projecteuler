def solve(n, l):
    dp = [[0] * (n + 1) for i in range(2)]
    dp[0][0] = 1

    for i in range(n + 1):
        if i - l >= 0:
            dp[1][i] = dp[1][i - l] + dp[0][i - l]
        if i - 1 >= 0:
            dp[0][i] = dp[1][i - 1] + dp[0][i - 1]

    return dp[0][n] + dp[1][n] - 1

n = 50
sol = solve(n, 2) + solve(n, 3) + solve(n, 4)
print(sol)
