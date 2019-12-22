//
// Created by htbc4 on 12/19/2019.
//

#ifndef UNTITLED_USER_H
typedef struct _user{
    char *username;
    char *password;
}user;

void inputLogIn (user *u);

user createUser();

#define UNTITLED_USER_H

#endif //UNTITLED_USER_H
