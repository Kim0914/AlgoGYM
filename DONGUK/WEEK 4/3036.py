def gcd(a, b):
    if b == 0:
        return a
    
    else:
        return gcd(b, a%b)


def make_pair(a, b):
    if a % b == 0:
        q = a // b
        return str(q) + '/1'
    
    else:
        div = gcd(a, b)
        q = a // div
        r = b // div
        return str(q) + '/' + str(r)


n = int(input())

nums = list(map(int, input().split()))

ans = []
for i in range(1, n):
    ret = make_pair(nums[0], nums[i])
    ans.append(ret)

for data in ans:
    print(data)
