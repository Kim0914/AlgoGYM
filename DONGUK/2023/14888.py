import sys, math

input = sys.stdin.readline

oper_dict = {0: '+', 1: '-', 2: 'x', 3: '/'}
N = int(input())
nums = list(map(int, input().split()))
operator = list(map(int, input().split()))

operators = []
for i in range(4):
    if operator[i] > 0:
        for _ in range(operator[i]):
            operators.append(oper_dict[i])
arr = []
visited = [0] * (N-1)
min_ans = math.inf
max_ans = -math.inf
def calc(arr):
    global min_ans, max_ans
    if len(arr) == N-1:
        sum_ = nums[0]
        for j in range(N-1):
            right_operand = nums[j+1]
            oper = arr[j]
            if oper == '+':
                sum_ = (sum_ + right_operand)
            elif oper == '-':
                sum_ = (sum_ - right_operand)
            elif oper == 'x':
                sum_ = (sum_ * right_operand)
            else:
                if sum_ < 0:
                    sum_ = -(abs(sum_) // right_operand)
                else:
                    sum_ = (sum_ // right_operand)
        min_ans = min(min_ans, sum_)
        max_ans = max(max_ans, sum_)
        return
    
    for i in range(len(operators)):
        if visited[i] == 0:
            arr.append(operators[i])
            visited[i] = 1
            calc(arr)
            visited[i] = 0
            arr.pop(-1)
        
calc(arr)
print(max_ans)
print(min_ans)