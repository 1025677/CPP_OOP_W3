#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;


class Item{
    private:
        int amount;
        string name;
    public:
        Item();
        Item(const int& amount, const string& name);
        void setName(const string& name);
        string getName();
        void addAmount(const int& amount);
        void setAmount(const int& amount);
        int getAmount();
        bool operator==(const Item& item) const;
        bool operator!=(const Item& item) const;
        bool operator<(const Item& item) const;
        bool operator<=(const Item& item) const;
        bool operator>(const Item& item) const;
        bool operator>=(const Item& item) const;
        Item& operator++();
        Item operator++(int);
        Item& operator--();
        Item operator--(int);
        friend ostream& operator<<(ostream& o, const Item& item);
        friend istream& operator>>(istream& i, Item& item);

};

#endif
