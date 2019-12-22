#include <stdio.h>



int main() {
    char info[100];
    double foodItemPrice=0;
    printf ("Welcome to food thingies!\nPlease sign in to continue:\n");
    int noFoods=3;
    int noDrinksChosen;
    int cutlery;
    char username[20];
    char password[20];
    int noTypes[3]={3,3,3};
    char foods[][10] = {"Pizza", "Pasta", "Salad"};
    char types[3][4][30] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
    {"Chicken Alfrefo", "Lasagna" },
    {"Tuna Salad", "Chicken Salad", "Cobb","Greek Salad"}};
    double price[3][4] = {{21, 23, 19},
        {23,21},
        {23,22,19,21}};
    int noDrinks=3;
    char drinks[][30]={"Pepsi", "Cola", "Fanta"};
    double drinkPrice[]={5,5,5};
    int chosenDrink[3];
    int choice;







    int state=0;
    int ordersigned=0;
    while (ordersigned==0) {
        switch (state) {
            case 0: {
                printf("---Username");
                gets(username);
                printf("---Password");
                gets(password);
                state++;
                break;
            }
            case 1: {
                printf("Please choose the food you feel like eating today:\n");
                int i;
                for (i = 0; i < noFoods; i++) {
                    putchar('a' + i);
                    printf(")%s\n", foods[i]);
                }

            }
                printf("%c) Go back\n", 'a' + noFoods);
                choice = getchar();

                getchar();
                if (choice == 'a' + noFoods) {
                    state--;
                    break;
                }

                int foodChoice, typeChoice;
                foodChoice = choice - 'a';
                state++;
                break;


            case 2: {
                printf("PLease select a type of %s\n", foods[foodChoice]);
                int i;
                if(foodChoice==0)
                    noFoods=3;
                else
                    if(foodChoice==1)
                        noFoods=2;
                    else
                        noFoods=4;





                for (i = 0; i < noFoods; i++) {
                    putchar('a' + i);
                    printf(")%s (%.2f)\n", types[foodChoice][i], price[foodChoice][i]);
                }
                printf("%c) Go back\n", 'a' + noTypes[foodChoice]);
                choice = getchar();
                getchar();
                if (choice == 'a' + noTypes[foodChoice]) {
                    state--;
                    break;
                }

                typeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                printf("Please choose a drink:\n");
                for (int i = 0; i < noDrinks; i++) {
                    putchar('a' + i);
                    printf(") %s (%.2f)\n", drinks[i], drinkPrice[i]);
                }
                printf("%c) Go back\n", 'a' + noDrinks);
                choice = getchar();
                if (choice == 'a' + noDrinks) {
                    state--;
                    getchar();
                    break;
                }
                noDrinksChosen = 0;
                while (choice != '\n') {
                    chosenDrink[noDrinks] = choice - 'a';
                    noDrinks++;
                    noDrinksChosen++;
                    char comma = getchar();
                    if (comma == '\n') {
                        break;
                    }
                    choice = getchar();
                }
                state++;
                break;

            }

            case 4: {
                printf("Do you want cutlery?\n");
                printf("a) Yes\n"
                       "b) No, thanks!\n"
                       "c) Go back\n");


                choice = getchar();
                if (choice == 'a' + 2) {
                    state--;
                    getchar();
                    break;
                }
                if (choice == 'a') {
                    cutlery = 1;
                } else {
                    cutlery = 0;
                }


                state++;
                break;

            }
            case 5: {
                printf("Any additional info?\n");
                scanf("%[^\n]s", info);

                state++;
                break;
            }
            case 6: {
                printf("This is your order:\n"
                       "-------------------\n");
                printf("Name: %s\n", username);
                printf("Food items:\n""---%s\n", types[foodChoice][typeChoice]);
                for (int i = 0; i < noDrinksChosen; i++) {
                    foodItemPrice = drinkPrice[chosenDrink[i]] + foodItemPrice;
                }
                if (noDrinks != 0) {
                    for (int i = 0; i < noDrinksChosen; i++) {
                        printf("---%s(%.2f)\n", drinks[chosenDrink[i]], drinkPrice[chosenDrink[i]]);

                    }
                }
                printf("Cutlery:");
                if (cutlery == 1) {
                    printf(" yes\n");
                } else {
                    printf(" no\n");
                }
            }
                printf("Additional info:\n");
                printf("%s", info);
                printf("Payment ammount: %.2f\n", price[foodChoice][typeChoice] + foodItemPrice);
                printf("a) Sign\n");
                printf("b) Go back\n");
                choice = getchar();
                if (choice == 'a') {
                    ordersigned = 1;
                } else {
                    state--;
                }

                getchar();
                break;


            }


        }
    }











