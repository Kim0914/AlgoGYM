def check(i,j, board):
    c = board[i][j]

    if c == '.':
        return False
    
    if  c == board[i][j+1] and c == board[i+1][j] and c == board[i+1][j+1]:
        return True
    else:
        return False    

def solution(m, n, board):
    answer = 0
    # 전처리
    for i in range(len(board)):
        board[i] = list(board[i])

    while True:
        checked = [[0] * n for _ in range(m)]

        # 같은 캐릭터 체크
        for i in range(m-1):
            for j in range(n-1):
                if check(i,j,board):
                    checked[i][j] = 1
                    checked[i+1][j] = 1
                    checked[i][j+1] = 1
                    checked[i+1][j+1] = 1

        cnt = 0
        for data in checked:
            cnt += data.count(1)  

        if cnt == 0:
            break

        answer += cnt

        for j in range(n):
            for i in range(m):
                if checked[i][j] == 1:
                    x, y = i, j
                    while x >= 0:
                        if x == 0:
                            board[x][y] = '.'
                            break
                        else:
                            board[x][y] = board[x-1][y]
                            x = x - 1
    return answer