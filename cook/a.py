def countTotalBits(num): 
     # convert number into it's binary and  
     # remove first two characters 0b. 
     binary = bin(num)[2:] 
     return (len(binary))

t = int(input())
for a in range(t):
	n = int(input())
	b = countTotalBits(n)
	if 2**(b-1) == n:
		print(-1)
	else:
		p = 2**b - (b+2)
		print(n + p)