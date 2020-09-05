import numpy

w = input()
w = w.translate(str.maketrans("", "", "aeiou"))
print(w)

