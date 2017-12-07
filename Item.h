//Name: Leon Becker
//File: Item.h
#ifndef ITEM_H
#define ITEM_H
#include <iostream>

namespace ITEM{   
    extern const int WEAPON = 75;
    extern const int ARMOUR = 100;
    extern const int ACCESSORY = 10;
    extern const int TOTAL = WEAPON + ARMOUR + ACCESSORY;
}

namespace RARITY{
    extern const int NORMAL = 800;
    extern const int MAGIC = 180;
    extern const int RARE = 19;
    extern const int LEGENDARY = 1;
    extern const int TOTAL = NORMAL + MAGIC + RARE + LEGENDARY;
}

namespace WEAPON{
    extern const int SWORD = 1;
    extern const int WAND = 1;
    extern const int BOW = 1;
    extern const int TOTAL = SWORD + BOW + WAND;
}

namespace ARMOUR{
    extern const int BODY = 10;
    extern const int HELMET = 8;
    extern const int GLOVES = 8;
    extern const int BOOTS = 8;
    extern const int TOTAL = BODY + HELMET + GLOVES + BOOTS;
}

namespace ACCESSORY{
    extern const int AMULET = 1;
    extern const int RING = 3;
    extern const int TOTAL = AMULET + RING;
    
}

struct Item{
    std::string rarity;
    std::string itemType;
    Item(std::string r, std::string i){
        rarity = r;
        itemType = i;
    }
};
#endif
