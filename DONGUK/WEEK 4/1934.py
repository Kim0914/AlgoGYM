def gcd(a, b):
    if b == 0:
        return a
    
    else:
        return gcd(b, a%b)

n = int(input())

for _ in range(n):
    num1, num2 = map(int, input().split())

    a = max(num1, num2)
    b = min(num1, num2)
    ret = gcd(b, a%b)

    print(a * b // ret)