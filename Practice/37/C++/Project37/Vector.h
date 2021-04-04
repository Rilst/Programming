#pragma once
#include "Point.h"

class Vector{
private:
    double x, y;
public:
    Vector(): x(1), y(0){}
    Vector(Point end): x(end.get_x()), y(end.get_y()){}
    Vector(Point begin, Point end): x(end.get_x()-begin.get_x()), y(end.get_y()-begin.get_y()){}

    double length(){
        return sqrt(pow(x,2)+pow(y,2));
    }

    friend bool operator== (const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, const double b);
    friend double operator*(const Vector& a, const Vector& b);

};

bool operator== (const Vector& a, const Vector& b) {
    if ((round(a.x * Rn) / Rn) == (round(b.x * Rn) / Rn) && (round(a.y * Rn) / Rn) == (round(b.y * Rn) / Rn)) {
        return true;
    }
    else return false;
}

Vector operator-(const Vector& a){
    Vector Invert(Point(-a.x, -a.y));
    return Invert;
}

Vector operator-(const Vector& a, const Vector& b){
    Vector Subtraction(Point((a.x - b.x), (a.y - b.y)));
    return Subtraction;
}

Vector operator+(const Vector& a, const Vector& b){
    Vector Summation(Point((a.x + b.x), (a.y + b.y)));
    return Summation;
}

Vector operator*(const Vector& a, const double b){
    Vector Multiplication(Point((a.x * b), (a.y * b)));
    return Multiplication;
}

double operator*(const Vector& a, const Vector& b){
    double MultiplicationByNum = (a.x * b.x) + (a.y * b.y);
    return MultiplicationByNum;
}

