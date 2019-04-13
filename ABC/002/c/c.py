x_a, y_a, x_b, y_b, x_c, y_c = map(int, input().split())
dx1 = x_a - x_b
dy1 = y_a - y_b
dx2 = x_a - x_c
dy2 = y_a - y_c
print(abs(dx1*dy2-dx2*dy1)/2)

