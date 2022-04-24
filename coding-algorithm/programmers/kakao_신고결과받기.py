from collections import Counter

def solution(id_list, report, k):
    
    report = list(set(report)) # 중복 없애기
    reported = [] # 신고받은사람
    id_dict = dict.fromkeys(id_list, 0) #신고한사람
    
    reported = [i.split(' ')[1] for i in report]
    cnt_reported = [key for key, val in Counter(reported).items() if val >= k] #신고 k 넘은 사람
    
    for i in report:
        if i.split(' ')[1] in cnt_reported:
            id_dict[i.split(' ')[0]] += 1
    
    answer = list(id_dict.values())
    return answer
