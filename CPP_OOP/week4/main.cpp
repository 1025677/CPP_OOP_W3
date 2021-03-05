#include "character.h"

#include <assert.h>

int main(){
    try{
        Character mainCharacter;
        cin >> mainCharacter;
        Item item1(52, "Gold");
        Item item2;
        Item item3(51, "Gold");
        Item item4(1, "Staff of the Familiar");

        cin >> item2;
        mainCharacter.addItem(item2);
        mainCharacter.addItem(item1);
        cout << mainCharacter;

        Character mainCharacter2("Ayayron");
        mainCharacter2.addItem(item1);
        mainCharacter2.addItem(item4);
        cout << mainCharacter2;

        assert(item3 < item1);
        assert(!(item3 > item1));
        assert(item3 == item3);
        assert(item3 != item1);
        assert(item3 <= item1);
        assert(item1 >= item3);

        cout << "Post-increment object" << endl;
        cout << "item++: " << item1++ << endl;
        cout << "Pre-increment object" << endl;
        cout << "++item: " << ++item1 << endl;
    }
    catch(logic_error &e){
        cerr << "Caught logic error: " << e.what() << endl;
    }
    catch(exception &e){
        cerr << "Caught every exception: " << e.what() << endl;
    }

    return 0;
}
