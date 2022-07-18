def solution(n):
    answer = []

    snail_row = [[0 for j in range(1, i+1)] for i in range(1, n+1)]
    
    cnt = 0
    for i in range(1,n+1):
        cnt += i
    
    
    x, y = 0, 0
    flag = 0
    next_dir = n-1
    for num in range(1, cnt+1):
        snail_row[x][y] = num
        
        if flag == 0: # 왼쪽 아래로 진행
            x += 1

            if num == next_dir: # 방향을 바꿔야되는 경우
                flag = 1
                n -= 1
                next_dir = next_dir + n


        elif flag == 1: # 오른쪽으로 진행
            y += 1

            if num == next_dir:
                flag = 2
                n -= 1
                next_dir = next_dir + n

        
        elif flag == 2: # 왼쪽 상단으로 진행
            x -= 1
            y -= 1

            if num == next_dir:
                flag = 0
                n -= 1
                next_dir = next_dir + n

    
    for row in snail_row:
        for data in row:
            answer.append(data)
        
    return answer