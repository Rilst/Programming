from Point import Point
import math
import copy

with open('data.txt') as fin:
    original = [Point(p) for p in fin.readline().split(', ')]
  
simulacrum = copy.deepcopy(original)
for p in simulacrum:
    print(p, end='')
    p.set_x(p.get_x() + 10)
    p.set_phi(p.get_phi() + 180*math.pi/180)
    p.set_y(-p.get_y())
    p.set_x(-p.get_x() - 10)
    print(p)
  
print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')
