def solution(s):
    answer = []
    eng_dict = {'zero':'0', 'one':'1', 'two':'2', 
                'three':'3', 'four':'4', 'five':'5',
                'six':'6', 'seven':'7', 'eight':'8', 'nine':'9'}
    
    for i in range(len(s)):
        if s[i] in eng_dict.values():
            answer.append(s[i])
        if s[i].isalpha:
            for key in eng_dict.keys():
                j = len(key)
                if key in s[i:i+j]:
                    answer.append(eng_dict[key])
        
    answer = int(''.join(answer))  
    return answer
