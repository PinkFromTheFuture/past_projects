
.table

int main_c
int main_a = 2
int main_b = 2


.code

multi:
return 3

main:
mov $3, 2
mov $4, 2
add $5, $3, $4
mov main_a, $5
call multi, 0
pop $7
mov main_b, $7
println main_a
println main_b

