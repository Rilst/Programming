from Point import Point
from math import sqrt

class Vector:
    def __init__(self, begin = None, end = None):
        if (begin is None) and (end is None):
            self.x = 1
            self.y = 0
        elif (begin is not None) and (end is None):
            self.x = begin.get_x()
            self.y = begin.get_y()
        elif (begin is not None) and (end is not None):
            self.x = end.get_x()-begin.get_x()
            self.y = end.get_y()-begin.get_y()
    
    def __neg__(self):
        Invert = Vector(Point(-self.x, -self.y))
        return Invert
    
    def __add__(self, other):
        Summation = Vector(Point(self.x + other.x, self.y + other.y))
        return Summation
    
    def __sub__(self, other):
        Subtraction = Vector(Point(self.x - other.x, self.y - other.y))
        return Subtraction
    
    def __mul__(self, other):
        if isinstance(other, Vector):
            MultiplicationByVector = (self.x * other.x) + (self.y * other.y)
            return MultiplicationByVector
        elif isinstance(other, int) or isinstance(other, float):
            MultiplicationByNum = Vector(Point(self.x * other, self.y * other))
            return MultiplicationByNum
    
    def length(self):
        Length = sqrt(pow(self.x,2)+pow(self.y,2))
        return Length
    
    def __eq__(self, other):
        if (round(self.x, 10) == round(other.x, 10)) and (round(self.y, 10) == round(other.y, 10)):
            return True
        else:
            return False