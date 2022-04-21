import sys, math
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    page = list(map(int, input().split()))

    dp = [[0] * n for _ in range(n)]
    for j in range(1, n):
        for i in range(j-1, -1, -1): # 대각선 행렬(자기자신)은 0이기 때문에 계산 X
            small = math.inf
            for k in range(j-i):
                idx = i + k
                small = min(small, dp[i][i+k] + dp[i+k+1][j])
            dp[i][j] = small + sum(page[i:j+1])
    
    print(dp[0][n-1])

'''
    A   B   C   D   E
A   0  A+B
B       0  B+C
C           0
D               0
E

p에서 q까지 합치는 경우는 다음과 같다.
p에서 방문할 지점을 r이라고 하면 시작점 p에서 r지점까지 합치는 비용 + 그 다음지점 r+1 부터 마지막 지점 q 까지 합치는 비용이다.
그 비용들 중에서 가장 작은 비용을 선택한다.
f(p, q) = (f(p, p) + f(p+1, q)) or (f(p, p+1) + f(p+2, q)) or ....

예를 들어서 f(A, C)는 
1) A,A -> B,C => A+B + (A+B+C)
2) A,B -> C,C => B+C + (A+B+C) 
2개중에 작은 값을 선택하면 구할 수 있다

'''