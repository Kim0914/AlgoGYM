import sys
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
opers = list(map(int, input().split()))  # +, -, *, / 순서

max_v = -1e9
min_v = 1e9

def bt(ind, val):
    global max_v, min_v
    if ind == N:
        
        max_v = max(max_v, val)
        min_v = min(min_v, val)
        return
    
    else:
        if opers[0] > 0: # 더하기
            opers[0] -= 1
            bt(ind+1, val + nums[ind])
            opers[0] += 1

        if opers[1] > 0: # 빼기
            opers[1] -= 1
            bt(ind+1, val - nums[ind])
            opers[1] += 1

        if opers[2] > 0: # 곱하기
            opers[2] -= 1 
            bt(ind+1, val * nums[ind])
            opers[2] += 1

        if opers[3] > 0: # 나누기
            opers[3] -= 1
            
            if val < 0:
                bt(ind+1, -((-val) // nums[ind]))
            
            else:
                bt(ind+1, val // nums[ind])
            
            opers[3] += 1
            

bt(1, nums[0])

print(max_v)
print(min_v)