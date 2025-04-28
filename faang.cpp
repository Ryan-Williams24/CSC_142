#include <iostream>

int main(){
    
    int budget;
    std::cout << "Enter your budget: ";
    std::cin >> budget;
    int itemCount = 0;

    while (true){
        
        int price;
        std::cout << "Enter the price of item " << itemCount+1 << " (or 0 to finish): ";
        std::cin >> price;
        
        if (price ==0){
            break;
        }
        if (price >= budget){

            std::cout << "Cannot afford item " << itemCount+1 << " costing $" << price << ". Budget is $" << budget << ".\n";
            break;

        }

        budget -= price;
        itemCount++;
        std::cout << "Item " << itemCount << " bought for $" << price << ". Remaining budget is $" << budget << ".\n" << std::endl;

    }

    std::cout << "You purchased " << itemCount << " items. You have a remaining budget of $" << budget << " on your gift card." << std::endl;

}