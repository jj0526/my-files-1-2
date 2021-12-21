score = int(input("input the student's score : "))
if score>=90:
    grade = 'A'
if score>=80:
    grade = 'B'
if score>=70:
    grade = 'C'
if score>=70:
    grade = 'D'
if score<60:
    grade = 'F'
print("the student's grade is {}".format(grade))