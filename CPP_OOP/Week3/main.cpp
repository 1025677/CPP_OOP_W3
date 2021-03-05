#include "character.h"

using namespace Hero;

int main(){
    try{
        vector<Character> characterData;
        Character mainCharacter1("Jayquellin");
        characterData.push_back(mainCharacter1);
        Item item1(56, "Gold");
        Item item2(3, "Grand soul gem");
        Item item3(1, "Staff of the Familiar");
        characterData[0].addItem(item1);
        characterData[0].addItem(item2);
        characterData[0].addItem(item3);
        cout << characterData[0].toString() << endl;


        Character mainCharacter2("Ayayron");
        characterData.push_back(mainCharacter2);
        characterData[1].addItem(item1);
        characterData[1].addItem(item2);
        characterData[1].addItem(item3);
        cout << characterData[1].toString() << endl;

        characterData[0].deleteItems();
        characterData[0].addItem(item1);
        item1.setAmount(10);
        characterData[0].removeItem(item1);
        characterData[0].getItemAmount(item1.getName());
        cout << characterData[0].toString() << endl;

        item1.setAmount(-10);
        // 2 ways to throw exceptions
        characterData[0].addItem(item1);
        //characterData[1].getItemAmount("gasd");
    }
    catch(logic_error &e){
        cerr << "Caught logic error: " << e.what() << endl;
    }
    catch(exception &e){
        cerr << "Caught every exception: " << e.what() << endl;
    }

    return 0;
}
