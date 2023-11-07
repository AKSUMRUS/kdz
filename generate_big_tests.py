import random

def gen(n,f):
    f.write(str(n) + "\n")
    for i in range(0,n):
        f.write(str(random.randint(-1e8, 1e8)) + " ")
    f.write("\n")

array_n = [5, 100, 250, 500, 1000, 5000, 10000, 500000, 1000000]

with open("build/tests.txt", "w") as f:
    f.write(str(len(array_n)) + "\n")
    for n in array_n:
        gen(n, f)
