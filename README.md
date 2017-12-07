# LootSystem
This code serves as a learning experience for myself.
GOAL:
1) Create an elementary loot system

Concept:
    
    This loot system will be based off of Path of Exile's item classifications
    Some logic concepts come from Paul Hellquist's article "INSIDE THE BOX: THE BORDERLANDS 2 LOOT SYSTEM"
    url: http://www.gearboxsoftware.com/2013/09/inside-the-box-the-borderlands-2-loot-system/
    
    CHANCE_FOR_ITEM_DROP:
    
        From a value from 0 to 1, if the value is less than 0.085
        then an item is dropped

    ITEM_CATEGORY:

        There will be 3 item categories each with their own sub item types:
            
            ARMOUR_TYPES:
                HEAD, BODY, GLOVES, BOOTS

            WEAPON_TYPES:
                SWORD, WAND, BOW

            ACCESSORY_TYPES:
                RING, AMULET
    
    RARITIES:

        Four rarities:
            NORMAL, MAGIC, RARE, LEGENDARY

    MAGIC_FIND:
        Depends on the enemy type killed, and character's magic find stat

    
    I also want to be able to create a server-client relationship where 
    The client notifies the server if a monster has been killed and it has dropped
    an item that must be rolled, then the server returns an item.
