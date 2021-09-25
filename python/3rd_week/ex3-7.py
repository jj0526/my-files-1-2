year = int(input("input the year you were born in : "))
age = 2021 - year + 1
if 20<=age<=29:
    print("your age is {} and you're a college/university student".format(age))
elif 17<=age<=19:
    print("your age is {} and you're a high school student".format(age))
elif 14<=age<=16:
    print("your age is {} and you're a middle school student".format(age))
elif 8<=age<=13:
    print("your age is {} and you're a elementary school student".format(age))
else:
    print("your age is {} and you're not a student".format(age))