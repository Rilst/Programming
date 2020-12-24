#include <iostream>
#include <vector>

struct Item {
    enum class ItemType {
        COIN,
        RUNE,
        WEAPON,
        ARMOR
    };
    union Runion {
        struct Coin {
            unsigned int count;
        };
        struct Rune {
            unsigned short level;
            enum class element {
                FIRE,
                WATER,
                EARTH,
                AIR
            };

        };
        struct Weapon {
            unsigned int damage;
            unsigned short critical;
            unsigned short durability;
        };
        struct Armor {
            unsigned int guard;
            unsigned short durability;
        };
    };
};

using namespace std;
typedef vector<Item> LootBox;


int main()
{

}


LootBox generateLootBox() {

}