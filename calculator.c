#include <stdio.h>

int main() {
    double a, b, result;
    int choice;
    
    printf("Simple Calculator using switch\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Choose an option (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    
    switch(choice) {
        case 1:
            result = a + b;
            printf("Result = %.2lf\n", result);
            break;
            
        case 2:
            result = a - b;
            printf("Result = %.2lf\n", result);
            break;
            
        case 3:
            result = a * b;
            printf("Result = %.2lf\n", result);
            break;
            
        case 4:
            if(b != 0) {
                result = a / b;
                printf("Result = %.2lf\n", result);
            } else {
                printf("Error: Division by zero is not allowed\n");
            }
            break;
            
        default:
            printf("Invalid choice! Please select 1-4\n");
            break;
    }
    
    return 0;
}
