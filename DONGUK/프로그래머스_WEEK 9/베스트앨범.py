def solution(genres, plays):
    answer = []
    
    genre_dict = {}
    genre_count_dict = {}
    for i in range(len(genres)):
        if genres[i] not in genre_dict:
            genre_dict[genres[i]] = [(i, plays[i])]
            genre_count_dict[genres[i]] = plays[i]
            
        else:
            genre_dict[genres[i]].append((i, plays[i]))
            genre_count_dict[genres[i]] += plays[i]
    
    
    genre_counts = list(genre_count_dict.items())

    genre_counts.sort(key=lambda x : x[1], reverse=True)
    
    for genre in genre_counts:
        data = genre_dict[genre[0]]
        
        data.sort(key = lambda x : (x[1], -x[0]), reverse = True)
        
        for i in range(len(data)):
            if i >= 2:
                break
                
            answer.append(data[i][0])
    

    return answer