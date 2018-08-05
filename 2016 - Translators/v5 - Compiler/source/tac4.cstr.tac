
.table

int apenas_if_a = 2
int nested_if_elses_a = 3
int main_a = 2


.code

apenas_if:
apenas_if:
mov $1, 2
2:
mov apenas_if_a, $1
$1:
mov $3, apenas_if_a
apenas_if_a:
mov $4, 2
2:
$3:
seq $5, $3, $4
__else__label__0__:
brz __else__label__0__, $5
mov $7, 3
3:
mov apenas_if_a, $7
$7:
__end__ifelse__label__0__:
jump __end__ifelse__label__0__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__0__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__0__:
return apenas_if_a
apenas_if_a:

nested_if_elses:
nested_if_elses:
mov $14, 3
3:
mov nested_if_elses_a, $14
$14:
mov $16, nested_if_elses_a
nested_if_elses_a:
mov $17, 2
2:
$16:
slt $18, $16, $17
__else__label__1__:
brz __else__label__1__, $18
mov $20, 3
3:
mov nested_if_elses_a, $20
$20:
__end__ifelse__label__1__:
jump __end__ifelse__label__1__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__1__:
mov $24, nested_if_elses_a
nested_if_elses_a:
mov $25, 3
3:
$24:
seq $26, $24, $25
__else__label__2__:
brz __else__label__2__, $26
mov $28, nested_if_elses_a
nested_if_elses_a:
mov $29, 4
4:
$28:
slt $30, $28, $29
__else__label__3__:
brz __else__label__3__, $30
mov $32, 5
5:
mov nested_if_elses_a, $32
$32:
__end__ifelse__label__3__:
jump __end__ifelse__label__3__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__3__:
mov $36, 6662
6662:
mov nested_if_elses_a, $36
$36:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__3__:
__end__ifelse__label__2__:
jump __end__ifelse__label__2__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__2__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__2__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__1__:
return nested_if_elses_a
nested_if_elses_a:

main:
main:
mov $45, 2
2:
mov main_a, $45
$45:
mov $47, main_a
main_a:
mov $48, 5
5:
$48:
slt $49, $48, $47
__else__label__4__:
brz __else__label__4__, $49
mov $51, main_a
main_a:
mov $52, main_a
main_a:
mul $53, $51, $52
$51:
mov main_a, $53
$53:
__end__ifelse__label__4__:
jump __end__ifelse__label__4__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__4__:
mov $57, 666
666:
mov main_a, $57
$57:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__4__:
call nested_if_elses, 0
nested_if_elses:
$60:
pop $60
mov main_a, $60
$60:
return main_a
main_a:

