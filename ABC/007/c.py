from queue import Queue

R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
c = [list(input()) for _ in range(R)]
checked = [[False]*C for _ in range(R)]

q = Queue()
q.put((sx, sy, 0))
while(not q.empty()):
    cx, cy, d = q.get()
    if checked[cy-1][cx-1]:
        continue
    if (cx, cy)==(gx, gy):
        print(d)
        break
    checked[cy-1][cx-1] = True
    if cx>1 and c[cy-1][cx-2]=='.' and not checked[cy-1][cx-2]:
        q.put((cx-1, cy, d+1))
    if cx<C and c[cy-1][cx]=='.' and not checked[cy-1][cx]:
        q.put((cx+1, cy, d+1))
    if cy>1 and c[cy-2][cx-1]=='.' and not checked[cy-2][cx-1]:
        q.put((cx, cy-1, d+1))
    if cy<R and c[cy][cx-1]=='.' and not checked[cy][cx-1]:
        q.put((cx, cy+1, d+1))
