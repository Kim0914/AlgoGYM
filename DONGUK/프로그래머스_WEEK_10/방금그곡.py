def calcTime(start, end):
    start = start.split(':')
    start = int(start[0]) * 60 + int(start[1])
    
    end = end.split(':')
    end = int(end[0]) * 60 + int(end[1]) 
    
    return abs(end - start)
    

def solution(m, musicinfos):
    answer = ''
    
    cmp = []
    for n in m:
        if n == '#':
            cmp.append(cmp.pop() + n)
        else:
            cmp.append(n)
    
    musicinfos.sort(key = lambda x : x[0])
    
    max_time = 0
    for infos in musicinfos:
        info = infos.split(',')
        start, end, title, notes = info[0], info[1], info[2], info[3]
        time = calcTime(start, end) # 분
        
        note = []
        for n in notes:
            if n == '#':
                note.append(note.pop() + n)
            else:
                note.append(n)
        
        
        q = time // len(note)
        r = time % len(note)
        
        tmp = note * q + note[:r]
        
        cnt = 0
        for i in range(len(tmp)):
            if tmp[i] == cmp[cnt]:
                cnt += 1
                
                if cnt == len(cmp):
                    if time > max_time:
                        max_time = time
                        answer = title
                    break
            
            else:
                if tmp[i] == cmp[cnt-1]:
                    continue
                    
                cnt = 0
    
    if not answer:
        answer = "(None)"
        
    return answer