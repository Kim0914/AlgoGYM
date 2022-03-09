N = int(input())

answer = []
cnt = 0
for i in range(666, 100000000):
    nums = str(i)

    if '666' in nums:
        cnt += 1
        answer.append(i)
    
    if cnt == N:
        break

    
print(answer[N-1])

'''
666
1666
2666
3666
'''