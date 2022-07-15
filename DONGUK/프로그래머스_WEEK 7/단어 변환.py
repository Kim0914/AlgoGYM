import heapq

def solution(begin, target, words):
    answer = 0
    
    words_dict = {}
    alpha = {}
    
    for i in range(len(target)):
        alpha[i] = []
    
    for word in words:
        for i in range(len(word)):
            if word[i] not in alpha[i]:
                alpha[i].append(word[i])
                
        if word not in words_dict:
            words_dict[word] = 1
    
    
    if target not in words_dict:
        return 0
    
    
    q = []
    heapq.heappush(q, (0, begin))
    
    while q:
        cnt, word = heapq.heappop(q)
        
        if word == target:
            answer = cnt
            break
        
        
        for i in range(len(word)):
            for c in alpha[i]:
                if word[i] != c:
                    tmp = list(word)
                    tmp[i] = c
                    candidate = "".join(tmp)
                    
                    if candidate in words_dict:
                        heapq.heappush(q, (cnt+1, candidate))
            
    return answer