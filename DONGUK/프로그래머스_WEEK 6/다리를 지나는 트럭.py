from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    
    N = len(truck_weights)
    
    bridge = deque([0] * bridge_length)
    truck_weights = deque(truck_weights)
    
    passed = []
    truck_cnt = 0
    sum_bridge = 0
    while True:
        if len(passed) == N:
            break
        
        top = bridge.popleft()
        
        if top > 0:
            passed.append(top)
            truck_cnt -= 1
            sum_bridge -= top
        
        if truck_cnt <= bridge_length:
            if truck_weights and sum_bridge + truck_weights[0] <= weight:
                sum_bridge += truck_weights[0]
                bridge.append(truck_weights.popleft())
                truck_cnt += 1
        
            else:
                bridge.append(0)
                
        answer += 1
    
    return answer