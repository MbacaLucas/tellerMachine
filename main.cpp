#include <iostream>
#include <string>

// Display current session statistics formatted with tabs
void displayHeader(double totalSum, int totalProducts, int premiumCount, std::string expensiveItemName)
{
    // Display current session statistics formatted with tabs
    std::cout << "N.Products: " << totalProducts << "\t" << "N.Premium: " << premiumCount << "\tMost Expensive Product: " << expensiveItemName << '\t' << "Total: $" << totalSum << '\n';
    std::cout << "---------------------------------------------------------------------------" << '\n';
    std::cout << "\t(to close the program write 'exit' in the product section)" << "\n\n";
}

// Evaluates if a product qualifies for premium status based on price
bool isPremium(double price)
{
    return price >= 100.0;
}

// Finish the program showing the detail bill
void printRecibe(int totalProducts, int premiumCount, double totalSum)
{
    std::cout << "\n====================================\n";
    std::cout << "Regular Products: " << totalProducts - premiumCount << "  Premium Products: " << premiumCount << "   total Items: " << totalProducts << '\n';

    if (totalProducts >= 5)
    {
        std::cout << "DISCOUNT APPLIED: 10 of descount for volume purchase!\n";
    }

    std::cout << "Final Total: $" << totalSum << '\n';
    std::cout << "Program finished!\n";
}

double applyDiscount(double totalSum, int totalProducts)
{
    return (totalProducts >= 5) ? totalSum * 0.9 : totalSum;
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
        displayHeader(totalSum, totalProducts, premiumCount, expensiveItemName);

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
        totalSum += price;
    }

    totalSum = applyDiscount(totalSum, totalProducts);

    printRecibe(totalProducts, premiumCount, totalSum);

    return 0;
}