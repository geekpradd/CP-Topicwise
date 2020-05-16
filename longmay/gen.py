out = "1\n400 160000\n"
for a in range(400):
	out += "{0} ".format(400-a)

with open("in.txt", "w") as f:
	f.write(out)