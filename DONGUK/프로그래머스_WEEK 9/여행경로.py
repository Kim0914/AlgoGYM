from collections import deque
import copy

cities = {}
ticket_cnt = {}
answer = []


def search(arr, now, visited, N):
    if len(arr) == N+1:
        arr_cp = copy.deepcopy(arr)  
        answer.append(arr_cp)
        return
    
    if now not in cities:
        return
    
    candidate = cities[now]
    candidate.sort()
    
    for next_city in candidate:
        if (now, next_city) not in visited or ticket_cnt[(now, next_city)] > 0:
            arr.append(next_city)
            visited.append((now, next_city))
            ticket_cnt[(now, next_city)] -= 1
            search(arr, next_city, visited, N)
            visited.remove((now, next_city))
            ticket_cnt[(now, next_city)] += 1
            arr.pop()

        

def solution(tickets):
    global answer
    
    for start, end in tickets:
        if start not in cities:
            cities[start] = [end]
            
        else:
            cities[start].append(end)

        if (start, end) not in ticket_cnt:
            ticket_cnt[(start, end)] = 1

        else:
            ticket_cnt[(start, end)] += 1
    
    
    search(["ICN"], "ICN", [], len(tickets))
    
    answer.sort()
    
    answer = answer[0]
    
    return answer
    

