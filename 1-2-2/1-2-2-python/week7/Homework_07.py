def func_sum(a,b,c,d,e):
    sum = a+b+c+d+e
    return sum
score = [73, 95, 80, 57, 99]
real_sum = func_sum(*score)
print("합계 점수 : ", real_sum)
print("평균 점수 : ", real_sum/5)
