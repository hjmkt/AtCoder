X, A, D, N = map(int, input().split())
if D == 0:
    print(abs(A - X))
elif N == 1:
    print(abs(A - X))
else:
    if D < 0:
        A += D * (N - 1)
        D = -D
    X -= A
    if X < 0:
        print(-X)
    elif X > D * (N - 1):
        print(X - D * (N - 1))
    else:
        print(min(X % D, D - X % D))
