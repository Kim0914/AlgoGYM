def solution(dirs):
    answer = 0
    visited = []
    
    x, y = 0, 0
    for c in dirs:
        p_x, p_y = x, y
        if c == 'U':
            if y < 5:
                y += 1
            else:
                continue
                
        elif c == 'D':
            if y > -5:
                y -= 1
            else:
                continue
        
        elif c == 'L':
            if x > -5:
                x -= 1
            else:
                continue
            
        else:
            if x < 5:
                x += 1
            else:
                continue
        
        if (p_x, p_y, x, y) not in visited and (x, y, p_x, p_y) not in visited:
            visited.append((p_x, p_y, x, y))
            answer += 1
            
    return answer