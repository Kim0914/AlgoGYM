import sys

input = sys.stdin.readline

N = int(input())

datas = []
for _ in range(N):
    price, delivery = map(int, input().split())
    datas.append((price, delivery))


datas = list(set(datas))
datas.sort(key = lambda x: (x[0], x[1]))

max_profit = 0
min_price = 999999999
for i in range(len(datas)):
    my_price, my_delivery = datas[i][0], datas[i][1]
    profit = max(0, my_price - my_delivery)
    for j in range(len(datas)):
        if i == j:
            continue
        other_price, other_delivery = datas[j][0], datas[j][1]

        if other_price < my_price:
            continue

        if my_price < other_delivery:
            continue
        
        profit += (my_price - other_delivery)
    
    if profit >= max_profit:
        if profit == max_profit:
            min_price = min(min_price, my_price)
        else:
            min_price = my_price
        max_profit = profit

if max_profit == 0:
    print(0)
else:
    print(min_price)