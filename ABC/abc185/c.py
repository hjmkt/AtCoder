import math
from sys import stdin
input = stdin.readline

L = int(input())

def combi(n, m):
    a = math.factorial(n)
    b = math.factorial(m)
    c = math.factorial(n-m)
    return a//b//c

print(combi(L-12+11, 11))
