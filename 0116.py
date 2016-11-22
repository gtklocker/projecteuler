def solve(n, l):
    dp = [0] * n
    for i in range(n - 1, -1, -1):
        if i + l <= n:
            dp[i] += 1
            for j in range(i + l, n):
                dp[i] += dp[j]
    return sum(dp)

n = 50
sol = solve(n, 2) + solve(n, 3) + solve(n, 4)
print(sol)
