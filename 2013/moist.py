import sys
import itertools


ts = sys.stdin.readlines()
ts = [i[:-1] for i in ts][1:]
ts = ['' if i.isnumeric() else i for i in ts]
ds = [list(i[1]) for i in itertools.groupby(ts, lambda i: i=='') if not i[0]]
for case, t in enumerate(ds):
  cost = 0
  for i in range(len(t)):
    if i != 0 and t[i] < t[i-1]:
      j = i
      while j != 0 and t[j] < t[j-1]:
        _ = t[j]
        t[j] = t[j-1]
        t[j-1] = _
        j -= 1
      cost += 1
  print(f'Case #{case+1}: {cost}')  
