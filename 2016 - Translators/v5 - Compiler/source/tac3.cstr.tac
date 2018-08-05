
.table

int while_in_while_a = 1
int while_in_while_b = 1
int main_a = 1
int main_b = 1


.code

while_in_while:
while_in_while:
mov $1, 1
1:
mov while_in_while_a, $1
$1:
mov $3, 1
1:
mov while_in_while_b, $3
$3:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__0__:
mov $6, while_in_while_a
while_in_while_a:
mov $7, 5
5:
$6:
sleq $8, $6, $7
__end__loop__label__0__:
brz __end__loop__label__0__, $8
mov $10, while_in_while_b
while_in_while_b:
mov $11, while_in_while_a
while_in_while_a:
mul $12, $10, $11
$10:
mov while_in_while_b, $12
$12:
mov $14, while_in_while_a
while_in_while_a:
mov $15, 1
1:
add $16, $14, $15
$14:
mov while_in_while_a, $16
$16:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__1__:
mov $19, while_in_while_a
while_in_while_a:
mov $20, 5
5:
$19:
sleq $21, $19, $20
__end__loop__label__1__:
brz __end__loop__label__1__, $21
mov $23, while_in_while_b
while_in_while_b:
mov $24, while_in_while_a
while_in_while_a:
mul $25, $23, $24
$23:
mov while_in_while_b, $25
$25:
mov $27, while_in_while_a
while_in_while_a:
mov $28, 1
1:
add $29, $27, $28
$27:
mov while_in_while_a, $29
$29:
__begin__loop__label__1__:
jump __begin__loop__label__1__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__1__:
__begin__loop__label__0__:
jump __begin__loop__label__0__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__0__:
return 1
1:

main:
main:
mov $37, 1
1:
mov main_a, $37
$37:
mov $39, 1
1:
mov main_b, $39
$39:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__2__:
mov $42, main_a
main_a:
mov $43, 5
5:
$42:
sleq $44, $42, $43
__end__loop__label__2__:
brz __end__loop__label__2__, $44
mov $46, main_b
main_b:
mov $47, main_a
main_a:
mul $48, $46, $47
$46:
mov main_b, $48
$48:
mov $50, main_a
main_a:
mov $51, 1
1:
add $52, $50, $51
$50:
mov main_a, $52
$52:
__begin__loop__label__2__:
jump __begin__loop__label__2__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__2__:
return main_b
main_b:

