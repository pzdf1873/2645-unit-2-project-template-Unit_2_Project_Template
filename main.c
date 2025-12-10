
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcs.h"


void main_menu(void);            /* runs in the main loop */
static void print_main_menu(void);      /* output the main menu description */
static int  get_user_input(void);       /* get a valid integer menu choice */
static void select_menu_item(int input);/* run code based on user's choice */
static void go_back_to_main(void);      /* wait for 'b'/'B' to continue */
static int  is_integer(const char *s);  /* validate integer string */
int enter_binary_number(char *output_buffer,size_t buffer_size);

int main(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
        main_menu();
    }
    /* not reached */
    return 0;
}

void main_menu(void)
{
    print_main_menu();
    {
        int input = get_user_input();
        select_menu_item(input);
    }
}

static int get_user_input(void)
{
    enum { MENU_ITEMS = 4 };   /* 1..4 = items, 5 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

static void select_menu_item(int input)
{
    switch (input) {
        case 1:
            Mathematical_Operation();
            go_back_to_main();
            break;
        case 2:
            Logical_Operation();
            go_back_to_main();
            break;
        case 3:
            Binary_Conversion();
            go_back_to_main();
            break;
        
        default:
            printf("Bye!\n");
            exit(0);
    }
}

static void print_main_menu(void)
{
    printf("\n----------- Main menu -----------\n"); // Displays the main menu 
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Mathematical Operation\t\t\n"
           "\t2. Logical Operation\t\t\n"
           "\t3. Binary Conversion\t\t\n"
           "\t4. Exit\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}

static void go_back_to_main(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');
}

/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
static int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}
int enter_binary_number(char *output_buffer, size_t buffer_size){
    char BinaryInput[17];
    printf("Enter your binary number: ");

    if (!fgets(BinaryInput, sizeof(BinaryInput), stdin)) {
        return -2; // Added some internal error checks just in case
    }
    BinaryInput[strcspn(BinaryInput, "\r\n")] = '\0'; // Get rid of the \0 that i dont want
    
    int check = is_valid_input(BinaryInput);
    if(check != 0){
        printf("Invalid input\n");
        return check;
    } else {
        printf("Valid input\n");
        
        strncpy(output_buffer, BinaryInput, buffer_size - 1); // 0 based
        output_buffer[buffer_size - 1] = '\0';
        return 0; // Success
    }
}
int get_math_input(void)
{
    enum { MATH_MENU_ITEMS = 4 };   //* 1..3 items 4 = exit
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MATH_MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}
int get_logic_input(void)
{
    enum { LOGIC_MENU_ITEMS = 4 };   //* 1..3 items 4 = exit
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= LOGIC_MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

int get_conversion_input(void)
{
    enum { CONVERSION_MENU_ITEMS = 3 };   //* 1..2 items 3 = exit
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= CONVERSION_MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}