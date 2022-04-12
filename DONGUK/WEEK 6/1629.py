a, b, c = map(int, input().split())

def calc (a,b):
    if b == 1:
        return a % c

    else:
        tmp = calc(a, b//2)

        if b % 2 ==0:
            
            return (tmp * tmp) % c

        else:
            
            return (tmp  * tmp * a) % c

print(calc(a, b))

'''
a = 10, b = 10, c = 12
10^10 = 10^5 * 10^5 = (10^2 * 10^2 * 10) % 12 x (10^2 * 10^2 * 10) % 12
'''
