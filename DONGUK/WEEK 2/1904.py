import sys
input = sys.stdin.readline

N = int(input())

dp = [0] * 1000001
dp[1] = 1
dp[2] = 2

for i in range(3, N+1):
    dp[i] = (dp[i-2] + dp[i-1]) % 15746

print(dp[N])
'''
N = 1 -> 1              
N = 2 -> 00, 11        
N = 3 -> 001, 100, 111  
N = 4 -> 0000, 0011, 1001, 1100, 1111
N = 5 -> 00001, 10000, 00111, 10011, 11001, 11100, 11111 

'''