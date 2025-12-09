#ifndef FUNCS_H
#define FUNCS_H

void Mathematical_Operation(void);
void Logical_Operation(void);
void Binary_Conversion(void);
void menu_item_4(void);
int is_valid_input(const char BinaryInput[]);
int Binary_Addition(const char BinaryMatrix[2][17], char *output_buffer);
int Binary_Addition_32bit(const char BinaryMatrix[2][33], char *output_buffer);
void main_menu(void);
int enter_binary_number(char *output_buffer, size_t buffer_size);
int get_math_input(void);
void Twos_complement(char SubtractorInput[]);
int PrepareBinaryInputs(char inputmatrix[2][17]);


#endif