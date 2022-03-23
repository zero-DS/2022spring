user = input("주민등록번호: ").replace("-","")

result1 = int(user[0])*2 + int(user[1])*3 + int(user[2])*4 + int(user[3])*5 + int(user[4])*6 + int(user[5])*7 + int(user[6])*8 + int(user[7])*9 + int(user[8])*2 + int(user[9])*3 + int(user[10])*4 + int(user[11])*5
result2 = 11 - (result1 % 11)
result3 = str(result2)
if user[-1] == result3:
    print("유효한 주민등록번호입니다.")
else:
    print("유효하지 않은 주민등록록번호입니다.")