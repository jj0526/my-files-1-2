num = int(input("input an integer : "))
total = 0
i = 1

for i in range(1,num+1):
    total = total + i
print("The sum of 1 - {} is {}".format(num,total))