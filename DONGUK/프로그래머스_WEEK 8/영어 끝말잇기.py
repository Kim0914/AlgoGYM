def solution(n, words):
    answer = []
    
    used_word = []
    N = len(words)

    used_word.append(words[0])
    last_word = words[0][-1]

    person, trial = 0,0
    answer.append(person)
    answer.append(trial)
    for i in range(1,N):
        start_word = words[i][0]
        if words[i] not in used_word and start_word == last_word:
            used_word.append(words[i])
            last_word = words[i][-1]
        
        else:
            person = ((i%n) + 1)
            trial = ((i//n) + 1)
            answer[0] = person
            answer[1] = trial
            break

    return answer