//
// Created by htbc4 on 12/22/2019.
//
#define NO_OF_DRINKS 3
#define MAX_DRINK 10

#include "stdlib.h"
#include "drinks.h"

drinks createDrinks(){
    drinks d;
    d.drinks=(char*)malloc(MAX_DRINK*sizeof(char));

    return d;
}