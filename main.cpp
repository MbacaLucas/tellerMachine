#include <iostream>

bool isPremium(double price)
{
    return price >= 100.0;
}

int main()
{
    double price{};
    double totalSum{};
    int totalProducts{};
    int premiumCount{};

    while (true)
    {
        std::cout << "N.Products: " << totalProducts << "\t" << "N.Premium: " << premiumCount << '\t' << "Total: $" << totalSum << '\n';
        std::cout << "-------------------------------------------------" << "\n\n";
        std::cout << "Please enter the value of the product (or 0 to exit): ";
        std::cin >> price;

        if (price == 0)
        {
            break;
        }
        else if (bool premium{isPremium(price)})
        {
            ++premiumCount;
        }
        ++totalProducts;
        totalSum += price;
    }

    std::cout << "Program finished!";

    return 0;
}