num = int(input("input an integer number"))

if ((num%2) and (num%3))==0:
    print("{}는 2와 3으로 나누어 떨어집니다.".format(num))
else:
    print("{}는 2와 3으로 나누어 떨어지지 않습니다".format(num))