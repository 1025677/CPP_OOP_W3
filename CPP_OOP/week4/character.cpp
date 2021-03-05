#include "character.h"

int Character::id =  40999;

Character::Character(){
    this->characterID = id;
    ++id;
}

Character::Character(const string& n){
    this->name = n;
    this->characterID = id;
    ++id;
}

Character::~Character(){
}

void Character::setName(const string& n){
    name = n;
}

string Character::getName(){
    return name;
}

void Character::addItem(Item item){
    if(0 < item.getAmount()){
        for(unsigned int i = 0; i < inventory.size(); ++i){
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
    for(unsigned int i = 0; i < inventory.size(); ++i){
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

int Character::getItemAmount(const string& name){
        for(unsigned int i = 0; i < inventory.size(); ++i){
            if(inventory[i].getName() == name){
                return inventory[i].getAmount();
            }
        }
        throw logic_error("invalid argument");
}

void Character::deleteItems(){
    inventory.clear();
}


string Character::toString() const{
    stringstream ss;
    ss << name << endl;
    for(unsigned int i = 0; i < inventory.size(); ++i){
            ss << inventory[i] << endl;
        }
    ss << characterID << endl;

    return ss.str();
}

ostream& operator<<(ostream& o, const Character& character){
    o << character.toString();
    return o;
}

istream& operator>>(istream& i, Character& character){
    Character temp;
    i >> temp.name;
    character.name = temp.name;
    return i;
}

