numbers = [55, 73, 22, 256, 123, 73, 456]
print("$ (1) 리스트 내부에 있는 값 찾기")
print("- {}는 {} 위치에 있습니다.".format(22, numbers.index(22)))

print("# (2) 리스트 내부에 없는 값 찾기")
try:
    number = 1000
    print("- {}는 {} 위치에 있습니다". format(number, numbers.index(number)))
except:
    print("오류가 발생하였습니다")
    print("- 리스트 내부에 없는 값입니다.")
print("--- 정상적으로 종료되었습니다. ---")