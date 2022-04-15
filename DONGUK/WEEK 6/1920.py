n = int(input())
data = list(map(int, input().split()))
data.sort()

m = int(input())
nums= list(map(int, input().split()))

for num in nums:
    start, end = 0, n-1
    
    while start <= end:
        mid = (start + end) // 2

        if data[mid] == num:
            print(1)
            break
    
        elif data[mid] < num:
            start = mid + 1
        
        else:
            end = mid - 1
    
    if start > end:
        print(0)