name = []
score = []

while True:
    n = input()
    sc = input()
    if (n=='' or sc ==''):
        break
    name.append(n)
    score.append(sc)
dic = dict(zip(name, score))
print(dic)