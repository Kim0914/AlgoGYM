import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
stack = deque()

result = [-1] * n
for i in range(n):
    while stack:
        if nums[i] > nums[stack[-1]]:
            result[stack.pop()] = nums[i]            
        else:
            break
        
    stack.append(i)

print(*result)



# import sys
# input = sys.stdin.readline

# n = int(input())

# nums = list(map(int, input().split()))

# ans = []
# stack = []
# for i in range(n-1, -1, -1):
#     if i == n-1:
#         ans.append(-1)
#         stack.append(nums[-1])
    
#     else:
#         if nums[i] < nums[i+1]: # 다음에 오는 숫자가 증가하는 경우 바로 오큰수 찾음
#             ans.append(nums[i+1])
#             stack.append(nums[i+1])
        
#         else: # 다음에 오는 숫자가 작거나 같은 경우, 현재 까지 스택의 값을 탐색
#             flag = False
#             for j in range(len(stack)-1, -1, -1):
#                 if nums[i] < stack[j]:
#                     ans.append(stack[j])
#                     flag = True
#                     break
            
#             if flag == False:
#                 ans.append(-1)
            

# print(*ans[::-1])