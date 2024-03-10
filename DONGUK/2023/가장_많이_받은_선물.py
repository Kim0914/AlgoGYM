def solution(friends, gifts):
    answer = 0
    gift_history = {}
    send_rank = {}
    receive_rank = {}

    for friend in friends:
        send_rank[friend] = 0
        receive_rank[friend] = 0

    for gift in gifts:
        gift = gift.split()
        sender, receiver = gift[0], gift[1]
        send_rank[sender] += 1
        receive_rank[receiver] += 1
        
        if (sender, receiver) not in gift_history:
            gift_history[(sender, receiver)] = 1
            gift_history[(receiver, sender)] = 0
        else:
            gift_history[(sender, receiver)] += 1
    
    
    N = len(friends)
    for i in range(N):
        f1 = friends[i]
        cnt = 0
        for j in range(N):
            if i == j:
                continue
                
            f2 = friends[j]

            if (f1, f2) in gift_history:
                if gift_history[(f1, f2)] > gift_history[(f2, f1)]:
                    cnt +=1
                    
                elif gift_history[(f1, f2)] == gift_history[(f2, f1)]:
                    f1_rank = send_rank[f1] - receive_rank[f1]
                    f2_rank = send_rank[f2] - receive_rank[f2]
                    if f1_rank > f2_rank:
                        cnt += 1
                else:
                    continue
            
            else:
                f1_rank = send_rank[f1] - receive_rank[f1]
                f2_rank = send_rank[f2] - receive_rank[f2]
                
                if f1_rank > f2_rank:
                    cnt += 1
        
        answer = max(answer, cnt)
    return answer