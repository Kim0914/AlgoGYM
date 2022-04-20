import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    nums = list(map(int, input().split()))

    dp = [0] * n


'''
2
4
40 30 30 50

40 30 = 70
30 50 = 80
70 80 = 150


15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32

알바 끝나고 다시 할게여,,,
'''