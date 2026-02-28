#include <iostream>

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
    int totalProducts{};
    int premiumCount{};

    while (true)
    {
        // Display current session statistics formatted with tabs
        std::cout << "N.Products: " << totalProducts << "\t" << "N.Premium: " << premiumCount << '\t' << "Total: $" << totalSum << '\n';
        std::cout << "-------------------------------------------------" << "\n\n";
        std::cout << "Please enter the value of the product (or 0 to exit): ";
        std::cin >> price;

        // Sentinel value to terminate the loop
        if (price == 0)
        {
            break;
        }
        else if (bool premium{isPremium(price)})
        {
            ++premiumCount;
        }

        // Update cumulative totals
        ++totalProducts;
        totalSum += price;
    }

    std::cout << "Program finished!";

    return 0;
}