def solution(survey, choices):
    answer = ''
    
    d = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    
    for i in range(len(survey)):
        ch1, ch2 = survey[i][0], survey[i][1]
        choice = choices[i]
        
        if 1 <= choice <= 3:
            d[ch1] += 4 - choice
        
        elif 5 <= choice <= 7:
            d[ch2] += choice - 4
    
    candidates = [('R', 'T'), ('C', 'F'), ('J', 'M'), ('A', 'N')]
    
    for candidate in candidates:
        first, second = candidate[0], candidate[1]
        
        if d[first] >= d[second]:
            answer += first
        else:
            answer += second
            
    return answer