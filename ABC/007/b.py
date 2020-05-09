a = input()
if a=='a':
    print(-1)
elif len(a)==1:
    print(chr(ord(a[0])-1))
else:
    print(a[:-1])
