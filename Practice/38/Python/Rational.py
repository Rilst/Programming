import math

class Rational:
    def __init__(self, numerator, denominator):
        if (numerator is None) and (denominator is None):
            self.Result = 0
        elif (numerator is not None) and (denominator is None):
            self.a = numerator
            self.b = 1
            self.Result = numerator
        elif (numerator is not None) and (denominator is not None):
            self.a = numerator
            self.b = denominator
            if (numerator == 0) and (denominator == 0):
                self.Result = float('nan')
            elif (numerator > 0) and (denominator == 0):
                self.Result = float('inf')
            elif (numerator < 0) and (denominator == 0):
                self.Result = float('-inf')
            elif denominator != 0:
                self.Result = numerator/denominator
    
    @staticmethod
    def gcd(a, b):
        nod = 1;
        Start = a;
        if a == 0: Start = b;
        for i in range(Start, 0, -1):
            if (a % i == 0 and b % i == 0):
                nod = i;
                break;
        return nod;
    
    def isNaN(self):
        if math.isnan(self.Result): return True
        else: return False
        
    def isInf(self):
        if math.isinf(self.Result): return True
        else: return False

    def isInfPos(self):
        if math.isinf(self.Result) and self.a > 0: return True
        else: return False

    def isInfNeg(self):
        if math.isinf(self.Result) and self.a < 0: return True
        else: return False

    def numerator(self):
        return self.a

    def denominator(self):
        return self.b
    
    def __add__(self, second):
        if (not(self.isNaN()) and not(second.isNaN()) and not(self.isInf()) and not(second.isInf()) and self.b != second.b):
            result = Rational((self.a * second.b) + (second.a * self.b), (self.b * second.b))
            return result
        elif(not(self.isNaN()) and not(second.isNaN()) and not(self.isInf()) and not(second.isInf()) and self.b == second.b):
            result = Rational((self.a + second.a), second.b)
            return result
        elif (self.isNaN() or second.isNaN()):
            result = Rational(0, 0)
            return result
        elif (self.isInfNeg() and second.isInfPos()):
            result = Rational(0, 0)
            return result
        elif (self.isInfPos() and second.isInfNeg()):
            result = Rational(0, 0)
            return result
        elif (self.isInfNeg() and second.isInfNeg()): return self
        elif (self.isInfPos() and second.isInfPos()): return self
        elif ((self.isNaN() or self.isInf()) and (not(second.isNaN()) and not(second.isInf()))): return self
        elif ((not(self.isNaN() and not(self.isInf()))) and (second.isNaN() or second.isInf())): return second
        
    def __eq__(self, second):
        if (self.isNaN() or second.isNaN()): return False
        elif (self.Result == second.Result): return True
        else: return False
    
    def __sub__(self, second):
        if (not(self.isNaN()) and not(second.isNaN()) and not(self.isInf()) and not(second.isInf()) and self.b != second.b):
            result = Rational((self.a * second.b) - (second.a * self.b), (self.b * second.b))
            return result
        
        elif(not(self.isNaN()) and not(second.isNaN()) and not(self.isInf()) and not(second.isInf()) and self.b == second.b):
            result = Rational((self.a - second.a), second.b)
            return result
        
        elif (self.isInfNeg() and second.isInfNeg()):
            result = Rational(0, 0)
            return result
        
        elif (self.isInfPos() and second.isInfPos()):
            result = Rational(0, 0)
            return result
        
        elif (self.isNaN() or second.isNaN()):
            result = Rational(0, 0)
            return result
        
        elif (self.isInfNeg() and second.isInfPos()): return self
        elif (self.isInfPos() and second.isInfNeg()): return self
        elif ((self.isNaN() or self.isInf()) and (not(second.isNaN()) and not(second.isInf()))): return self
        elif ((not(self.isNaN()) and not(self.isInf())) and (second.isNaN() or second.isInf())):
            result = Rational(-second.a, 0)
            return result
    
    def __mul__(self, second):
        result = Rational((self.a * second.a), (self.b * second.b))
        return result
    
    def __truediv__(self, second):
        if ((self.isNaN() or self.isInf()) and (not(second.isNaN()) and not(second.isInf()))):
            if (second.a < 0):
                result = Rational(-self.a, self.b)
                return result
            else:
                return self
        else:
            result = Rational((self.a * second.b), (self.b * second.a))
            return result
            
    def __float__(self):
        return float(self.Result)
        
    def __bool__(self):
        if self.Result == 0:
            return False
        else:
            return True

