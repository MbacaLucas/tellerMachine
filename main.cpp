#include <iostream>
#include <string>

// Evaluates if a product qualifies for premium status based on price
bool isPremium(double price)
{
    return price >= 100.0;
}

int main()
{
    // Initialize variables using uniform initialization
    double price{};
    double totalSum{};
    double maxPrice{0.0};
    int totalProducts{};
    int premiumCount{};
    std::string itemName{};
    std::string expensiveItemName{"None"};

    while (true)
    {
        // Display current session statistics formatted with tabs
        std::cout << "N.Products: " << totalProducts << "\t" << "N.Premium: " << premiumCount << "\tMost Expensive Product: " << expensiveItemName << '\t' << "Total: $" << totalSum << '\n';
        std::cout << "---------------------------------------------------------------------------" << '\n';
        std::cout << "\t(to close the program write 'exit' in the product section)" << "\n\n";

        std::cout << "Enter the product: ";
        std::getline(std::cin >> std::ws, itemName);
        if (itemName == "exit")
        {
            break;
        }

        std::cout << "Please enter the price of " << itemName << ": ";
        std::cin >> price;

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
        totalSum += price;
    }

    std::cout << "Program finished!";

    return 0;
}