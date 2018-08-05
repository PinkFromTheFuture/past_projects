
.table

char main_a [] = "1238278831781633718691763363131651931"
char main_b [] = "abc"


.code

main:
main:
mov $1, &main_a
&main_a:
mov $3, &main_b
&main_b:
mov $5, 0
0:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__string__attribution__label__7:
mov $8, $1[$5]
$1:
$8:
push $8
$11:
pop $11
mov $3[$5], $11
$5:
add $5, $5, 1
$5:
mov $15, $3[$5]
$3:
mov $17, '\0'
'\0':
$15:
seq $19, $15, $17
__string__attribution__label__7:
brz __string__attribution__label__7, $19
return main_b
main_b:

