day_count = 1

TEN = 600
EIGHTEEN = 1080


def conv_to_min(text):
    values = list(map(int, text.split(':')))
    return values[0]*60 + values[1]


def conv_from_minutes(m):
    hour = m // 60
    minutes = m % 60
    
    return f'{hour} hours and {minutes} minutes' if hour else f'{minutes} minutes'


def to_format(m):
    hour = m // 60
    minutes = str(m % 60).zfill(2)
    
    return f'{hour}:{minutes}'

while True:
    try:
        n_tasks = int(input())
        
        schedule = []
        while(n_tasks):
            init, end, *rest = input().split(' ')
            schedule.append((conv_to_min(init), conv_to_min(end)))
            n_tasks -= 1
            
        schedule.sort(key=lambda tup: (tup[0], tup[1]))
        sch = [TEN]
        
        for a, b in schedule:
            sch.append(a)
            sch.append(b)
            
        sch.append(EIGHTEEN)
        
        #print(sch)
        start_at = -1
        duration = -1 
        
        for i in range(0, len(sch)-1):
            if i % 2:
                continue
            
            aux = sch[i+1] - sch[i]
            #print(f'{sch[i+1]} {sch[i]} - {aux}')
            if (duration == -1 and aux) or aux > duration:
                duration = aux
                start_at = i
        
        print(
            f'Day #{day_count}: the longest nap starts at {to_format(sch[start_at])} and will last for {conv_from_minutes(duration)}.')
            
        day_count += 1
    except EOFError:
        break
