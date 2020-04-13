total = 100000
s = "{0}\n".format(total)
for a in range(total):
    s += "{0}\n".format(a+1)

f = open("input", "w")
f.write(s)
f.close()
