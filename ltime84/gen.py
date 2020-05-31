import numpy as np
t = 5
s = str(t) + "\n"
for a in range(t):
    n = 6
    s += str(n) + "\n"
    arr = np.random.randint(low = 1, high = 10, size = n)
    for elem in arr:
        s += str(elem) + " "
    s += "\n"

with open("input.txt", "w") as f:
    f.write(s)

