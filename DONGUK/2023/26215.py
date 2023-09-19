import sys, heapq

input = sys.stdin.readline

N = int(input())

houses = list(map(int, input().split()))

time = 0
heap = []
for house in houses:
    heapq.heappush(heap, -house)

while time <= 1440:
    if not heap:
        break
    
    next_house = []
    for i in range(2):
        if heap:
            house = -heapq.heappop(heap)
            house -= 1

            if house > 0:
                next_house.append(house)
    
    for house in next_house:
        heapq.heappush(heap, -house)
    
    time += 1

if time > 1440:
    print(-1)
else:
    print(time)