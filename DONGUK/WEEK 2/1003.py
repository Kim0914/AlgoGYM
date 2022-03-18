import sys
input = sys.stdin.readline

T = int(input())

dp = [[1,0], [0,1]]

def fibo(num, target):
    if num == target:
        x, y = (dp[num-2][0] + dp[num-1][0]), (dp[num-2][1] + dp[num-1][1])
        dp.append([x,y])
        print(dp[-1][0], dp[-1][1])
        return
    
    else:
        x, y = (dp[num-2][0] + dp[num-1][0]), (dp[num-2][1] + dp[num-1][1])
        dp.append([x,y])
        fibo(num+1, target)


        

for _ in range(T):
    target = int(input())
    
    if target == 0:
        print(dp[0][0], dp[0][1])
    
    elif target == 1:
        print(dp[1][0], dp[1][1])

    else:
        fibo(2, target)

    dp = [[1,0], [0,1]]