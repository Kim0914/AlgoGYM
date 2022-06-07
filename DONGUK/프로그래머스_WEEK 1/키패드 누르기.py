keypad = {'1':(0,0), '2':(0,1), '3':(0,2), 
          '4':(1,0), '5':(1,1), '6':(1,2), 
          '7':(2,0), '8':(2,1) ,'9':(2,2), 
          '*':(3,0), '0':(3,1), '#':(3,2)}

def getDistance(now, target):
    now_x, now_y = keypad[now]
    tar_x, tar_y = keypad[target]
    
    return abs(tar_x - now_x) + abs(tar_y - now_y)

def solution(numbers, hand):
    answer = ''
    
    now_left, now_right = '*', '#'
    for num in numbers:
        num = str(num)
        
        if num == '1' or num == '4' or num == '7':
            answer += 'L'
            now_left = num
        
        elif num == '3' or num == '6' or num == '9':
            answer += 'R'
            now_right = num
        
        else:
            left_dis = getDistance(now_left, num)
            right_dis = getDistance(now_right, num)

            if left_dis > right_dis:
                answer += 'R'
                now_right = num

            elif left_dis < right_dis:
                answer += 'L'
                now_left = num

            else:
                if hand == "right":
                    answer += 'R'
                    now_right = num

                else:
                    answer += 'L'
                    now_left = num
            
    return answer