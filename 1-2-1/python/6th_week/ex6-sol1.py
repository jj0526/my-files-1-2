name = []
score = []
print("Enter을 치면, 입력을 종료합니다.")
while (True):
    name.append(input("이름을 입력하시오 : "))
    if name[-1] == '':
        break
    score.append(input("점수를 입력하시오 : "))
    if score[-1] == '':
        break
print(name)
print(score)
dic = dict(zip(name, score))
print(dic)