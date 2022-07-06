def solution(clothes):
    answer = 1
    
    d = {}
    
    for cloth in clothes:
        name, typ = cloth[0], cloth[1]
        
        if typ not in d:
            d[typ] = 1
        
        else:
            d[typ] += 1
    
    for cnt in d.values():
        answer = answer * (cnt + 1)
    
    answer -= 1
    return answer