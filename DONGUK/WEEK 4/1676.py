n = int(input())

res = 1
for i in range(n, 0, -1):
    res = res * n
    n -= 1

s_res = str(res)[::-1]

cnt = 0
for i in range(len(s_res)):
    if s_res[i] == '0':
        cnt +=1
    
    else:
        break

print(cnt)

'''
오버플로우가 나지 않는 파이썬만 통곽가능한 코드
'''

count = 0

while (n >= 5):
    count += n / 5
    n /= 5

'''
소인수 분해의 성질을 이용
'''