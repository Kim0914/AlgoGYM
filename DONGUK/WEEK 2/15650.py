import sys
input = sys.stdin.readline

N, M = map(int, input().split())
nums = []

def search():
    if len(nums) == M:
        for i in range(M):
            if i != M-1:
                print(nums[i], end=' ')
            
            else:
                print(nums[i])

    else:
        for i in range(1, N+1):
            if i not in nums:
                if len(nums) == 0 or i > nums[-1]:
                    nums.append(i)
                    search()
                    nums.pop()

search()