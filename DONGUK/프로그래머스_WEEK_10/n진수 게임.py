def convert(num, base):
    tmp = '0123456789ABCDEF'
    q = num // base
    r = num % base

    ret_str = tmp[r]

    if q == 0:
        return tmp[r]

    while q > 0:
        r = q % base
        q = q // base
        ret_str += tmp[r]

    ret_str = ret_str[::-1]
    return ret_str


def solution(n, t, m, p):
    answer = ''
    allCase = ''

    myTurn = []
    for i in range(m*t): # 숫자는 0부터 시작
        allCase += convert(i,n)

        if i == p-1: # 순서는 1부터 시작
            myTurn.append(i)
            p += m
    
    for turn in myTurn:
        answer += allCase[turn]

    return answer