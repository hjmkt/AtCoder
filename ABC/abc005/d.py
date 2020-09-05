n = int(input())
d = [list(map(int, input().split())) for _ in range(n)]
q = int(input())
p = [int(input()) for _ in range(q)]

acc = [[sum(c[:i+1]) for i in range(n)] for c in d]
for i in range(1, n):
    for j in range(n):
        acc[i][j] += acc[i-1][j]

opt = [0 for _ in range(n*n+1)]
for i in range(n):
    for j in range(n):
        for k in range(i, n):
            for l in range(j, n):
                a = (k-i+1)*(l-j+1)
                s = acc[k][l] - (acc[i-1][l] if i>0 else 0) - (acc[k][j-1] if j>0 else 0) + (acc[i-1][j-1] if i>0 and j>0 else 0)
                opt[a] = max(opt[a], s)
for i in range(1, n*n+1):
    opt[i] = max(opt[i-1], opt[i])
for i in range(q):
    print(opt[p[i]])
