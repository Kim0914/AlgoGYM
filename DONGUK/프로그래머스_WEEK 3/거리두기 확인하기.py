def search(place):
    # 상하좌우 1칸, 2칸, 대각선
    passed = [[0] * 5 for _ in range(5)]
    
    dx = [1, -1, 0, 0, 2, -2, 0, 0, 1, 1, -1, -1] 
    dy = [0, 0, 1, -1, 0, 0, 2, -2, 1, -1, 1, -1]
    for x in range(5):
        for y in range(5):
            if place[x][y] == 'P':
                for i in range(12):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    
                    if 0 <= nx < 5 and 0 <= ny < 5:
                        if place[nx][ny] == 'P':
                            if passed[nx][ny] == 1:
                                continue
                            
                            if (abs(nx-x) + abs(ny-y)) == 1: # 붙어있는 경우
                                return False
                            
                            else:
                                if (x == nx) or (y == ny): # 같은 행 or 열
                                    if x == nx:
                                        if place[nx][(y+ny) // 2] == 'O':
                                            return False
                                    elif y == ny:
                                        if place[(x+nx)//2][ny] == 'O':
                                            return False
                                        
                                else: # 대각선
                                    if (nx-x) == 1 and (ny-y) == 1:
                                        if place[x+1][y] == 'X' and place[x][y+1] == 'X':
                                            continue
                                        else:
                                            return False
                                    
                                    elif (nx-x) == 1 and (ny-y) == -1:
                                        if place[x+1][y] == 'X' and place[x][y-1] == 'X':
                                            continue
                                        else:
                                            return False
                                        
                                    elif (nx-x) == -1 and (ny-y) == 1:
                                        if place[x-1][y] == 'X' and place[x][y+1] == 'X':
                                            continue
                                        else:
                                            return False
                                    
                                    elif (nx-x) == -1 and (ny-y) == -1:
                                        if place[x-1][y] == 'X' and place[x][y-1] == 'X':
                                            continue
                                        else:
                                            return False
            passed[x][y] = 1

    return True
                                    
                                            
    

def solution(places):
    answer = []
    
    for place in places:
        ret = search(place)
        print(ret)
    
    return answer