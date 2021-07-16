from math import asin, degrees
from decimal import Decimal

G = Decimal(9.8)
t = int(input())
for i in range(1, int(t+1)):
  v, d = map(Decimal, input().split())
  angle = round(0.5*degrees(asin(d*G/v**2)), 7)
  print(f'Case #{i}: {angle}')
