from collections import deque
import sys

input = sys.stdin.readline

T = int(input())


for _ in range(T):
    p = list(input().rstrip())
    n = int(input())
    nums = deque(input().rstrip()[1:-1].split(","))
    
    flag = True
    rev_cnt = 0
    for c in p:
        if c == 'R':
            rev_cnt += 1

        elif c == 'D':
            if len(nums) == 0 or n == 0:
                print('error')
                flag = False
                break

            else:
                if rev_cnt % 2 == 0:
                    nums.popleft()
                else:
                    nums.pop()

    # 짝수번 뒤집는 것은 의미가 없음
    # 몇 번 뒤집는 지 카운트해서 홀수이면 뒤집기
    if flag:
        if rev_cnt % 2 == 1:
            nums.reverse()
        print('[' + ','.join(nums) + ']')