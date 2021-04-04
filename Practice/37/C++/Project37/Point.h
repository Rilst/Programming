#pragma once
#include <cmath>
#include <iostream>

const auto Rn = 10000000000;

enum coord_sys{
    Polar,
    Cartesian
};

class Point{
private:
    double x_r, y_phi;
    coord_sys type_coords;

public:
    Point(double a1 = 0, double a2 = 0, coord_sys coord_system = Cartesian): x_r(a1), y_phi(a2), type_coords(coord_system){}

    double get_x(){
        if (type_coords == Cartesian){
            return x_r;
        }
        else{
            return get_r()*cos(get_phi());
        }
    }

    double get_y(){
        if (type_coords == Cartesian){
            return y_phi;
        }
        else{
            return get_r()*sin(get_phi());
        }
    }

    void set_x(double x){
        if (type_coords == Cartesian){
            x_r = x;
        }
        else{
            set_r(x);
        }
    }

    void set_y(double y){
        if (type_coords == Cartesian){
            y_phi = y;
        }
        else{
            set_phi(y);
        }
    }

    double get_r(){
        if (type_coords == Cartesian){
            return sqrt((get_x() * get_x()) + (get_y()*get_y()));
        }
        else{
            return x_r;
        }
    }

    double get_phi(){
        if (type_coords == Cartesian){

            if (get_x() > 0) return atan(get_y() / get_x());
            else if (get_x() < 0 && get_y() > 0) return atan(get_y() / get_x()) + M_PI;
            else if (get_x() < 0 && get_y() < 0) return atan(get_y() / get_x()) - M_PI;
            else if (get_x() == 0 && get_y() > 0) return M_PI/2;
            else if (get_x() == 0 && get_y() < 0) return -M_PI/2;
            else return 0;

        }
        else{
            return y_phi;
        }
    }

    void set_r(double r){
        if (type_coords == Cartesian){
            double buf = get_phi();
            x_r = r;
            y_phi = buf;
            type_coords = Polar;

        }
        else{
            x_r = r;
        }
    }

    void set_phi(double phi){
        if (type_coords == Cartesian){
            y_phi = get_r() * sin(phi);
            x_r = get_r() * cos(phi);
        }
        else{
            y_phi = phi;
        }
    }

    friend bool operator== (Point& a, Point& b);
    friend bool operator!= (Point& a, Point& b);
    friend std::ostream& operator<< (std::ostream& out, Point& a);
    friend std::istream& operator>> (std::istream& in, Point& a);
};

bool operator== (Point& a, Point& b) {
    if ((round(a.get_x() * Rn) / Rn) == (round(b.get_x() * Rn) / Rn) && (round(a.get_y() * Rn) / Rn) == (round(b.get_y() * Rn) / Rn)) {
        return true;
    }
    else return false;
}
bool operator!= (Point& a, Point& b) {
    if ((round(a.get_x() * Rn) / Rn) != (round(b.get_x() * Rn) / Rn) && (round(a.get_y() * Rn) / Rn) != (round(b.get_y() * Rn) / Rn)) {
        return true;
    }
    else return false;
}
std::ostream& operator<< (std::ostream& out, Point& a) {
    out << "(" << a.get_x() << "," << a.get_y() << ")\n";
    return out;
}
std::istream& operator>> (std::istream& in, Point& a) {
    std::string String, Y, X;
    in >> String;

    size_t start = String.find('(');
    size_t dot = String.find(',');
    size_t end = String.find(')');

    X = String.substr(start+1, dot-1);
    Y = String.substr(dot+1, end-1);

    a.set_x(atoi(X.c_str()));
    a.set_y(atoi(Y.c_str()));

    return in;
}
