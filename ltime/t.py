with open("in", "w") as f:
    s = "1\n"
    p = 564
    s += str(p) + "\n"
    for x in range(p):
        s += str(x+1) + " " 
    s += "\n"
    f.write(s)
