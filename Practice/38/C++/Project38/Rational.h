#pragma once
#include <cmath>

class Rational{
private:
    double a, b, Result;
public:
    Rational(): Result(0){}
    Rational(int first, int second): a(first), b(second), Result(static_cast<double>(first)/static_cast<double>(second)){}

    operator double() {
        return Result;
    }
    operator bool() {
        if (Result  == 0)
            return false;
        else
            return true;
    }

    static int gcd(int a, int b) {
        int nod = 1;
        int Start = a;
        if (a == 0) Start = b;

        for (int i = Start; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                nod = i;
                break;
            }
        }
        return nod;
    }

    bool isNaN() const{
        if(std::isnan(Result)) return true;
        else return false;
    }

    bool isInf() const{
        if(std::isinf(Result)) return true;
        else return false;
    }

    bool isInfPos() const{
        if(std::isinf(Result) && a > 0) return true;
        else return false;
    }

    bool isInfNeg() const{
        if(std::isinf(Result) && a < 0) return true;
        else return false;
    }

    double numerator(){
        return a;
    }

    double denominator(){
        return b;
    }

    friend bool operator==(const Rational &first, const Rational &second);
    friend Rational operator+(const Rational &first, const Rational &second);
    friend Rational operator-(const Rational &first, const Rational &second);
    friend Rational operator*(const Rational &first, const Rational &second);
    friend Rational operator/(const Rational &first, const Rational &second);

};

bool operator==(const Rational &first, const Rational &second){
    if (first.isNaN() || second.isNaN()) return false;
    else if (first.Result == second.Result) return true;
    else return false;
}

Rational operator+(const Rational &first, const Rational &second){
    if (!first.isNaN() && !second.isNaN() && !first.isInf() && !second.isInf() && first.b != second.b){
       Rational result((first.a * second.b) + (second.a * first.b), (first.b * second.b));
       return result;
    }
    else if(!first.isNaN() && !second.isNaN() && !first.isInf() && !second.isInf() && first.b == second.b){
        Rational result((first.a + second.a), second.b);
        return result;
    }
    else if (first.isNaN() || second.isNaN()){
        Rational result(0, 0);
        return result;
    }
    else if (first.isInfNeg() && second.isInfPos()){
        Rational result(0, 0);
        return result;
    }
    else if (first.isInfPos() && second.isInfNeg()){
        Rational result(0, 0);
        return result;
    }
    else if (first.isInfNeg() && second.isInfNeg()) return first;
    else if (first.isInfPos() && second.isInfPos()) return first;
    else if ((first.isNaN() || first.isInf()) && (!second.isNaN() && !second.isInf())) return first;
    else if ((!first.isNaN() && !first.isInf()) && (second.isNaN() || second.isInf())) return second;
}

Rational operator-(const Rational &first, const Rational &second){
    if (!first.isNaN() && !second.isNaN() && !first.isInf() && !second.isInf() && first.b != second.b){
       Rational result((first.a * second.b) - (second.a * first.b), (first.b * second.b));
       return result;
    }
    else if(!first.isNaN() && !second.isNaN() && !first.isInf() && !second.isInf() && first.b == second.b){
        Rational result((first.a - second.a), second.b);
        return result;
    }
    else if (first.isInfNeg() && second.isInfNeg()){
        Rational result(0, 0);
        return result;
    }
    else if (first.isInfPos() && second.isInfPos()){
        Rational result(0, 0);
        return result;
    }
    else if (first.isNaN() || second.isNaN()){
        Rational result(0, 0);
        return result;
    }
    else if (first.isInfNeg() && second.isInfPos()) return first;
    else if (first.isInfPos() && second.isInfNeg()) return first;
    else if ((first.isNaN() || first.isInf()) && (!second.isNaN() && !second.isInf())) return first;
    else if ((!first.isNaN() && !first.isInf()) && (second.isNaN() || second.isInf())) {
        Rational result(-second.a, 0);
        return result;
    }
}

Rational operator*(const Rational &first, const Rational &second){
    Rational result((first.a * second.a), (first.b * second.b));
    return result;
}

Rational operator/(const Rational &first, const Rational &second){
    if ((first.isNaN() || first.isInf()) && (!second.isNaN() && !second.isInf())){
        if (second.a < 0){
            Rational result(-first.a, first.b);
            return result;
        }
        else {
            return first;
        }
    }
    else{
        Rational result((first.a * second.b), (first.b * second.a));
        return result;
    }
}
