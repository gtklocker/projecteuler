def solve(min_l, n):
    dp = [[0] * n for i in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for l in range(n, min_l - 1, -1):
            if i + l <= n:
                dp[l][i] += 1

                for l1 in range(min_l, n + 1):
                    for j in range(i + l + 1, n):
                        dp[l][i] += dp[l1][j]

    return sum([sum(dp[i]) for i in range(n + 1)]) + 1

m = 50

over = 175
needle = 10**6
start, end = m, over
while True:
    middle = (start + end) // 2

    if start == end:
        print(start)
        break

    sol = solve(m, middle)
    if sol > needle:
        if middle >= start:
            end = middle
    elif sol < needle:
        if middle + 1 <= end:
            start = middle + 1
