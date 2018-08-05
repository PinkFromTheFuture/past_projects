
.table

int main_variavel1
int main_i = 0


.code

main:
main:
mov $1, 0
0:
mov main_i, $1
$1:
mov $3, main_i
main_i:
mov $4, 2
2:
mul $5, $3, $4
$3:
mov main_variavel1, $5
$5:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__0__:
mov $8, main_i
main_i:
mov $9, 10
10:
$8:
slt $10, $8, $9
__end__loop__label__0__:
brz __end__loop__label__0__, $10
mov $12, main_i
main_i:
mov $13, 1
1:
add $14, $12, $13
$12:
mov main_i, $14
$14:
__begin__loop__label__0__:
jump __begin__loop__label__0__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__0__:
mov $18, main_variavel1
main_variavel1:
mov $19, main_i
main_i:
add $20, $18, $19
$18:
mov main_variavel1, $20
$20:
return main_variavel1
main_variavel1:

