#include <iostream>
#include <cmath>

int main() {
    float weight, height, bmi;

    
    std::cout << "Enter your weight in kilograms (kg): ";
    std::cin >> weight;

    std::cout << "Enter your height in meters (m): ";
    std::cin >> height;

    
    bmi = weight / pow(height, 2);

   
    std::cout << "\nYour BMI is: " << bmi << std::endl;

    
    if (bmi < 18.5) {
        std::cout << "Category: Underweight" << std::endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        std::cout << "Category: Normal weight" << std::endl;
    } else if (bmi >= 25 && bmi < 30) {
        std::cout << "Category: Overweight" << std::endl;
    } else {
        std::cout << "Category: Obesity" << std::endl;
    }

   return 0;
}