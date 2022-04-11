n = int(input())
board = [list(input())for _ in range(n)]

ans = ''
def check(x, y, size):
    global ans

    if size == 1:
        if board[x][y] == '0':
            ans += '0'

        else:
            ans += '1'

        return

    flag = True
    num = board[x][y]
    for i in range(x, x+size):
        for j in range(y, y+size):
            if board[i][j] != num:
                flag = False
                break

    if flag:
        if num == '1':
            ans += '1'
        
        else:
            ans += '0'
    
    else:
        size = size // 2
        ans += '('
        check(x, y, size)
        check(x, y+size, size)
        check(x+size, y, size)
        check(x+size, y+size, size)
        ans += ')'


check(0,0,n)
print(ans)