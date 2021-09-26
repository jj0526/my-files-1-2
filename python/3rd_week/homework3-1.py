num1 = int(input("input the first integer"))
num2 = int(input("input the second integer"))
num3 = int(input("input the third integer"))
if ((num1>=num2)and(num1>=num3)):
    print("{} is the biggest number among {}, {} and {}".format(num1, num1,num2,num3))
if ((num2>=num1)and(num2>=num3)):
    print("{} is the biggest number among {}, {} and {}".format(num2, num1,num2,num3))
if ((num3>=num2)and(num3>=num1)):
    print("{} is the biggest number among {}, {} and {}".format(num3, num1,num2,num3))