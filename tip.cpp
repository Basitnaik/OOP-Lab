#include <iostream>

int main() {
    double price;
    double subtotal = 0.0;
    int choice;
    double  tipp;//tip_percentage;
    
    std::cout << "Restaurant Tip Calculator " << std::endl;
    std::cout << "Enter meal prices. Type 0 when finished." << std::endl;
    
    // Get meal prices
    while (true) {
        std::cout << "Enter meal price: $";
        std::cin >> price;
        
        if (price == 0) {
            break;
        } else if (price > 0) {
            subtotal += price;
        } else {
            std::cout << "Please enter a positive price." << std::endl;
        }
    }
    
    if (subtotal == 0) {
        std::cout << "No meals entered. Goodbye!" << std::endl;
        return 0;
    }
    
    std::cout << "\nChoose tip percentage:" << std::endl;
    std::cout << "1. 15%" << std::endl;
    std::cout << "2. 18%" << std::endl;
    std::cout << "3. 20%" << std::endl;
    std::cout << "4. Custom percentage" << std::endl;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            tipp = 0.15;
            break;
        case 2:
            tipp = 0.18;
            break;
        case 3:
            tipp = 0.20;
            break;
        case 4:
            std::cout << "Enter custom tip percentage (e.g., 22 for 22%): ";
            std::cin >> tipp;
            tipp = tipp / 100.0;
            break;
        default:
            std::cout << "Invalid choice. Using 18% default." << std::endl;
            tipp = 0.18;
            break;
    }
    
    double tip_amount = subtotal * tipp;
    double total_bill = subtotal + tip_amount;
    
    std::cout << "\n=== Bill Breakdown ===" << std::endl;
    std::cout << "Subtotal: $" << subtotal << std::endl;
    std::cout << "Tip (" << (tipp * 100) << "%): $" << tip_amount << std::endl;
    std::cout << "Total Bill: $" << total_bill << std::endl;

    return 0;
}
