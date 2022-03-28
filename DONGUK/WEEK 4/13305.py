import sys
input = sys.stdin.readline

n = int(input())
load_list = list(map(int, input().split()))
oil_price = list(map(int, input().split()))

ans = 0
now_price = oil_price[0]
for i in range(len(load_list)):
    if i == 0:
        ans += now_price * load_list[i]
    
    else:
        if oil_price[i] <= now_price:
            now_price = oil_price[i]
            ans += now_price * load_list[i]
        
        else:
            ans += now_price * load_list[i]

print(ans)