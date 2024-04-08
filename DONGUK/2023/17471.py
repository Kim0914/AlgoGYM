from collections import deque
import math

INF = math.inf

def comb(nums, cnt):
    result = []
    if cnt == 0:
        return [[]]
    for i in range(len(nums)):
        elementary = nums[i]
        rest_nums = nums[i+1:]
        for c in comb(rest_nums, cnt - 1):
            result.append([elementary] + c)
    return result

def bfs(graph, cities):
    q = deque()
    q.append(cities[0])

    cnt = 0
    visited = set()
    visited.add(cities[0])
    while q:
        top = q.popleft()

        cnt += 1

        neighbors = graph[top]
        for neigbor in neighbors:
            if neigbor not in visited and neigbor in cities:
                visited.add(neigbor)
                q.append(neigbor)

    return cnt

N = int(input())
humans = list(map(int, input().split()))
graph = [[] for _ in range(N+1)]

for i in range(N):
    data = list(map(int, input().split()))
    cnt = data[0]
    if cnt == 0:
        continue

    neighbors = data[1::]
    graph[i+1] = neighbors

answer = INF
nums = [i for i in range(1, N+1)]
left, right = 1, N-1
while left <= right:
    left_nums = comb(nums, left)
    for left_data in left_nums:
        right_data = list(set(nums) - set(left_data))
        left_city_cnt = bfs(graph, left_data)
        right_city_cnt = bfs(graph, right_data)
        # print(left_data, right_data, left_city_cnt, right_city_cnt)
        if left_city_cnt + right_city_cnt == N:
            left_human_cnt = 0
            for l in left_data:
                left_human_cnt += humans[l - 1]
            
            right_human_cnt = 0
            for r in right_data:
                right_human_cnt += humans[r - 1]
            
            answer = min(answer, abs(left_human_cnt - right_human_cnt))
    left += 1
    right -= 1

if answer == INF:
    answer = -1

print(answer)