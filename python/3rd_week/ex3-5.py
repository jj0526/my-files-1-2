score = int(input("input the student's score : "))
if score>=90:
    grade = 'A'
elif score>=80:
    grade = 'B'
elif score>=70:
    grade = 'C'
elif score>=70:
    grade = 'D'
else:
    grade = 'F'
print("the student's grade is {}".format(grade))