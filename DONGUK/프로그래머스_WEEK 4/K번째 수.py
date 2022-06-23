def solution(array, commands):
    answer = []
    for start, end, target in commands:
        data = array[start-1:end]
        data.sort()
        answer.append(data[target-1])
    return answer