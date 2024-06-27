import sys, heapq

input = sys.stdin.readline

W, N = map(int, input().split())

germs = []

for _ in range(N):
    weight, price = map(int, input().split())
    # germs.append((weight, price))
    heapq.heappush(germs, (-price, -weight))

# germs.sort(key = lambda x : (x[1], x[0]), reverse = True)

answer = 0
cur_weight = 0
while cur_weight < W:
    if not germs:
        break
    # top = germs.pop(0)
    top = heapq.heappop(germs)
    germ_weight, germ_price_unit = -top[1], -top[0]

    if germ_weight <= W - cur_weight:
        answer += (germ_weight * germ_price_unit)
        cur_weight += germ_weight
    else:
        answer += ((W - cur_weight) * germ_price_unit)
        cur_weight += (W - cur_weight)

print(answer)