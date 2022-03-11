# 파이썬 str list 사용
num = int(input())

num_list = sorted(list(str(num)), reverse=True)

for data in num_list:
    print(data, end='')

# 몫, 나머지 계산 이용
num = int(input())

n_len = len(str(num)) - 1
div = 10 ** (n_len)

res = []
for _ in range(n_len + 1):
    res.append(str(num // div))
    num = num % div
    div = div // 10
    
answer = "".join(sorted(res, reverse=True)).rstrip()
print(answer)




