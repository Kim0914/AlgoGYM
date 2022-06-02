def solution(id_list, report, k):
    report = list(set(report))
    
    answer = []

    caller_list= {} # 사람, 편지받는 횟수 
    count_list = {} # 신고당한 횟수
    receivers = []
    dict_list = []

    for data in id_list:
        caller_list[data] = 0
        count_list[data] = 0
    
    for data in report:
        dt = data.split()
        receivers.append(dt[1])
        dict_list.append(list((dt[0], dt[1])))
    
    
    for name, cnt in count_list.items():
        if name in receivers:
            cnt = receivers.count(name)
            count_list[name] = cnt

    singo = []
    for name, cnt in count_list.items():
        if cnt >= k:
            singo.append(name)


    for data in dict_list:
        if data[1] in singo:
            cnt = caller_list.get(data[0]) + 1
            caller_list[data[0]] = cnt

    answer = list(caller_list.values())
        
    return answer