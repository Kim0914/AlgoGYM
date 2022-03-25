# dp를 기록하는 변수가 이차원으로 해결 가능한 풀이
a = input().rstrip().upper()
b = input().rstrip().upper()

dp = [[0] * (len(b) + 1) for _ in range(len(a) + 1)]


# 0번째 행과 0번째 열은 계산을 위해서 비워둠
for i in range(1, len(a)+1):
    for j in range(1, len(b)+1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[-1][-1])


# ------------------------------------------------------------ #
# dp를 기록하는 변수가 일차원으로 해결 가능한 풀이 

s1 = input().rstrip()
s2 = input().rstrip()

l1, l2 = len(s1), len(s2)

cache = [0] * max(l1, l2)

for i in range(l1):
    cnt = 0
    for j in range(l2):
        if cnt < cache[j]:
            cnt = cache[j]
        
        elif s1[i] == s2[j]:
            cache[j] = cnt + 1
print(max(cache))