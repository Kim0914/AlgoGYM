from collections import deque

d = {}
import math

INF = math.inf


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def search(board, N):
    q = deque()
    q.append([(0, 0), (0, 1), False, 0])
    min_val = INF
    
    while q:
        top = q.popleft()
        pos1, pos2, flag, cnt = top[0], top[1], top[2], top[3]
        
        # if cnt > min_val:
        #     continue
        
        if pos1 == (N-1, N-1) or pos2 == (N-1, N-1):
            min_val = min(min_val, cnt)
            continue
        
        if (pos1, pos2) in d or (pos2, pos1) in d:
            if cnt >= d[(pos1, pos2)]:
                continue
            
        d[(pos1, pos2)] = cnt
        
        x1, y1 = pos1[0], pos1[1]
        x2, y2 = pos2[0], pos2[1]
        
        for i in range(4):
            nx1, ny1 = x1 + dx[i], y1 + dy[i]
            nx2, ny2 = x2 + dx[i], y2 + dy[i]
            
            if 0 <= nx1 < N and 0 <= ny1 < N:
                if 0 <= nx2 < N and 0 <= ny2 < N:
                    if board[nx1][ny1] == 0 and board[nx2][ny2] == 0:
                        q.append([(nx1, ny1), (nx2, ny2), flag, cnt+1])
        
        
        if flag == False: # 가로방향 -> 세로방향
            # pos1을 돌림
            rx1, ry1 = x1 + 1, y1
            rx2, ry2 = x1 + 1, y1 + 1
            
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(x2, y2), (rx2, ry2), True, cnt+1])
                        
            rx1, ry1 = x1 - 1, y1
            rx2, ry2 = x1 - 1, y1 + 1
            
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(rx2, ry2), (x2, y2), True, cnt+1])
            
            
            # pos2를 돌림
            rx1, ry1 = x2 + 1, y2
            rx2, ry2 = x2 + 1, y2 - 1
            
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(x1, y1), (rx2, ry2), True, cnt+1])
                        
                        
            rx1, ry1 = x2 - 1, y2
            rx2, ry2 = x2 - 1, y2 - 1
            
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(rx2, ry2), (x1, y1), True, cnt+1])
        
        
        else: # 세로방향 -> 가로방향
            rx1, ry1 = x1, y1 + 1
            rx2, ry2 = x1 + 1, y1 + 1
                    
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(x2, y2), (rx2, ry2), False, cnt+1])
            
            
            
            rx1, ry1 = x1, y1 - 1
            rx2, ry2 = x1 + 1, y1 - 1
            
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(rx2, ry2), (x2, y2), False, cnt+1])
                        
                        
            rx1, ry1 = x2, y2 - 1
            rx2, ry2 = x2 - 1, y2 - 1
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(rx2, ry2), (x1, y1), False, cnt+1])
            
            
            rx1, ry1 = x2, y1 - 1
            rx2, ry2 = x2 - 1, y2 + 1
            if 0 <= rx1 < N and 0 <= ry1 < N:
                if 0 <= rx2 < N and 0 <= ry2 < N:
                    if board[rx1][ry1] == 0 and board[rx2][ry2] == 0:
                        q.append([(x1, y1), (rx2, ry2), False, cnt+1])
            
    return min_val

def solution(board):
    answer = 0
    
    N = len(board)
    answer = search(board, N)
        
    return answer