n = int(input())

nums = [i for i in range(1, n+1)]

answer = []
for _ in range(n):
    answer.append(int(input()))

sign = []

cmp = [0] * n 
tmp = []  
i = 0
for num in nums:
    if num != answer[i]:
        tmp.append(num)
        sign.append('+')

    else:
        tmp.append(num)
        sign.append('+')
        while True:
            if num == n or len(tmp) == 0:
                break
            
            if tmp[-1] == answer[i]:
                cmp[i] = tmp.pop()
                sign.append('-')
                i += 1
            
            else:
                break

while tmp:
    cmp[i] = tmp.pop()
    sign.append('-')
    i += 1

flag = True
for i in range(n):
    if cmp[i] == answer[i]:
        continue
    else:
        flag = False
        break

if flag:
    print(*sign)

else:
    print('NO')
