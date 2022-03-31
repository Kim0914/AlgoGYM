import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    
    else:
        return gcd(b, a%b)

n = int(input())
nums = []


for _ in range(n):
    nums.append(int(input()))

nums.sort()

diff_list = []
for i in range(1, n):
    diff_list.append(nums[i] - nums[i-1])

diff_list.sort(reverse=True)

ret = diff_list[0]
for i in range(1, len(diff_list)):
    ret = gcd(ret, diff_list[i])

ans = []
for i in range(2, int(ret ** 1/2) + 1):
    if ret % i == 0:
        ans.append(i)
        ans.append(ret//i)
ans.append(ret)

ans = list(set(ans))
ans.sort()
print(*ans)

'''
pypy3로 통과
'''

