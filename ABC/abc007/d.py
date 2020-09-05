A, B = map(int, input().split())

def count(x):
    fb, cb, t = -1, 0, x
    while t>0:
        if t%10==4 or t%10==9:
            fb = cb
        cb += 1
        t //= 10
    if fb>=0:
        x = (x//(10**fb)-1) * (10**fb)
        for i in range(fb):
            x += 8*(10**i)
    nb = 0
    t = 1 if x%10!=4 and x%10!=9 else 0
    while True:
        b = x%10
        for i in range(b):
            if i!=4 and i!=9:
                t += 8**nb
        x //= 10
        nb += 1
        if x==0:
            break
    return t

print(B-A+1 - (count(B)-count(A-1)))
