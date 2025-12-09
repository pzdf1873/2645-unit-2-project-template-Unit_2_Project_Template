#include <stdio.h>
#include "funcs.h"
#include <string.h>
#include <stdbool.h>

extern void main_menu(void);
extern int enter_binary_number(char *output_buffer, size_t buffer_size);

void Mathematical_Operation(void) {
    printf("\n>> Mathematical Operation Menu\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Binary Addition\t\t\n"
           "\t2. Binary Subtraction\t\t\n"
           "\t3. Binary Multiplication\t\t\n"
           "\t4. Exit to Menu\t\t\n"
           "\t\t\t\t\t\t\n");
    int input = get_math_input(); 

    switch (input)
    {
    case 1:{
        char inputmatrix[2][17];
        char result[18];

        if (PrepareBinaryInputs(inputmatrix) != 0) break;

        int result_status = Binary_Addition(inputmatrix, result);

        if (result_status == 0){
            printf("\n""The sum of the 2 binary bumbers is: %s\n",result);
        }
        break;
    }
    case 2:{
        char inputmatrix[2][17];
        char result[18];
        if (PrepareBinaryInputs(inputmatrix) != 0) break;
        Twos_complement(inputmatrix[1]); //Only the 2nd number needs to become 2s complement form

        int result_status = Binary_Addition(inputmatrix, result);

        if (result_status == 0){
            printf("\n""The mathematical operation of the two binary bnumbers is: %s\n",result);
        }
        break;
    }
    case 3:
        //Binary_Multiplication();
        break;
    case 4:
        main_menu();
        break;
    default:
        main_menu();
        break;
    }
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
    if(strlen(BinaryInput) == 4 || strlen(BinaryInput) == 8 || strlen(BinaryInput) == 16){
        return 0;
    }else{
        return -1;
    }
}

int Binary_Addition(const char BinaryMatrix[2][17],char *output_buffer){
    int Bit1;
    int Bit2;
    int carry = 0;
    char result[17];
    for(int i = 15; i >=0 ; i--){
        Bit1 = (BinaryMatrix[0][i] - '0');
        Bit2 = (BinaryMatrix[1][i] - '0');

        if(Bit1 + Bit2 + carry == 0){
            result[i] = '0';
            carry = 0;
        }else if(Bit1 + Bit2 + carry == 1){
            result[i] = '1';
            carry = 0;
        }else if(Bit1 + Bit2 + carry == 2){
            result[i] = '0';
            carry = 1;
        }else if(Bit1 + Bit2 + carry == 3){
            result[i] = '1';
            carry = 1;
        }
    }
   
    printf("Number Valid");
    strncpy(output_buffer,result,16);
    output_buffer[16] = '\0';
    return 0;   
    
}

void Twos_complement(char SubtractorInput[]){
    bool BitCheck = false;
    for(int i = 15;i>=0;i--){
        char bit = SubtractorInput[i];
        if(BitCheck == false){
            if(bit == '1'){
                BitCheck = true;
            }
        }else{
            if (SubtractorInput[i] =='0'){
                SubtractorInput[i] = '1';
            }else{
                SubtractorInput[i] = '0';
            }
        }
    }
}

int PrepareBinaryInputs(char inputmatrix[2][17]){
    char number1[17];
    char number2[17];
    char result[18];

    if (enter_binary_number(number1, sizeof(number1)) != 0) return -1;
    if (enter_binary_number(number2, sizeof(number2)) != 0) return -1;

    size_t len1 = strlen(number1);
    memset(inputmatrix[0], '0', 16);
    inputmatrix[0][16] = '\0';
    if (len1 <= 16) {
        strncpy(inputmatrix[0] + (16 - len1), number1, len1);
    }

    size_t len2 = strlen(number2);
    memset(inputmatrix[1], '0', 16);
    inputmatrix[1][16] = '\0';
    if (len2 <= 16) {
        strncpy(inputmatrix[1] + (16 - len2), number2, len2);
    }
    return 0;
}
int Binary_Multiplication(const char BinaryMatrix[2][17],char *output_buffer){
    char product[16][33];
    for(int r = 0;r<16;r++){
        for(int c = 0;c<32;c++){
            product[r][c] = '0';
        }
    product[r][32] = '\0';
    }

    for(int i = 15; i>=0; i--){
        int currentmultiplier = BinaryMatrix[1][i] - '0';
        int row_index = 15-i;
        if (currentmultiplier == 0){
            continue;
        }
        for(int t = 15; t>=0; t--){
            char product_bit = BinaryMatrix[0][t];
            int multiplier_shift = 15-i;
            int multiplicand_shift = 15-t;
            int total_offset = multiplier_shift + multiplicand_shift;
            int column_index = 31 - total_offset;

            if(column_index>=0 &&column_index<32){
                product[row_index][column_index] = product_bit;
            }
        }
    }
    char current_sum[33];
    char next_add[2][33];

    strcpy(current_sum, product[0]);
    for(int r = 1;r<16;r++){
        strcopy(next_add[0],current_sum);
        strcopy(next_add[1],product[r]);
        int status = Binary_Addition_32bit(next_add,current_sum);
        if(status != 0){
            printf("Error during addition");
            return -1;
        }
    }
    strcpy(output_buffer, current_sum);
    return 0;
}

int Binary_Addition_32bit(const char BinaryMatrix[2][33], char *output_buffer){
    int Bit1;
    int Bit2;
    int carry = 0;
    char result[33];
    for(int i = 31; i >=0 ; i--){
        Bit1 = (BinaryMatrix[0][i] - '0');
        Bit2 = (BinaryMatrix[1][i] - '0');

        if(Bit1 + Bit2 + carry == 0){
            result[i] = '0';
            carry = 0;
        }else if(Bit1 + Bit2 + carry == 1){
            result[i] = '1';
            carry = 0;
        }else if(Bit1 + Bit2 + carry == 2){
            result[i] = '0';
            carry = 1;
        }else if(Bit1 + Bit2 + carry == 3){
            result[i] = '1';
            carry = 1;
        }
    }
   
    printf("Number Valid");
    strncpy(output_buffer,result,32);
    output_buffer[32] = '\0';
    return 0;
}