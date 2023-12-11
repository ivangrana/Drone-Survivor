#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;

struct Item
{
    string type;
    const int cost;
};

class Market
{
    friend std::ostream &operator<<(std::ostream &, const Market &);

public:
    
    Market(string);
    Market(const Market &); // construtor de cópia
    ~Market();

    void setName(string);
    void addItem(int, Item &);
    void removeItem(int, Item &);

private:
    map<int, Item *> itemMap; // Utilização do STL map
    string market_name;
};

#endif // MARKET_H