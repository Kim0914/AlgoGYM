def calc_five(n):
    five = 0

    while n != 0:
        n = n // 5
        five += n

    return five


def calc_two(n):
    two = 0

    while n != 0:
        n = n // 2
        two += n
    
    return two


n, m = map(int, input().split())

two_count = calc_two(n) - calc_two(n - m) - calc_two(m)
five_count = calc_five(n) - calc_five(n - m) - calc_five(m)
print(min(two_count, five_count))
