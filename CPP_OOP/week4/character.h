#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <sstream>

using namespace std;

    class Character{

        private:
            string name;
            vector<Item> inventory;
            static int id;
            int characterID;
            void giveId();
        public:
            Character();
            Character(string n);
            ~Character();
            void setName(string n);
            string getName();
            void addItem(Item item);
            void removeItem(Item item);
            int getItemAmount(string name);
            void deleteItems();
            string toString() const;
            friend ostream& operator<<(ostream& o, const Character& character);
            friend istream& operator>>(istream& i, Character& character);

    };


#endif
