x = int(input("첫 번째의 숫자를 입력하세요 : "))
y = int(input("두 번째 숫자를 입력하세요 : "))

def quotRemain(a,b):
    return a//b, a%b
quotient, remainder = quotRemain(x,y)
print("몫 : {0}, 나머지 : {1}".format(quotient, remainder))