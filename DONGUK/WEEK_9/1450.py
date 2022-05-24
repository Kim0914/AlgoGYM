import sys, math
import itertools

input = sys.stdin.readline

N, C = map(int, input().split()) # 물건 N개, 최대 C 무게의 가방
weights = list(map(int, input().split()))

# 집합에서 모든 부분집합을 구해, C보다 작은 부분집합들을 모은 리스트 반환
def findSub(arr):
    sub = []
    for select in range(len(arr) + 1):
        pool = map(sum, itertools.combinations(arr, select))

        for p in pool:
            if p <= C:
                sub.append(p)
    
    return sub


# Right 집합의 원소(item)에 대해, A에서 탐색하며 가방안에 들어갈 수 있는 가장 큰 인덱스 반환
def getPair(arr, item):
    if item > C:
        return 0

    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = (start + end) // 2

        target = arr[mid] + item

        if target <= C:
            start = mid + 1
        
        else:
            end = mid - 1

    return start

left = weights[:N//2]
right = weights[N//2:]

left_sum = findSub(left)
right_sum = findSub(right)

left_sum.sort()

cnt = 0
for right in right_sum:
    cnt += getPair(left_sum, right)

print(cnt)

