import numpy as np

n, m = map(int, input().split())
table = np.full([n, n], False, np.bool)
for i in range(m):
    x, y = map(int, input().split())
    table[x-1, y-1] = True

def appendable(clique, n):
    for c in clique:
        if not table[c, n]:
            return False
    return True

def find_max_clique(clique, cands):
    if len(cands)==0:
        return 0
    max_clique = 0
    for cand in cands:
        is_clique = True
        for cl in clique:
            if not table[cand, cl]:
                is_clique = False
                break
        if is_clique:
            clique.add(cand)
            cands.remove(cand)
            s = find_max_clique(clique, cands) + 1
            if s > max_clique:
                max_clique = s
            clique.remove(cand)
            cands.add(cand)
    return max_clique

print(find_max_clique(set(), set(range(n))))

