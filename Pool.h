//Name: Leon Becker
//File: Pool.h
#ifndef POOL_H
#define POOL_H
#include "Item.h"

struct Pool{
    std::string id;
    int tickets;
    Pool(std::string n, int t){
        tickets = t;
        id = n;
    }
};
#endif
