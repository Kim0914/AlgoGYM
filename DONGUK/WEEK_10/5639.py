import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

nums = []

def init():
    while True:
        try:
            nums.append(int(input()))
        
        except:
            break

def search(start, end):
    if start > end:
        return

    root = nums[start]
    right_ind = end + 1
    for i in range(start + 1, end + 1):
        if nums[i] > root:
            right_ind = i
            break
        
    # (start + 1 ~ right_ind - 1) -> 왼쪽 서브트리
    # (right_ind ~ end) -> 오른쪽 서브트리
    
    search(start + 1, right_ind - 1)
    search(right_ind, end)
    print(nums[start])

init()
search(0, len(nums) - 1)

'''
50 30 24 5 28 45 98 52 60

'''
# 