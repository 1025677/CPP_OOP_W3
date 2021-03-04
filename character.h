#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <sstream>

using namespace std;


class Item{
    private:
        int amount;
        string name;
    public:
        Item(int amount, string name);

        void setName(string name);

        string getName();

        void addAmount(int amount);

        void setAmount(int amount);

        int getAmount();
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

            void addItem(Item item);

            void removeItem(Item item);

            int getItemAmount(string name);

            void deleteItems();

            string toString();

    };
}

#endif
