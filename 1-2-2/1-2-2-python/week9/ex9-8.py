import random

a = random.randint(1,100)
b = random.randint(1,100)
c = a+b

print('%d + %d = ? ' %(a, b))
result = int(input())

if result==c:
    print('정답입니다')
else:
    print('틀렸습니다')