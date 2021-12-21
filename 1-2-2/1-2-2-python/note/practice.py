for i in range(19):
    for j in range(9):
        if(i%7==0 and i!=0 and j!=0):
            print("{} x {} = {}".format(i, j, i*j))