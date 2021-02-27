#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>

using namespace std;

struct Item{
    int amount;
    string name;
};

namespace Hero{
    class Character{

        private:
            string name;
            vector<Item> inventory;
            static int id;
            int characterID;

        public:

            Character(string n);

            ~Character();

            void setName(string n);

            string getName();

            void addItem(int amount, string name);

            void removeItem(int amount, string name);

            int getItemAmount(string name);

            void deleteItems();

            void showInventory();

            void toString();

    };
}

#endif
