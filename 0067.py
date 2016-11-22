INPUT = None

with open('p067_triangle.txt', 'r') as f:
    INPUT = f.read()

lines = INPUT.split('\n')[:-1]
n = len(lines)
levels = [list(map(int, line.split())) for line in lines]

INF = 9999999999
sol = [[-INF for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(i + 1):
        sol[i][j] = levels[i][j]
        if i - 1 >= 0 and j - 1 <= i - 1:
            sol[i][j] = max(sol[i][j], sol[i - 1][j - 1] + levels[i][j])
        if i - 1 >= 0 and j <= i - 1:
            sol[i][j] = max(sol[i][j], sol[i - 1][j] + levels[i][j])
print(max([sol[n - 1][j] for j in range(n)]))
