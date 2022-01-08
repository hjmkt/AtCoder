K = int(input())
ans = 0
base = 1
while K>0:
    b = K%2
    K //= 2
    ans += b*base
    base *= 10
print(ans*2)
