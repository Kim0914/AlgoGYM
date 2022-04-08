from collections import deque

T = int(input())

for _ in range(T):
    

    N, pos = map(int, input().split())
    nice = list(map(int, input().split()))

    key_val = []
    for i in range(N):
        key_val.append([str(i), nice[i]])

    q = deque(key_val)
    
    
    if N == 1:
        print(1)
    
    else:
        cnt = 0
        while True:
            max_val = max(nice)
            if q[0][1] == max_val:
                if q[0][0] == str(pos):
                    cnt += 1
                    break
                
                q.popleft()
                nice.remove(max_val)
                cnt += 1
            
            else:
                tmp = q.popleft()
                q.append(tmp)

        print(cnt)