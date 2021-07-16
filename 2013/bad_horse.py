T = int(input())
for i in range(1, T+1):
  pos = 'No'
  cases = int(input())
  l = []
  l.append({})
  for _ in range(cases):
    p1, p2 = input().split()
    j, k = 0, 1
    while j < k:
      d = l[j]
      if p1 not in d and p2 not in d:
        d2 = d.copy()
        d2[p1] = False
        d2[p2] = True
        l.append(d2)
        d[p1] = True
        d[p2] = False
        k += 1
      elif p1 in d and p2 not in d:
        d[p2] = not d[p1]
      elif p1 not in d and p2 in d:
        d[p1] = not d[p2]
      j += 1
    l = [d for d in l if d[p1] != d[p2]]
  if l:
    pos = 'Yes'
  print(f'Case #{i}: {pos}')
