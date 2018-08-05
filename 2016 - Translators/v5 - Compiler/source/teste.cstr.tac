
.table

int aux_a
int aux_b
char get_empty_string_texto [] = 1
char main_s [] = "Achar uma agulha num palheiro"
char main_palheiro [] = ""
char main_result [] = ""
char main_dentro_de_string_posso_colocar_varios_caracteres_que_poderiam_ser_invalidos_fora_dela [] = "!@#$%^&*()_+áé'cç"
int main_a = 0
int main_b
char main_variavel_string_de_exemplo [] = ""
char main_variavel_string_de_exemplo2 [] = 0
char main_variavel_string_de_exemplo3 [] = 0
char main_var2 [] = "agulha"
int main_j = 0


.code

aux:
aux:
aux_a:
pop aux_a
aux_b:
pop aux_b
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__0__:
mov $4, aux_b
aux_b:
mov $5, aux_a
aux_a:
$5:
slt $6, $5, $4
__end__loop__label__0__:
brz __end__loop__label__0__, $6
mov $8, aux_b
aux_b:
mov $9, 1
1:
sub $10, $8, $9
$8:
mov aux_b, $10
$10:
__begin__loop__label__0__:
jump __begin__loop__label__0__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__0__:
mov $14, aux_a
aux_a:
mov $15, 10
10:
$14:
slt $16, $14, $15
__else__label__1__:
brz __else__label__1__, $16
mov $18, aux_a
aux_a:
mov $19, aux_a
aux_a:
add $20, $18, $19
$18:
mov aux_a, $20
$20:
__end__ifelse__label__1__:
jump __end__ifelse__label__1__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__1__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__1__:
return 1
1:

get_empty_string:
get_empty_string:
return get_empty_string_texto
get_empty_string_texto:

main:
main:
mov $29, 0
0:
mov main_a, $29
$29:
mov $31, 0
0:
mov main_j, $31
$31:
mov $33, main_a
main_a:
mov $34, 10
10:
$33:
slt $35, $33, $34
__else__label__2__:
brz __else__label__2__, $35
mov $37, main_a
main_a:
mov $38, main_a
main_a:
add $39, $37, $38
$37:
mov main_a, $39
$39:
mov $41, 20
20:
mov main_b, $41
$41:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__3__:
mov $44, main_b
main_b:
mov $45, main_a
main_a:
$45:
slt $46, $45, $44
__end__loop__label__3__:
brz __end__loop__label__3__, $46
mov $48, main_b
main_b:
mov $49, 1
1:
sub $50, $48, $49
$48:
mov main_b, $50
$50:
__begin__loop__label__3__:
jump __begin__loop__label__3__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__3__:
mov $54, main_b
main_b:
mov $55, main_a
main_a:
$55:
slt $56, $55, $54
__else__label__4__:
brz __else__label__4__, $56
mov $58, main_b
main_b:
mov main_a, $58
$58:
__end__ifelse__label__4__:
jump __end__ifelse__label__4__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__4__:
mov $62, main_a
main_a:
mov main_b, $62
$62:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__4__:
__end__ifelse__label__2__:
jump __end__ifelse__label__2__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__2__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__2__:
return main_result
main_result:

