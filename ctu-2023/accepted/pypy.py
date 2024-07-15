#from __future__ import annotations
import sys
import math
sys.setrecursionlimit(1000000)
def D(a):print(a)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))
next_int()
T = a = b = B = 0
f = [0] * 21
W = [2,3,4,5,6,7,8,9,10,12,14,15,16,18,20]
N = len(W)
for i in line_ints():
    if f[i]:
        T += i
    f[i] += 1
for i, e in enumerate(f):
    if e:
        if i in W:
            a += 1
        else:
            b += 1
    elif i in W:
        B |= 1 << W.index(i)

dp = [[-1] * (1 << N) for _ in range(21)]
def dyn(B, l):
    global dp
    if dp[l][B] != -1:
        return dp[l][B]
    if B == (1<<N)-1:
        return 0
    dp[l][B] = 0
    for i, v in enumerate(W):
        if not B & (1 << i):
            dp[l][B] = max(dp[l][B], dyn(B | (1 << i), v) + math.gcd(l, v))
    return dp[l][B]

def go(B):
    if not a:
        return b-1
    return dyn(B, 1) - 1 + b


print(go(B)+T)
