#include "item.h"

Item::Item(){
}

Item::Item(const int &amount, const string& name){
    this->name = name;
    this->amount = amount;
}

void Item::setName(const string& name){
    this->name = name;
}

string Item::getName(){
    return name;
}

void Item::setAmount(const int& amount){
    this->amount = amount;
}

int Item::getAmount(){
    return amount;
}

void Item::addAmount(const int& amount){
    this->amount += amount;
}

bool Item::operator==(const Item& item) const{
    return (amount == item.amount && name == item.name);
}

bool Item::operator!=(const Item& item) const{
    return !(*this == item);
}

bool Item::operator<(const Item& item) const{
    return (amount < item.amount && name == item.name);
}

bool Item::operator<=(const Item& item) const{
    return (*this == item || *this < item);
}

bool Item::operator>(const Item& item) const{
    return !(*this < item);
}

bool Item::operator>=(const Item& item) const{
    return (*this == item || *this > item);
}

Item& Item::operator++(){
    ++this->amount;
    return *this;
}

Item Item::operator++(int){
    Item temp = *this;
    ++this->amount;
    return temp;
}


Item& Item::operator--(){
    --this->amount;
    return *this;
}

Item Item::operator--(int){
    Item temp = *this;
    --this->amount;
    return temp;
}

ostream& operator<<(ostream& o, const Item& item){
    o << item.name << " " << item.amount;
    return o;
}

istream& operator>>(istream& i, Item& item){
    Item temp;
    i >> temp.name >> temp.amount;
    item.name = temp.name;
    item.amount = temp.amount;

    return i;
}
