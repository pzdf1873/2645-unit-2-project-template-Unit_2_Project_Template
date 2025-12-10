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
    case 3:{
        char inputmatrix[2][17];
        char result[33]; //error was here
        if (PrepareBinaryInputs(inputmatrix) != 0) break;
        
        int result_status = Binary_Multiplication(inputmatrix, result);

        if (result_status == 0){
            printf("\n""The mathematical operation of the two binary bnumbers is: %s\n",result);
        }
        break;
    }
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
    printf("\n>> Logical Operation Menu\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Logical AND\t\t\n"
           "\t2. Logical OR\t\t\n"
           "\t3. Logical NOT\t\t\n"
           "\t4. Exit to Menu\t\t\n"
           "\t\t\t\t\t\t\n");
    int input = get_logic_input();

    switch(input){
        case 1:{ //Logical AND 
            char inputmatrix[2][17];
            char result[18];
            if (PrepareBinaryInputs(inputmatrix) != 0) break;

            int result_status = Logical_AND(inputmatrix, result);

            if (result_status == 0){
                printf("\n""The result of applying a logical AND to the two numbers is: %s\n",result);
            }
        break;
        }
        case 2:{
            char inputmatrix[2][17];
            char result[18];
            if (PrepareBinaryInputs(inputmatrix) != 0) break;

            int result_status = Logical_OR(inputmatrix, result);

            if (result_status == 0){
                printf("\n""The result of applying a logical OR to the two numbers is: %s\n",result);
            }
            break;
        }
        case 3:{
            char number[17];
            char result[17];
            char temp_number[17];

            if (enter_binary_number(temp_number, sizeof(temp_number)) != 0) break;
            size_t len1 = strlen(temp_number);
            memset(number, '0', 16);
            number[16] = '\0';
            if (len1 <= 16) {
            strncpy(number + (16 - len1), temp_number, len1);
            }

            int result_status = Logical_NOT(number, result);

            if (result_status == 0){
                printf("\n""The result of applying a logical NOT to the number is: %s\n",result);
            }
            break;
        }
        case 4: 
            main_menu();
            break;
        default:
            main_menu();
            break;
    }
}

void Binary_Conversion(void) {
    printf("\n>> Logical Operation Menu\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Conversion to Denary\t\t\n"
           "\t2. Conversion to HEX\t\t\n"
           "\t3. Exit to Menu\t\t\n"
           "\t\t\t\t\t\t\n");
    int input = get_conversion_input();
    switch(input){
        case 1:{ //Binary to Denary
            char number[17];
            char temp_number[17];

            if (enter_binary_number(temp_number, sizeof(temp_number)) != 0) break;
            size_t len1 = strlen(temp_number);
            memset(number, '0', 16);
            number[16] = '\0';
            if (len1 <= 16) {
                strncpy(number + (16 - len1), temp_number, len1);
            }
            int denary_result = conversion_to_denary(number);
            
            printf("\n""Converting this binary number to denary gives: %d\n",denary_result);
            break;                
        }
        case 2:{
            char number[17];
            char temp_number[17];
            char result[17];

            if (enter_binary_number(temp_number, sizeof(temp_number)) != 0) break;
            size_t len1 = strlen(temp_number);
            memset(number, '0', 16);
            number[16] = '\0';
            if (len1 <= 16) {
                strncpy(number + (16 - len1), temp_number, len1);
            }
            int result_status = conversion_to_hex(number,result);
            printf("\n""Converting this binary number to hex gives: %s\n",result);
            break;            
        }
        case 3:
            main_menu();
            break;
        default:
            break;

    }
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
    if(strlen(BinaryInput) > 0 && strlen(BinaryInput) <= 16){
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
        strcpy(next_add[0],current_sum);
        strcpy(next_add[1],product[r]);
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
   
    strncpy(output_buffer,result,32);
    output_buffer[32] = '\0';
    return 0;
}

int Logical_AND(const char BinaryMatrix[2][17], char *output_buffer){
    int bit1;
    int bit2;
    char result[17];
    for(int i = 0;i<=15;i++){
        if(BinaryMatrix[0][i] == '1' && BinaryMatrix[1][i] == '1'){
            result[i] = '1';
        }else{
            result[i] = '0';
        }
    }
    strncpy(output_buffer,result,16);
    output_buffer[16] = '\0';
    return 0;
}

int Logical_OR(const char BinaryMatrix[2][17], char *output_buffer){
    int bit1;
    int bit2;
    char result[17];
    for(int i = 0;i<=15;i++){
        if(BinaryMatrix[0][i] == '1' || BinaryMatrix[1][i] == '1'){
            result[i] = '1';
        }else{
            result[i] = '0';
        }
    }
    strncpy(output_buffer,result,16);
    output_buffer[16] = '\0';
    return 0;
}
int Logical_NOT(char BinaryInput[16], char *output_buffer){
    char result[17];
    for(int i = 0;i<=15;i++){
        if(BinaryInput[i]=='1'){
            result[i] = '0';
        }else{
            result[i] = '1';
        }
    }
    strncpy(output_buffer,result,16);
    output_buffer[16] = '\0';
    return 0;
}
int conversion_to_denary(char BinaryInput[16]){
    int ComparisonArray[16] = {32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
    int denary_value = 0;

    for(int i=0;i<=15;i++){
        if(BinaryInput[i] == '1'){
            denary_value = denary_value + ComparisonArray[i];
        }
    }
    return denary_value;

}
 int conversion_to_hex(char BinaryInput[16],char *output_buffer){
    int denary_value = conversion_to_denary(BinaryInput);
    char hex_result[5];
    char hex_compare[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    hex_compare[16] = '\0';
    int quotient = denary_value;
    int i = 3; //Going from LSB as 4 has \0
    hex_result[4] = '\0';

    if (quotient ==0){
        strcpy(hex_result, "0000");
    }else{
        while (quotient > 0 && i >=0)
        {
            int remainder = quotient % 16;
            hex_result[i] = hex_compare[remainder];

            quotient/=16;
            i--;
        }
        while(i>=0){
            hex_result[i] = '0';
            i--;

        }
        
    }
    strcpy(output_buffer,hex_result);
    return 0;

}