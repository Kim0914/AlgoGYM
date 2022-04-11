n = int(input())

board = [list(map(int, input().split())) for _ in range(n)]
minus, zero, one = 0, 0 ,0

def check(x, y, size):
    global minus, zero, one

    num = board[x][y]

    if size == 1:
        if num == -1:
            minus += 1
        
        elif num == 0:
            zero += 1

        else:
            one += 1

        return
    
    flag = True
    for i in range(x, x+size):
        for j in range(y, y+size):
            if board[i][j] != num:
                flag = False
                break
    
    if flag:
        if num == -1:
            minus += 1
        
        elif num == 0:
            zero += 1

        else:
            one += 1
        
    else:
        size = size // 3
        check(x, y, size)
        check(x, y+size, size)
        check(x, y+2*size, size)

        check(x+size, y, size)
        check(x+size, y+size, size)
        check(x+size, y+2*size, size)

        check(x+2*size, y, size)
        check(x+2*size, y+size, size)
        check(x+2*size, y+2*size, size)


check(0, 0, n)
print(minus)
print(zero)
print(one)