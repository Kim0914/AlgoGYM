cnt = 0

def bt(board, col, n):
    
    global cnt
    
    if col == n+1:
        cnt += 1
        
        return
    
    for val in range(1, n+1):
        flag = True
        for i in range(1, col):
            if board[i] == val:
                flag = False
                break
            
            if abs((val - board[i]) / (col - i)) == 1:
                flag = False
                break
        
        if flag == False:
            continue
                
        board[col] = val
        bt(board, col+1, n)
        board[col] = 0
            

def solution(n):
    answer = 0
    board = [0] * (n+1)
    
    if n == 1:
        return 1
    
    bt(board, 1, n)
    answer = cnt
    return answer