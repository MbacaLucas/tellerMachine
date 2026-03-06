#include <iostream>
#include <string>

// Evaluates if a product qualifies for premium status based on price
bool isPremium(double price)
{
    return price >= 100.0;
}

double applyDiscount(double totalNetSum, int totalProducts)
{
    return (totalProducts >= 5) ? totalNetSum * 0.9 : totalNetSum;
}

// Display current session statistics formatted with tabs
void displayHeader(double totalNetSum, int totalProducts, int premiumCount, std::string expensiveItemName)
{
    // Display current session statistics formatted with tabs
    std::cout << "N.Products: " << totalProducts << "\t" << "N.Premium: " << premiumCount << "\tMost Expensive Product: " << expensiveItemName << '\t' << "Total: $" << totalNetSum << '\n';
    std::cout << "---------------------------------------------------------------------------" << '\n';
    std::cout << "\t(to close the program write 'exit' in the product section)" << "\n\n";
}

// show detail of the bill
void printRecibe(int totalProducts, int premiumCount, double subtotal, double discount, double tax, double total)
{
    std::cout << "\n====================================\n";
    std::cout << "          FINAL RECEIPT             \n";
    std::cout << "====================================\n";
    std::cout << "Regular Products: " << totalProducts - premiumCount << '\n';
    std::cout << "Premium Products: " << premiumCount << '\n';
    std::cout << "Total Items:      " << totalProducts << '\n';
    std::cout << "------------------------------------\n";

    std::cout << "Subtotal:        $" << subtotal << '\n';

    // Solo mostramos la línea de descuento si realmente se aplicó
    if (discount > 0)
    {
        std::cout << "Discount (10%): -$" << discount << '\n';
    }

    std::cout << "Tax (19%):       +$" << tax << '\n';
    std::cout << "------------------------------------\n";
    std::cout << "TOTAL TO PAY:    $" << total << '\n';
    std::cout << "====================================\n";
    std::cout << "Program finished!\n";
}

int main()
{
    // Initialize variables using uniform initialization
    constexpr double tax{0.19};
    double price{};
    double totalNetSum{0.0};
    double maxPrice{0.0};
    int totalProducts{0};
    int premiumCount{0};
    std::string itemName{};
    std::string expensiveItemName{"None"};

    while (true)
    {
        displayHeader(totalNetSum, totalProducts, premiumCount, expensiveItemName);

        std::cout << "Enter the product: ";
        std::getline(std::cin >> std::ws, itemName);
        if (itemName == "exit")
        {
            break;
        }

        std::cout << "Please enter the price of " << itemName << ": ";
        std::cin >> price;

        if (price < 0)
        {
            std::cout << "Error: Negative price! Let's start this product again.\n";
            continue;
        }

        if (bool premium{isPremium(price)})
        {
            ++premiumCount;
        }
        if (price > maxPrice)
        {
            maxPrice = price;
            expensiveItemName = itemName;
        }

        // Update cumulative totals
        ++totalProducts;
        totalNetSum += price;
    }

    double subtotal{totalNetSum};
    double subtotalWithDiscount{applyDiscount(subtotal, totalProducts)};
    double discountAmount{subtotal - subtotalWithDiscount};
    double taxAmount{subtotalWithDiscount * tax};
    double finalTotal{subtotalWithDiscount + taxAmount};

    printRecibe(totalProducts, premiumCount, subtotal, discountAmount, taxAmount, finalTotal);

    return 0;
}