import copy
from collections import deque
from itertools import permutations

def preProcess(expression):
    opers = deque()
    numbers = deque()
    tmp = ''
    for s in expression:
        if s == '*' or s == '-' or s == '+':
            if s not in opers:
                opers.append(s)
                
            numbers.append(int(tmp))
            numbers.append(s)
            tmp = ''
        else:
            tmp += s
    numbers.append(int(tmp))
    
    opers = list(permutations(opers, len(opers)))
    
    return numbers, opers

def solution(expression):
    answer = 0
    o = ['*', '+', '-']
    values = []
    numbers, opers = preProcess(expression)
    
    for oper in opers:
        stack = []
        data = copy.deepcopy(numbers)
        for j in range(len(oper)):
            c = oper[j]
            
            i = 0
            while i < len(data):
                if data[i] not in o:
                    stack.append(data[i])
                else:
                    if data[i] == c:
                        oper1 = stack.pop()
                        i += 1
                        oper2 = data[i]
                        
                        if c == '*':
                            stack.append(oper1 * oper2)
                        elif c == '+':
                            stack.append(oper1 + oper2)
                        else:
                            stack.append(oper1 - oper2)
                    else:
                        stack.append(data[i])
                i += 1
            data = stack
            if j == len(oper) - 1:
                values.append(abs(stack[0]))
            stack = []
            
    
    
    answer = max(values)
    return answer