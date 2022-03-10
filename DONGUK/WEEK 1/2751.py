import heapq
import sys

def heapsort(array):
    h = []
    result = []
    # 모든 원소를 차례대로 힙에 삽입
    for value in array:
        heapq.heappush(h, value)
    # 힙에 삽입된 모든 원소를 차례대로 꺼내어 담기
    for _ in range(len(h)):
        result.append(heapq.heappop(h))
    return result

input = sys.stdin.readline

N = int(input())

arr = []
for _ in range(N):
    arr.append(int(input()))

res = heapsort(arr)

for r in res:
    print(r, end = ' ')