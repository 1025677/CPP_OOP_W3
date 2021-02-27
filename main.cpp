#include "character.h"

using namespace Hero;

int main(){
    try{
        vector<Character> characterData;
        Character mainCharacter1("Jayquellin");
        characterData.push_back(mainCharacter1);
        characterData[0].addItem(56, "Gold");
        characterData[0].addItem(3, "Grand soul gem");
        characterData[0].addItem(1, "Staff of the Familiar");
        characterData[0].toString();

        Character mainCharacter2("Ayayron");
        characterData.push_back(mainCharacter2);
        characterData[1].addItem(20, "Gold");
        characterData[1].addItem(1, "Hunting bow");
        characterData[1].addItem(59, "Iron arrows");
        characterData[1].toString();

        Character mainCharacter3("Balakey");
        characterData.push_back(mainCharacter3);
        characterData[2].addItem(1, "Steel Battleaxe");
        characterData[2].addItem(32, "Apple");
        characterData[2].toString();

        characterData[0].deleteItems();
        characterData[0].addItem(21, "Gold");
        characterData[0].removeItem(10, "Gold");
        characterData[0].getItemAmount("Gold");
        characterData[0].showInventory();

        // 2 ways to throw exceptions
        characterData[0].addItem(-10,"gold");
        //characterData[1].getItemAmount("gasd");
    }
    catch(logic_error &e){
        cout << "Caught logic error: " << e.what() << endl;
    }
    catch(exception &e){
        cout << "Caught every exception: " << e.what() << endl;
    }

    return 0;
}
