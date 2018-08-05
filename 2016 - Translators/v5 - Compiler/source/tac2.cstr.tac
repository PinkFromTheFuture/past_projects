
.table

int soma1_param
int soma1_a3
int soma2_param3
int soma_param1
int soma_param2
int soma_result
int life_a
int life_b
int main_var = 2
int main_var2


.code

soma1:
soma1:
soma1_param:
pop soma1_param
mov $2, 1
1:
mov $3, 2
2:
mov $4, 3
3:
mul $5, $3, $4
$3:
add $6, $2, $5
$2:
mov $7, 4
4:
add $8, $6, $7
$6:
mov soma1_a3, $8
$8:
return soma1_a3
soma1_a3:

soma2:
soma2:
soma2_param3:
pop soma2_param3
mov $13, 1
1:
mov $14, 2
2:
mov $15, soma2_param3
soma2_param3:
mul $16, $14, $15
$14:
add $17, $13, $16
$13:
mov $18, 4
4:
mov $19, 2
2:
mul $20, $18, $19
$18:
add $21, $17, $20
$17:
mov $22, 4
4:
mov $23, 4
4:
div $24, $22, $23
$22:
add $25, $21, $24
$21:
mov soma2_param3, $25
$25:
return soma2_param3
soma2_param3:

soma:
soma:
soma_param1:
pop soma_param1
soma_param2:
pop soma_param2
mov $31, soma_param1
soma_param1:
mov $32, soma_param2
soma_param2:
add $33, $31, $32
$31:
mov soma_result, $33
$33:
return soma_result
soma_result:

life:
life:
life_a:
pop life_a
life_b:
pop life_b
return 42
42:

main:
main:
mov $41, 2
2:
mov main_var, $41
$41:
mov $43, 3
3:
mov $44, 2
2:
add $45, $43, $44
$43:
mov main_var, $45
$45:
param 1
1:
param 2
2:
call life, 2
life:
$49:
pop $49
mov main_var, $49
$49:
param main_var
main_var:
call soma2, 1
soma2:
$53:
pop $53
mov main_var2, $53
$53:
return main_var2
main_var2:

