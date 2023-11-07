import random
import string

def gen(n,m,f):
    f.write(str(n) + "\n")
    for i in range(0,n):
        for j in range(0,m):
            f.write(random.choice(string.ascii_letters))
        f.write(" ")
    f.write("\n")

array_n = [5, 10, 25, 50, 100, 500, 1000, 5000]
array_m = [1, 25, 50, 100]

with open("build/tests.txt", "w") as f:
    f.write(str(len(array_n)) + " " + str(len(array_m)) + "\n")
    for n in array_n:
        for m in array_m:
            gen(n, m, f)
