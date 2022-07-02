def solution(info, query):
    answer = []
    
    info_dict = {}

    for lang in ['cpp', 'java', 'python', "-"]:
        for job in ['backend', 'frontend', "-"]:
            for career in ['junior', 'senior', "-"]:
                for food in ['chicken', 'pizza', "-"]:
                    info_dict[lang + job + career + food] = []

    
    for data in info:
        data = data.split(" ")
        for lang in [data[0], "-"]:
            for job in [data[1], "-"]:
                for career in [data[2], "-"]:
                    for food in [data[3], "-"]:
                        info_dict[lang + job + career + food].append(int(data[4]))
    
    
    for key in info_dict.keys():
        info_dict[key].sort()
        
    
    for q in query:
        q = q.replace('and', '')
        q = q.split()
        
        score = int(q[-1])
        condition = "".join(q[:-1])
        
        candidates = info_dict[condition]
        
        
        # 하나도 탐색못하는 경우, 전부 다 빼줘야 함
        ind = len(candidates)
        
        start, end = 0, len(candidates) - 1
        while start <= end:
            mid = (start + end) // 2
            
            if score <= candidates[mid]:
                ind = mid
                end = mid - 1
                
            else:
                start = mid + 1
        
        answer.append(len(candidates) - ind)
    
    return answer