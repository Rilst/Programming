#include <iostream>


double BMI(double weight, double height);
void printBMI(double BMI);

int main()
{
	double w, h;
	std::cout << "Enter your weight: ";
	std::cin >> w;
	std::cout << "Enter your height: ";
	std::cin >> h;

	printBMI(BMI(w, h));
}
double BMI(double weight, double height) {
	return (weight / pow((height/100), 2));
}
void printBMI(double BMI) {
	if (BMI < 18.5) std::cout << "Underweight\n";
	else if (BMI >= 18.5 && BMI < 25.0) std::cout << "Normal\n";
	else if (BMI >= 25.0 && BMI < 30.0) std::cout << "Overweight\n";
	else if (BMI >= 30.0) std::cout << "Obesity\n";
	return;
}
