import itertools

def solve(m, n):
    dp = [[0] * (n + 1) for i in range(2)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        if i - 1 >= 0:
            dp[0][i] = dp[0][i - 1] + dp[1][i - 1]
            dp[1][i] = dp[1][i - 1]
        if i - m >= 0:
            dp[1][i] += dp[0][i - m]

    return dp[0][n] + dp[1][n]

m = 50
for n in itertools.count(start=m):
    sol = solve(m, n)
    if sol > 10**6:
        print(n)
        break
