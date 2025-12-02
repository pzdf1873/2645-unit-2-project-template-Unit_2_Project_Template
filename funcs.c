#include <stdio.h>
#include "funcs.h"
#include <string.h>

void Mathematical_Operation(void) {
    printf("\n>> Menu 1\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 1 */
}

void Logical_Operation(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

void Binary_Conversion(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}
int is_valid_input(const char BinaryInput[]){
    for (int i = 0; i < (strlen(BinaryInput)); i++)
    {
        if (BinaryInput[i] != '1' && BinaryInput[i] != '0'){
            return -1;  
        }
    }
    return 0;
}