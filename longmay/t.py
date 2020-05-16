def solution(l):

    # Your code here

    l.sort()

    mod_0 = []

    mod_1 = []

    mod_2 = []

    other = 0

    for elem in l:

        if (elem%3) == 0:

            mod_0.append(elem)

        elif elem%3 == 1:

            mod_1.append(elem)

            other += elem

        else:

            mod_2.append(elem)

            other += elem

    if other % 3 == 1:

        if len(mod_1) != 0:

            mod_1.pop(0)

        else:

            mod_2.pop(0)

            mod_2.pop(1)

    elif other%3 == 2:

        if len(mod_2) != 0:

            mod_2.pop(0)

        else:

            mod_1.pop(0)

            mod_1.pop(0)

    final = mod_0 + mod_1 + mod_2

    final.sort(reverse=True)

    string = ""

    for num in final:

        string += str(num)

    return string
