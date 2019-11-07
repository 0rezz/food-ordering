#include <stdio.h>
#define MAX_FOOD_NAME 20
#define MAX_TYPE_NAME 30
#define MAX_DRINK_NAME 30


void inputLogIn (char username[], char password[]);
void chooseFood (int noFoods, char foods[][MAX_FOOD_NAME]);
void chooseType (char foods[], int noTypes,  char types[][MAX_TYPE_NAME], double price[] );
int getChoiceIndex(int noChoices, int *state);
void printDrinkChoices (int noDrinks, char drinks[][MAX_DRINK_NAME], double drinkPrice[]);
int chooseDrinks(int noDrinks, int chosenDrinks[], int *state);
void readAdditionalInfo (char str[], int *state);
void chooseCutlery (int *cutlery, int *state, char choice);
void displayOrder(char type[], double price, int noDrinksChosen, int chosenDrink[], char drinks[][MAX_DRINK_NAME],
                  double drinkPrice[], char str[],int *cutlery,int *state, char choice, int *ordersigned);
int main() {
    int noFoods=3;
    int choice, foodChoice, typeChoice;
    char info[100];
    double foodItemPrice=0;
    printf ("Welcome to food thingies!\nPlease sign in to continue:\n");
    int noDrinksChosen;
    int cutlery;
    char username[20];
    char password[20];
    int noTypes[3]={3,2,4};
    char foods[][MAX_FOOD_NAME] = {"Pizza", "Pasta", "Salad"};
    char types[3][4][MAX_TYPE_NAME] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                                       {"Chicken Alfredo", "Lasagna" },
                                       {"Tuna Salad", "Chicken Salad", "Cobb","Greek Salad"}};
    double price[3][4] =    {{21, 24, 19},
                             {23,21},
                             {23,22,19,21}};
    int noDrinks=3;
    char drinks[][30]={"Pepsi", "Coke", "Dr.Pepper"};
    double drinkPrice[]={5,5,5};
    int chosenDrink[3];
    int state=0;
    int ordersigned=0;
    while (ordersigned==0) {
        switch (state) {
            case 0: {
                inputLogIn (username, password);
                state++;
                break;
            }
            case 1: {
                chooseFood (noFoods, foods);
                foodChoice= getChoiceIndex( noFoods, &state);
                break;}
            case 2: {
                chooseType (foods[foodChoice], noTypes[foodChoice],  types[foodChoice],  price[foodChoice]);
                typeChoice= getChoiceIndex (noTypes[foodChoice], &state);
                break;
            }
            case 3: {
                printDrinkChoices (noDrinks, drinks, drinkPrice);
                noDrinksChosen = chooseDrinks (noDrinks, chosenDrink, &state);
                break;
            }
            case 4: {
                chooseCutlery (&cutlery, &state,choice);
                break;
            }
            case 5: {
                readAdditionalInfo (info, &state);
                break;
            }
            case 6: {
                displayOrder(types[foodChoice][typeChoice], price[foodChoice][typeChoice], noDrinksChosen,  chosenDrink,  drinks,  drinkPrice, info, &cutlery, &state,choice,&ordersigned);
            }
                getchar();
                break;
        }
    }
}
void inputLogIn (char username[], char password[]){
    printf("---Username");
    gets(username);
    printf("---Password");
    gets(password);
}
void chooseFood (int noFoods, char foods[][MAX_FOOD_NAME]){

    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < noFoods; i++) {
        putchar('a' + i);
        printf(")%s \n", foods[i]);
    }
    printf("%c) Go back\n", 'a' + noFoods);
}
void chooseType (char foods[], int noTypes,  char types[][MAX_TYPE_NAME], double price[]){
    printf("Please select a type of %s\n", foods);
    for (int i = 0; i<noTypes; i++) {
        putchar('a' + i);
        printf(")%s (%.2f)\n", types[i], price[i]);
    }
    printf("%c) Go back\n", 'a' + noTypes);
}
int getChoiceIndex(int noChoices, int *state){
    int choiceIndex;
    char choice=getchar();
    getchar();
    if(choice=='a'+noChoices) {
        (*state)--;
    }else {
        choiceIndex=choice-'a';
        (*state)++;
    }
    return choiceIndex;
}
void printDrinkChoices (int noDrinks, char drinks[][MAX_DRINK_NAME], double drinkPrice[]){
    printf("Choose additional items (separated by comma)\n");
    for (int i = 0; i < noDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", drinks[i], drinkPrice[i]);
    }
    printf("%c) Go back\n", 'a' + noDrinks);
}

int chooseDrinks(int noDrinks, int chosenDrinks[], int *state){
    int noDrinksChosen=0;
    char choice=getchar();
    if (choice=='a'+ noDrinks){
        (*state)--;
    } else (*state)++;
    while(choice!='\n') {
        chosenDrinks[noDrinksChosen] = choice - 'a';
        noDrinksChosen++;
        char comma = getchar();
        if (comma == '\n') {
            break;
        }
        choice = getchar();
    }
    return noDrinksChosen;
}
void readAdditionalInfo (char str[], int *state) {
    printf("Any additional info?\n");
    fgets(str, 100, stdin);
    (*state)++;
}
void chooseCutlery (int *cutlery, int *state, char choice){
    printf("Do you want cutlery?\n");
    printf("a) Yes\n"
           "b) No, thanks!\n"
           "c) Go back\n");
    choice = getchar();
    if (choice == 'a' + 2) {
        (*state)--;

    }else{ if(choice == 'a') {
            (*cutlery) =1;
            (*state)++;

        }else {
            (*cutlery) = 0;
            (*state)++;

        }}
    getchar();
}

void displayOrder(char type[], double price, int noDrinksChosen, int chosenDrink[], char drinks[][MAX_DRINK_NAME],
                  double drinkPrice[], char str[],int *cutlery,int *state,char choice, int *ordersigned) {
    printf("This is your order:\n""-------------------\n");
    printf("Food items:\n""---%s (%.2f)\n", type, price);
    double totalDrinkPrice = 0;
    for(int i=0;i<noDrinksChosen;i++) {
        totalDrinkPrice+= drinkPrice[chosenDrink[i]];}
    if(noDrinksChosen!=0){
        for(int i=0;i<noDrinksChosen;i++) {
            printf("--%s (%.2f)\n", drinks[chosenDrink[i]], drinkPrice[chosenDrink[i]]);}}
    printf("Cutlery:");
    if ((*cutlery) == 1) {
        printf(" yes\n");
    }    else {
        printf(" no\n");}
    printf("Additional info:\n");
    printf("%s", str);
    printf("Payment amount: %.2f\n", price + totalDrinkPrice);
    printf("a) Sign\n");
    printf("b) Go back\n");
    choice = getchar();
    if (choice == 'a') {
        (*ordersigned) = 1;
    } else {
        (*state)--;}
};

