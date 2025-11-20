#include <iostream>

int main() {
    double price;
    double subtotal = 0.0;
    int item_count = 0;
    double discount_rate = 0.0;
    
    std::cout << "=== Shopping Discount Calculator ===" << std::endl;
    std::cout << "Enter item prices. Type 0 when finished." << std::endl;
    
    // Get item prices
    while (true) {
        std::cout << "Enter item price: $";
        std::cin >> price;
        
        if (price == 0) {
            break;
        } else if (price > 0) {
            subtotal += price;
            item_count++;
            std::cout << "Item " << item_count << " added: $" << price << std::endl;
        } else {
            std::cout << "Please enter a positive price." << std::endl;
        }
    }
    
    if (subtotal == 0) {
        std::cout << "No items entered. Goodbye!" << std::endl;
        return 0;
    }
    
    
    if (subtotal >= 200) {
        discount_rate = 0.15; 
        std::cout << "\nCongratulations! You qualify for a 15% discount!" << std::endl;
    } else if (subtotal >= 100) {
        discount_rate = 0.10; //
        std::cout << "\nCongratulations! You qualify for a 10% discount!" << std::endl;
    } else {
        discount_rate = 0.0;
        std::cout << "\nSpend $" << (100 - subtotal) << " more to get a 10% discount!" << std::endl;
    }
    
    double discount_amount = subtotal * discount_rate;
    double final_total = subtotal - discount_amount;
    
    std::cout << "\n=== Shopping Summary ===" << std::endl;
    std::cout << "Number of items: " << item_count << std::endl;
    std::cout << "Subtotal: $" << subtotal << std::endl;
    
    if (discount_rate > 0) {
        std::cout << "Discount (" << (discount_rate * 100) << "%): -$" << discount_amount << std::endl;
    } else {
        std::cout << "Discount: $0.00" << std::endl;
    }
    
    std::cout << "Final Total: $" << final_total << std::endl;
    
    if (discount_rate > 0) {
        std::cout << "You saved: $" << discount_amount << "!" << std::endl;
    }
    
    return 0;
}
