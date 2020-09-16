d = {}
allowed = {}
while True:
	data = input()
	if not data:
		break
	if not "(" in data or not ")" in data:
		continue
	main_name = data.split("(")[0]
	annotation = data.split("(")[1][0]
	if annotation == 