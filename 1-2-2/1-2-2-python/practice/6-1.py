tu = ('apple', [7,5,6], (1,2,3))
li = list(tu)
tu2 = tuple(li)
tu2[1][1] = 20
tu2[1][2] = tu2[1][0]+tu2[1][1]
print(tu2)