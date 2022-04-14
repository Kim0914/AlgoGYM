n = int(input())
dp = dict()

p = 1000000007

def fibo(num):
    if dp.get(num) != None:
        return dp[num]

    if num == 0:
        return 0
    
    if num == 1 or num == 2:
        return 1

    else:
        if num % 2 == 0: # 짝수인 경우
            dp[num // 2 + 1] = fibo(num // 2 + 1) % p
            dp[num // 2 - 1] = fibo(num // 2 - 1) % p
            return (dp[num // 2 + 1] ** 2 - dp[num // 2 - 1] ** 2) % p

        else:
            dp[num // 2 + 1] = fibo(num // 2 + 1) % p
            dp[num // 2] = fibo(num // 2) % p
            return (dp[num // 2 + 1] ** 2 + dp[num // 2] ** 2) % p
        
print(fibo(n))