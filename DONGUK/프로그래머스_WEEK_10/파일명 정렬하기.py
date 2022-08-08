def solution(files):
    answer = []
    
    candidate = []
    ind = 0
    for file in files:
        origin = file
        file = file.lower()
        head, number, tail = '', '', ''
        
        i = 0
        while i < len(file):
            if '0' <= file[i] <= '9':
                break
                
            else:
                head += file[i]
                i += 1
                
                
        while i < len(file):
            if 'a' <= file[i] <= 'z' or file[i] == '.' or file[i] == ' ' or file[i] == '-':
                break
                
            else:
                number += file[i]
                i += 1
                
                if len(number) >= 5:
                    break
        
        candidate.append([origin, head, int(number), ind])
        ind += 1
    
    candidate.sort(key = lambda x: (x[1], x[2], x[3]))
    
    for data in candidate:
        answer.append(data[0])
        
    return answer