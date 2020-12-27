#include <iostream>
#include <vector>
#include <random>
#include <functional>


enum class ItemType {
    COIN,
    RUNE,
    WEAPON,
    ARMOR
};
enum class RuneType {
    FIRE,
    WATER,
    EARTH,
    AIR
};
union COL {
    struct {
        unsigned int count;
    } Coin;
    struct {
        unsigned short level;
        RuneType element;

    } Rune;
    struct {
        unsigned int damage;
        unsigned short critical;
        unsigned short durability;
    } Weapon;
    struct {
        unsigned int guard;
        unsigned short durability;
    } Armor;
};

struct Item {
    ItemType I;
    union COL Runion;
};

using namespace std;
typedef vector<Item> LootBox;

LootBox generateLootBox();

ostream& operator<<(ostream& Out, Item Itm) {
    if (Itm.I == ItemType::COIN) Out << Itm.Runion.Coin.count << " gold";
    else if (Itm.I == ItemType::RUNE) {
        if (Itm.Runion.Rune.element == RuneType::AIR) Out << "Rune of Air" << " " << Itm.Runion.Rune.level << " lvl";
        if (Itm.Runion.Rune.element == RuneType::WATER) Out << "Rune of Water" << " " << Itm.Runion.Rune.level << " lvl";
        if (Itm.Runion.Rune.element == RuneType::EARTH) Out << "Rune of Earth" << " " << Itm.Runion.Rune.level << " lvl";
        if (Itm.Runion.Rune.element == RuneType::FIRE) Out << "Rune of Fire" << " " << Itm.Runion.Rune.level << " lvl";
    }
    else if (Itm.I == ItemType::WEAPON) {
        if (Itm.Runion.Weapon.damage == 100)
            Out << "God Killer";
        if (Itm.Runion.Weapon.damage == 75)
            Out << "Demon Slayer";
    }
    else if (Itm.I == ItemType::ARMOR) Out << "Bronezhiletka";

    return Out;
}

ostream& operator<<(ostream& os, LootBox x) {
    for (int i = 0; i < x.size(); i++) {
        os << x[i] << std::endl;
    }
    return os;
}

Item& operator++(Item& value) {
    vector<double> Chance = { 50, 6, 13, 7, 14, 0.6, 1.3, 0.7, 1.4, 0.06, 0.13, 0.07, 0.14, 1.4, 1.4, 2.8 };

    random_device generator;
    uniform_real_distribution<double> distr(0, 100);
    auto real_random = std::bind(distr, std::ref(generator));
    double r = real_random();

    double current_sum = 0;
    for (int i = 0; i < Chance.size(); i++) {
        if (current_sum <= r && r < current_sum + Chance[i]) {
            if (i == 0) {
                value.I = ItemType::COIN;
                value.Runion.Coin.count = 1000;
                return value;
            }
            else if (i == 1) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 1;
                value.Runion.Rune.element = RuneType::FIRE;
                return value;
            }
            else if (i == 2) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 1;
                value.Runion.Rune.element = RuneType::WATER;
                return value;
            }
            else if (i == 3) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 1;
                value.Runion.Rune.element = RuneType::EARTH;
                return value;
            }
            else if (i == 4) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 1;
                value.Runion.Rune.element = RuneType::AIR;
                return value;
            }
            else if (i == 5) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 5;
                value.Runion.Rune.element = RuneType::FIRE;
                return value;
            }
            else if (i == 6) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 5;
                value.Runion.Rune.element = RuneType::WATER;
                return value;
            }
            else if (i == 7) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 5;
                value.Runion.Rune.element = RuneType::EARTH;
                return value;
            }
            else if (i == 8) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 5;
                value.Runion.Rune.element = RuneType::AIR;
                return value;
            }
            else if (i == 9) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 10;
                value.Runion.Rune.element = RuneType::FIRE;
                return value;
            }
            else if (i == 10) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 10;
                value.Runion.Rune.element = RuneType::WATER;
                return value;
            }
            else if (i == 11) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 10;
                value.Runion.Rune.element = RuneType::EARTH;
                return value;
            }
            else if (i == 12) {
                value.I = ItemType::RUNE;
                value.Runion.Rune.level = 10;
                value.Runion.Rune.element = RuneType::AIR;
                return value;
            }
            else if (i == 13) {
                value.I = ItemType::WEAPON;
                value.Runion.Weapon.damage = 100;
                value.Runion.Weapon.critical = 0;
                value.Runion.Weapon.durability = 100;
                return value;
            }
            else if (i == 14) {
                value.I = ItemType::WEAPON;
                value.Runion.Weapon.damage = 75;
                value.Runion.Weapon.critical = 50;
                value.Runion.Weapon.durability = 100;
                return value;
            }
            else if (i == 15) {
                value.I = ItemType::ARMOR;
                value.Runion.Armor.guard = 50;
                value.Runion.Armor.durability = 100;
                return value;
            }

        }
        current_sum += Chance[i];
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    LootBox ITEM;
    string Otvet;
    while (true)
    {
        cout << "Открыть лутбокс? Yes/No\n";
        cin >> Otvet;
        if (Otvet == "y" || Otvet == "yes" || Otvet == "Y" || Otvet == "Yes" || Otvet == "YES") {
            ITEM = generateLootBox();
            cout << ITEM;
        }
        else  if (Otvet == "n" || Otvet == "no" || Otvet == "N" || Otvet == "No" || Otvet == "NO") {
            return 0;
        }
        else continue;
    }
}

LootBox generateLootBox() {
        LootBox Items;
        Item Itm;
        for (int i = 0; i < 3; i++) {
            Items.push_back(++Itm);
        }
        return Items;
}