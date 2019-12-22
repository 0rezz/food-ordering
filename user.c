//
// Created by htbc4 on 12/19/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "user.h"

#define MAX_USER 10
#define MAX_PASS 10


user createUser(){
    user u;
    u.username = (char*)malloc(MAX_USER* sizeof(char));
    u.password = (char*)malloc(MAX_PASS* sizeof(char));
    return u;
}

void inputLogIn (user *u) {
    printf("---Username\n");
    gets(u->username);
    printf("---Password\n");
    gets(u->password);
}