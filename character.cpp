#include "character.h"

using namespace Hero;

int Character::id =  40999;

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

void Character::addItem(int amount, string name){
    if(0 < amount){
        for(int i = 0; i < inventory.size(); ++i){
            if(inventory[i].name == name){
                    inventory[i].amount += amount;
                    return;
            }
        }
        Item inv = {amount, name};
        inventory.push_back(inv);
    }
    else
        throw logic_error("Out of range");
}

void Character::removeItem(int amount, string name){
    for(int i = 0; i < inventory.size(); ++i){
        if(inventory[i].name == name){
            if(inventory[i].amount - amount <= 0){
                inventory.erase(inventory.begin() + i);
                return;
            }
            inventory[i].amount -= amount;
            return;
        }
    }

}

int Character::getItemAmount(string name){
        for(int i = 0; i < inventory.size(); ++i){
            if(inventory[i].name == name){
                return inventory[i].amount;
            }
        }
        throw logic_error("invalid argument");
}

void Character::deleteItems(){
    inventory.clear();
}

void Character::showInventory(){
    if(inventory.size() == 0){
        cout << "empty inventory" << endl;
    }
    else{
        cout << "Item " << setw(25) << "amount " << endl;
        for(int i = 0; i < inventory.size(); ++i){
            cout << inventory[i].name << setw(29 - inventory[i].name.length()) << inventory[i].amount << endl;
        }
    }

}

void Character::toString(){
    cout << "Character's name: " << name << endl;
    showInventory();
    cout << "Character's ID: " << characterID << endl;
    cout << endl;

}
