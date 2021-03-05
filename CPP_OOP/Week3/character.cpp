#include "character.h"

using namespace Hero;

int Character::id =  40999;

Item::Item(int amount, string name){
    this->name = name;
    this->amount = amount;
}

void Item::setName(string name){
    this->name = name;
}

string Item::getName(){
    return name;
}

void Item::setAmount(int amount){
    this->amount = amount;
}

int Item::getAmount(){
    return amount;
}

void Item::addAmount(int amount){
    this->amount += amount;
}

Character::Character(string n){
    this->name = n;
    this->characterID = id;
    ++id;
}

Character::~Character(){
}

void Character::setName(string n){
    name = n;
}

string Character::getName(){
    return name;
}

void Character::addItem(Item item){
    if(0 < item.getAmount()){
        for(int i = 0; i < inventory.size(); ++i){
            if(inventory[i].getName() == item.getName()){
                    inventory[i].addAmount(item.getAmount());
                    return;
            }
        }
        inventory.push_back(item);
    }
    else
        throw logic_error("Out of range");
}

void Character::removeItem(Item item){
    for(int i = 0; i < inventory.size(); ++i){
        if(inventory[i].getName() == item.getName()){
            if(inventory[i].getAmount() - item.getAmount() <= 0){
                inventory.erase(inventory.begin() + i);
                return;
            }
            inventory[i].addAmount(-item.getAmount());
            return;
        }
    }

}

int Character::getItemAmount(string name){
        for(int i = 0; i < inventory.size(); ++i){
            if(inventory[i].getName() == name){
                return inventory[i].getAmount();
            }
        }
        throw logic_error("invalid argument");
}

void Character::deleteItems(){
    inventory.clear();
}


string Character::toString(){
    stringstream ss;
    ss << name << endl;
    for(int i = 0; i < inventory.size(); ++i){
            ss << inventory[i].getName() << " " << inventory[i].getAmount() << endl;
        }
    ss << characterID << endl;

    return ss.str();
}
