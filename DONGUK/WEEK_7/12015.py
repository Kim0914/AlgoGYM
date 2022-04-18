import sys
input = sys.stdin.readline

def search_index(arr, data):
    start, end = 0, len(arr)

    ind = 0
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] < data:
            start = mid + 1
        
        else:
            ind = mid
            end = mid - 1
    
    return ind

n = int(input())

nums = list(map(int, input().split()))

stack = []
for i in range(n):
    if i == 0:
        stack.append(nums[i])
        continue
    
    if nums[i] > stack[-1]:
        stack.append(nums[i])

    else:
        ind = search_index(stack, nums[i])

        if ind >= len(stack):
            stack.append(nums[i])
        
        else:
            stack[ind] = nums[i]

print(len(stack))



'''
1. 인덱스
2. 값이 정해져 있으면 값을 조절하거나
3. 주어진 제한 조건이 있으면 그 제한 조건을 조절하거나


INPUT: 10 20 25 50 15 30

STACK: 15 20 25 30

-> 만들 수 없는 수열이지만, 길이를 정하는 문제이기 때문에
-> 스택의 top 아래에 있는 값들은 어떤 값이든지 증가하는 순서만 맞으면 OK.
-> 즉 스택의 top값은 올 수 있는 값들 중 최소값이 오는게 좋다 why? 그래야 다음 숫자로 올 수 있는 수의 범위가 커짐

'''
