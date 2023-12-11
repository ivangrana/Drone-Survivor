#include "include/Market.h"
#include <string>
#include <iostream>

Market::Market(const std::string name)
{
    setName(name);

} // first constructor

Market::Market(const Market &other) // copy constructor
{
    setName(other.market_name); // copies name from other market

    for (const auto &pair : other.itemMap) // copies each item from other market
    {
        int quantity = pair.first;
        Item *item = pair.second;
        itemMap.insert({quantity, pair.second});
    }
}

// Set the name from the market
void Market::setName(const std::string newName)
{
    this->market_name = newName.substr(0, 15);
}

void Market::addItem(int quantity,  Item &item){
 itemMap.insert({quantity, &item});
}

std::ostream &operator<<(std::ostream &os, const Market &market)
{
    os << market.market_name;
    os << "Items available:\n";
    for (auto &pair : market.itemMap)
    {
        os << "Quantity:" << pair.first << "|Price" << pair.second->cost;
    }
    return os;
}

// destructor
Market::~Market()
{
    for (const auto &pair : itemMap) // delete all items from the market
    {
        delete pair.second;
    }
    itemMap.clear(); //
}
