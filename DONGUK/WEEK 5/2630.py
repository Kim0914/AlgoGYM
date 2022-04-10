n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
blue_cnt, white_cnt = 0, 0

def check(x, y, size):
    global blue_cnt, white_cnt

    color = board[x][y]

    if size == 1:
        if board[x][y] == 1:
            blue_cnt += 1
        
        else:
            white_cnt += 1
        
        return

    flag = True
    for i in range(x, x+size):
        for j in range(y, y+size):
            if board[i][j] != color:
                flag = False
                break
    
    if flag:
        if color == 1:
            blue_cnt += 1
        
        else:
            white_cnt += 1
    
    else:
        size = size // 2
        check(x,y,size)
        check(x+size, y, size)
        check(x, y+size, size)
        check(x+size, y+size, size)

flag = True
color = board[0][0]
for i in range(n):
    for j in range(n):
        if board[i][j] != color:
            flag = False

if flag != True:
    for i in range(0, n, n//2):
        for j in range(0, n, n//2):
            check(i, j, n//2)
else:
    if color == 1:
        blue_cnt += 1

    else:
        white_cnt += 1
        
print(white_cnt)
print(blue_cnt)
