import sys
input = sys.stdin.readline

def calc(data):
    N = data[0]
    dp = [0] * (N + 1)

    same_area = 0
    same_flag = False
    diff_cnt = 1
    for i in range(1, N+1):
        if i == 1:
            dp[i] = data[1]

        else:
            diff = data[i] - data[i-1]
            if data[i-1] < data[i]: # 이전의 수 보다 큰 경우
                same_flag = False
                if diff == 1:
                    diff_cnt += 1
                    
                
                else:
                    diff_cnt = 0
                    dp[i] = max(data[i] , data[i-1] * 2)

            
            elif data[i-1] == data[i]: # 같은 경우
                if same_flag == False:
                    same_area = data[i-1]
                    same_flag = True

                dp[i] = dp[i-1] + same_area
            
            else: # 작은 경우
                same_flag = False
                if diff == -1:
                    diff_cnt += 1
                    dp[i] = max(dp[i-1], data[i] * diff_cnt)
            
                else:
                    diff_cnt = 0
                    dp[i] = data[i] * 2
    print(dp)
    return max(dp)


while True:
    data = list(map(int, input().split()))

    if len(data) == 1 and data[0] == 0:
        break
    
    print(calc(data))






        





'''
[1000, ]
'''
        


