from math import atan, sin, cos, sqrt, pi

class Point:
    def __init__(self, a1 = 0, a2 = 0, coord_system = "Cartesian"):
        if isinstance(a1, str) and (not(a1.isdigit())):
            slist = a1.split(',')
            self.x_r = float(slist[0][1:])
            self.y_phi = float(slist[1][:len(slist[1])-1])
            self.type_coords = "Cartesian"
        elif isinstance(a1, str) and a1.isdigit() or isinstance(a1, int) or isinstance(a1, float):
            if coord_system == "Polar":
                self.type_coords = "Polar"
                self.x_r = float(a1)
                self.y_phi = float(a2)
            elif coord_system == "Cartesian":
                self.type_coords = "Cartesian"
                self.x_r = float(a1)
                self.y_phi = float(a2)
                
    def get_x(self) -> float:
        if self.type_coords == "Cartesian":
            return self.x_r
        else:
            return self.get_r()*cos(self.get_phi())
            
    def get_y(self) -> float:
        if self.type_coords == "Cartesian":
            return self.y_phi
        else:
            return self.get_r()*sin(self.get_phi())
            
    def set_x(self, x: float):
        if self.type_coords == "Cartesian":
            self.x_r = x
        else:
            self.set_r(x)
            
    def set_y(self, y: float):
        if self.type_coords == "Cartesian":
            self.y_phi = y
        else:
            self.set_phi(y)
            
    def get_r(self) -> float:
        if self.type_coords == "Cartesian":
            return sqrt((self.get_x() * self.get_x()) + (self.get_y()*self.get_y()))
        else:
            return self.x_r
    
    def get_phi(self) -> float:
        if self.type_coords == "Cartesian":
            if (self.get_x() > 0): return atan(self.get_y() / self.get_x())
            elif (self.get_x() < 0 and self.get_y() > 0): return atan(self.get_y() / self.get_x()) + pi
            elif (self.get_x() < 0 and self.get_y() < 0): return atan(self.get_y() / self.get_x()) - pi
            elif (self.get_x() == 0 and self.get_y() > 0): return pi/2
            elif (self.get_x() == 0 and self.get_y() < 0): return -pi/2
            else: return 0
        else:
            return self.y_phi

    def set_r(self, r: float):
        if self.type_coords == "Cartesian":
            buf = self.get_phi()
            self.x_r = r
            self.y_phi = buf
            self.type_coords = "Polar"
        else:
            self.x_r = r
            
    def set_phi(self, phi: float):
        if self.type_coords == "Cartesian":
            self.y_phi = self.get_r() * sin(phi);
            self.x_r = self.get_r() * cos(phi);
        else:
            self.y_phi = phi;
    
    def __eq__(self, other):
        if (round(self.get_x(), 10) == round(other.get_x(), 10)) and (round(self.get_y(), 10) == round(other.get_y(), 10)):
            return True
        else:
            return False

    def __str__(self):
        return "({},{})".format(self.get_x(), self.get_y())
        
    def __repr__(self):
        return "({},{})".format(self.get_x(), self.get_y())
