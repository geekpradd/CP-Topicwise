total = 50
nt = 5
import random
strin = "{0} \n".format(total)

for _ in range(total):
	nums = [random.randint(1, 9) for x in range(nt)]*2
	random.shuffle(nums)
	first = nums[:5]
	second= nums[5:]
	strin += str(nt) + "\n"
	for n in first:
		strin += str(n) + " "
	strin += "\n"
	for n in second:
		strin += str(n) + " "
	strin += "\n"

with open("gen.txt", "w") as f:
	f.write(strin)

