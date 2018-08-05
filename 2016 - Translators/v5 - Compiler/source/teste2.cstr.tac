
.table

int main_param2
char main_a3 [] = ""
int main_bc4 = 4
char main_str5 [] = "asdalkdjakda"
int main_c6 = 4


.code

main:
main:
main_param2:
pop main_param2
mov $2, &main_"3"
&main_"3":
mov $4, &main_a3
&main_a3:
mov $6, 0
0:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__string__attribution__label__8:
mov $9, $2[$6]
$2:
$9:
push $9
$12:
pop $12
mov $4[$6], $12
$6:
add $6, $6, 1
$6:
mov $16, $4[$6]
$4:
mov $18, '\0'
'\0':
$16:
seq $20, $16, $18
__string__attribution__label__8:
brz __string__attribution__label__8, $20
mov $23, 4
4:
mov main_bc4, $23
$23:
mov $25, main_bc4
main_bc4:
mov main_c6, $25
$25:

