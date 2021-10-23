#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// set a constant for the max name length
#define MAX_LENGTH 26

// define function prototypes
int contains(char** array, char* val, int size);

int main(void){

    // declare a looping variable and a variable for the number of customers given
    int num_customers, i;

    // scan in the number of customers to use while looping
    scanf("%d", &num_customers);

    // to keep track of who has come in already, we use a dynamically allocated array
    // of size equal to the number of customers
    char** names_seen = malloc(sizeof(char*) * num_customers);

    for(i = 0; i < num_customers; i++){

        // we must allocate this memory before putting anything inside
        names_seen[i] = malloc(sizeof(char) * MAX_LENGTH);

        printf("Customer #%d: ", i + 1);

        // this is what we will temporarily store the input in
        char* customer = malloc(sizeof(char) * MAX_LENGTH);
        scanf("%s", customer);

        // print out the answer according to whether or not we have seen this customer
        if(contains(names_seen, customer, i) == 1){
            printf("**continue working**\n");
        }else{
            printf("Welcome to Moe's!!!\n");
        }

        // add the customer to our names seen so we can access it later
        strcpy(names_seen[i], customer);

        // make sure to free your memory!
        free(customer);
    }

    // REALLY make sure to free your memory!
    for(i = 0; i < num_customers; i++){
        free(names_seen[i]);
    }
    free(names_seen);

    // and, of course, we end the program
    return 0;
}

// given an array, an element, and the size of the array:
// return 1 if the element is in the array
// return 0 otherwise
int contains(char** array, char* val, int size){
    int i;
    for(i = 0; i < size; i++){
        if(strcmp(array[i], val) == 0){
            return 1;
        }
    }
    return 0;
}
