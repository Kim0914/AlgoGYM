def getNumToAdd(hands, target):
    for hand in hands:
        if target - hand in hands:
            return hand
    return -1

def solution(coin, cards):
    answer = 0
    
    hands = set()
    trash = set()
    n = len(cards)
    target = n+1

    for _ in range(n//3):
        card = cards.pop(0)
        hands.add(card)
    
    while True:
        answer += 1
        # print('hands ', hands, ' trash ', trash)
        if not cards:
            break
            
        card1 = cards.pop(0)
        card2 = cards.pop(0)
        trash.add(card1)
        trash.add(card2)

        # 코인 0개 사용 -> 손에 있는 패 털기
        num = getNumToAdd(hands, target)
        if num > 0:
            hands.remove(num)
            hands.remove(target - num)
            continue
                
        # 코인 1개 사용 -> 손에 있는 카드 1개, 휴지통에서 1개
        flag = False
        for card in hands:
            if target - card in trash and coin >= 1:
                trash.remove(target - card)
                hands.remove(card)
                coin -= 1
                flag = True
                break
        
        if flag:
            continue
            
        if coin >= 2:
            card = getNumToAdd(trash, target)
            if card != -1:
                trash.remove(card)
                trash.remove(target - card)
                coin -= 2
                continue

        break
            
    return answer