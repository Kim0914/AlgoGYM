def solution(name):
    answer = 0
    
    # 기본 최소 좌우이동 횟수는 길이 - 1
    min_move = len(name) - 1
    
    for i, char in enumerate(name):
        answer += min(ord(char) - ord('A'), ord('Z') - ord(char) + 1)
        
        # 해당 알파벳 다음부터 연속된 A 문자열 찾기
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
            
        # 기존, 연속된 A의 왼쪽시작 방식, 연속된 A의 오른쪽시작 방식 비교 및 갱신
        min_move = min([min_move, 2 *i + len(name) - next, i + 2 * (len(name) -next)])
        
    # 알파벳 변경(상하이동) 횟수에 좌우이동 횟수 추가
    answer += min_move
    return answer

# 71점 받는 풀이 -> 현재 위치에서 변경해야 할 가장 가까운 인덱스를 찾아서 이동하는 풀이인데 안됨
# def solution(name):
#     answer = 0
#     N = len(name)
    
#     ind_list = []
    
#     target = 'A' * N
    
#     for i in range(N):
#         if name[i] != target[i]:
#             diff_a = abs(ord(name[i]) - ord(target[i]))
#             diff_b = abs(ord('Z') - ord(name[i]) + 1)
#             ind_list.append(min(diff_a, diff_b))
#         else:
#             ind_list.append(0)
    
    
#     if not ind_list:
#         return answer
    
    
#     answer += sum(ind_list)
    
#     ind = 0
#     while True:
#         ind_list[ind] = 0
        
#         if sum(ind_list) == 0:
#             break

#         left, right = 1, 1
#         while ind_list[ind - left] == 0:
#             left += 1
        
#         while ind_list[ind + right] == 0:
#             right += 1
        
#         if left < right:
#             answer += left
#             ind -= left
            
#         else:
#             answer += right
#             ind += right
        
#     return answer