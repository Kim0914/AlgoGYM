def gcd(a, b):
    if b == 0:
        return a
    
    else:
        return gcd(b, a%b)



num1, num2 = map(int, input().split())

a = max(num1, num2)
b = min(num1, num2)
ret = gcd(b, a%b)

print(ret)
print(a * b // ret)