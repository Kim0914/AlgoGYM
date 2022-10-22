from collections import deque

def solution(order):
    answer = 0
    now = 1
    max_val = max(order)
    
    truck = []
    box = []
    
    i = 0
    while True:
        if now > max_val:
            break
            
        if now == order[i]:
            truck.append(order[i])
            now += 1
            i += 1
        
        else:
            if box:
                while box and box[-1] == order[i]:
                    box.pop()
                    truck.append(order[i])
                    i += 1
                    
                
            box.append(now)        
            now += 1
    
    while box:
        top = box.pop()
        
        if top == order[i]:
            truck.append(top)
            i += 1
        
        else:
            break
            
    answer = len(truck)
    return answer