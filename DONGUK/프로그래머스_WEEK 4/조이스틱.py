def getOrd(name, i):
    return min(abs(ord(name[i])) - ord('A'), abs(ord('Z') - ord(name[i]) + 1))

def solution(name):
    answer = 0
    init = []
    name = list(name)
    
    for i in range(len(name)):
        init.append('A')
    
    visited = [0] * len(name)
    
    i = 0
    while True:
        if init[i] != name[i]:
            answer += getOrd(name, i)
            visited[i] = 1
        
        else:
            visited[i] = 1
            
        if sum(visited) == len(name):
            break
        
        left, right = 1, 1
        while True:
            if name[i - left] != init[i - left]:
                break
            else:
                left += 1
        

        while True:
            if name[i + right] != init[i + right]:
                break
            else:
                right += 1
        
        
        if left < right:
            answer += left
            i += -left
            
        else:
            answer += right
            i += right
    
    return answer

print(solution("JAN"))