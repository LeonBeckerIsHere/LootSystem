//Name: Leon Becker
//File: main.cpp

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Pool.h"

//disgusting method prototypes
const std::string determine_drop(const int &int_mf, const std::vector<std::vector<Pool>> &pools);
const std::string determine_from_pool(const int &int_mf, const int &total, const std::vector<Pool> &pool);
void populate_pools(std::vector<std::vector<Pool>> &pools);
void populate_ITEM(std::vector<Pool> &pool);
void populate_RARITY(std::vector<Pool> &pool);
void populate_WEAPON(std::vector<Pool> &pool);
void populate_ARMOUR(std::vector<Pool> &pool);
void populate_ACCESSORY(std::vector<Pool> &pool);

int main(int argc, char** argv){
    
    //Container to hold all the pools
    std::vector<std::vector<Pool>> standardPool(5);
    
    //populate the pools
    populate_pools(standardPool); 
    
    //magic find/value based on the type of enemy killed
    //Ideally this value is given by a client program
    int magic_find = 1;
    
    //Seed the rand function
    srand(time(NULL));

    //determine 100 drops
    std::string drop;
    for(int i = 0; i < 100; i++){
        drop = determine_drop(magic_find, standardPool);
        std::cout << drop << std::endl;
    }
}

const std::string determine_drop(const int &int_mf, const std::vector<std::vector<Pool>> &pools){
    
    //initialize variables
    std::string item_type, rarity;
    
    //determine item type and rarity from initial pools 
    item_type = determine_from_pool(int_mf, ITEM::TOTAL,pools.at(0));
    rarity = determine_from_pool(int_mf, RARITY::TOTAL, pools.at(1));
    
    //determine item type from more detailed pools
    if(item_type == "WEAPON")
        item_type = determine_from_pool(int_mf, WEAPON::TOTAL, pools.at(2));
    else if(item_type == "ARMOUR")
        item_type = determine_from_pool(int_mf, ARMOUR::TOTAL, pools.at(3));
    else if(item_type == "ACCESSORY")
        item_type = determine_from_pool(int_mf, ACCESSORY::TOTAL, pools.at(4));

    //return rarity and item type
    return rarity + " " + item_type;
}

//This method uses a lottery system to determine the item from a pool
const std::string determine_from_pool(const int &int_mf, const int &total,const std::vector<Pool> &pool){
    //draw determines the winning ticket number
    int sum = 0, draw = rand() % total + int_mf;
    
    //for each element in the pool add their ticket value
    //to the sum. If the sum is less than the drawn ticket
    //then we have our winner
    for(unsigned int i = 0; i < pool.size(); i++){  
        sum += pool.at(i).tickets;
        if(sum >= draw){
            return pool.at(i).id;
        }
    }

    return "";
}

//populate all the pools
void populate_pools(std::vector<std::vector<Pool>> &pools){
    populate_ITEM(pools.at(0));
    populate_RARITY(pools.at(1));
    populate_WEAPON(pools.at(2));
    populate_ARMOUR(pools.at(3));
    populate_ACCESSORY(pools.at(4));
}

void populate_ITEM(std::vector<Pool> &pool){
    Pool weapon_pool("WEAPON", ITEM::WEAPON);
    Pool armour_pool("ARMOUR", ITEM::ARMOUR);
    Pool accessory_pool("ACCESSORY", ITEM::ACCESSORY);
    pool.push_back(weapon_pool);
    pool.push_back(armour_pool);
    pool.push_back(accessory_pool);
}

void populate_RARITY(std::vector<Pool> &pool){
    Pool normal_pool("NORMAL", RARITY::NORMAL);
    Pool magic_pool("MAGIC", RARITY::MAGIC);
    Pool rare_pool("RARE", RARITY::RARE);
    Pool legendary_pool("LEGENDARY", RARITY::LEGENDARY);
    
    pool.push_back(normal_pool);
    pool.push_back(magic_pool);
    pool.push_back(rare_pool);
    pool.push_back(legendary_pool);
}

void populate_WEAPON(std::vector<Pool> &pool){
    Pool sword_pool("SWORD", WEAPON::SWORD);
    Pool wand_pool("WAND", WEAPON::WAND);
    Pool bow_pool("BOW", WEAPON::BOW);

    pool.push_back(sword_pool);
    pool.push_back(wand_pool);
    pool.push_back(bow_pool);
}

void populate_ARMOUR(std::vector<Pool> &pool){
    Pool body_pool("BODY", ARMOUR::BODY);
    Pool helmet_pool("HELMET", ARMOUR::HELMET);
    Pool gloves_pool("GLOVES", ARMOUR::GLOVES);
    Pool boots_pool("BOOTS", ARMOUR::BOOTS);

    pool.push_back(body_pool);
    pool.push_back(helmet_pool);
    pool.push_back(gloves_pool);
    pool.push_back(boots_pool);
}

void populate_ACCESSORY(std::vector<Pool> &pool){
    Pool amulet_pool("AMULET", ACCESSORY::AMULET);
    Pool ring_pool("RING", ACCESSORY::RING);

    pool.push_back(amulet_pool);
    pool.push_back(ring_pool);
}

