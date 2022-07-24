def solution(line):
    answer = []
    
    candidate = []
    for i in range(len(line)):
        a1, b1, c1 = line[i][0], line[i][1], line[i][2]
        for j in range(i+1, len(line)):
            
            a2, b2, c2 = line[j][0], line[j][1], line[j][2]
            
            x, y = 0, 0
            if (a1*b2) - (b1*a2) == 0:
                continue
            x = (b1*c2-c1*b2) / (a1*b2 - b1*a2)
            y = (c1*a2-a1*c2) / (a1*b2 - b1*a2)
            
            if int(x) == x and int(y) == y:
                if (x, y) not in candidate:
                    candidate.append((int(x), int(y)))
    
                                     
    candidate.sort(key = lambda x : x[0])
    minx, maxx = candidate[0][0], candidate[-1][0]
    
    candidate.sort(key = lambda x : x[1])
    miny, maxy = candidate[0][1], candidate[-1][1]
    
    
    
    arr = [["." for j in range(maxx - minx+1)] for i in range(maxy - miny+1)]
    
    for x, y in candidate: 
        r, c = y - miny, x - minx
        
        arr[r][c] = "*"
        
    return ["".join(item) for item in arr][::-1]
