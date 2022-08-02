def solution(price, money, count):
    answer = 0

    cnt = 1
    for i in range(count):
        answer += price * cnt
        cnt += 1

    if money - answer > 0:
        return 0

    answer = abs(money - answer)


    return answer
