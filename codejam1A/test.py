fact = []
fact.append(1)
for a in range(59):
	fact.append((a+1)*fact[a])

def c(first, second):
	return fact[first]/(fact[second]*fact[first-second])

f = open("out", "r")
lines = f.readlines()
sum = 0
for line in lines:
	li = line.split(' ')
	first = int(li[0]) - 1
	second = int(li[1]) - 1
	sum += c(first, second)

print (sum)