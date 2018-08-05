
.table

int f0_a = 2
char f0_str [] = 2
char f0_b [] = ""
int dois_a
int dois_b
char f4_ret [] = "2"
int f6_param
int f7_param2
int f7_str
int f8_param2
int f8_str = 2
char f82_param2 [] = ""
char f82_str [] = ""
int f9_a = 2
char f92_ret [] = 2
int f10_ret = 2
int f11_ret = 2
int ifs4_aux = 3
int main_a = 2
int main_b = 2
char main_str1 [] = ""
char main_str2 [] = ""
int main_errada = 2
char main_FIXME [] = "2"
char main_b2 [] = "a"
char main_str [] = "str agulha str"
char main_palheiro [] = ""
char main_result [] = ""
int main_inteiro = 3


.code

f:
f:
return 2
2:

f0:
f0:
mov $3, 2
2:
mov f0_a, $3
$3:
call f, 0
f:
$5:
pop $5
mov f0_a, $5
$5:
mov $8, &f0_
&f0_:
mov $10, &f0_b
&f0_b:
mov $12, 0
0:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__string__attribution__label__14:
mov $15, $8[$12]
$8:
$15:
push $15
$18:
pop $18
mov $10[$12], $18
$12:
add $12, $12, 1
$12:
mov $22, $10[$12]
$10:
mov $24, '\0'
'\0':
$22:
seq $26, $22, $24
__string__attribution__label__14:
brz __string__attribution__label__14, $26
return f0_a
f0_a:

f1:
f1:

f2:
f2:
return 1234
1234:

dois:
dois:
dois_a:
pop dois_a
dois_b:
pop dois_b
mov $36, dois_b
dois_b:
mov $37, dois_a
dois_a:
add $38, $36, $37
$36:
mov dois_a, $38
$38:
return dois_a
dois_a:

f3:
f3:

f4:
f4:
return f4_ret
f4_ret:

f6:
f6:
f6_param:
pop f6_param
mov $46, f6_param
f6_param:
mov $47, 2
2:
mul $48, $46, $47
$46:
mov f6_param, $48
$48:
return f6_param
f6_param:

f7:
f7:
f7_param2:
pop f7_param2
mov $53, f7_param2
f7_param2:
mov $54, f7_str
f7_str:
mul $55, $53, $54
$53:
mov f7_str, $55
$55:
return f7_str
f7_str:

f8:
f8:
f8_param2:
pop f8_param2
mov $60, 2
2:
mov f8_str, $60
$60:
mov $62, f8_param2
f8_param2:
mov $63, f8_str
f8_str:
mul $64, $62, $63
$62:
mov f8_str, $64
$64:
return f8_str
f8_str:

f82:
f82:
f82_param2:
pop f82_param2
return f82_param2
f82_param2:

f9:
f9:
mov $71, 2
2:
mov f9_a, $71
$71:
return f9_a
f9_a:

f92:
f92:
return f92_ret
f92_ret:

f10:
f10:
call f9, 0
f9:
$77:
pop $77
mov f10_ret, $77
$77:
return f10_ret
f10_ret:

f11:
f11:
call f9, 0
f9:
$82:
pop $82
mov f11_ret, $82
$82:
return f11_ret
f11_ret:

ifs1:
ifs1:
mov $87, 2
2:
mov $88, 3
3:
$87:
seq $89, $87, $88
__else__label__0__:
brz __else__label__0__, $89
return 3
3:
__end__ifelse__label__0__:
jump __end__ifelse__label__0__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__0__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__0__:
return 4
4:

ifs2:
ifs2:
mov $97, 2
2:
mov $98, 3
3:
$97:
seq $99, $97, $98
__else__label__1__:
brz __else__label__1__, $99
return 3
3:
__end__ifelse__label__1__:
jump __end__ifelse__label__1__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__1__:
return 4
4:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__1__:

ifs3:
ifs3:
mov $107, 2
2:
mov $108, 3
3:
$107:
seq $109, $107, $108
__else__label__2__:
brz __else__label__2__, $109
return 3
3:
__end__ifelse__label__2__:
jump __end__ifelse__label__2__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__2__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__2__:
return 3
3:

ifs4:
ifs4:
mov $117, 2
2:
mov $118, 3
3:
$117:
seq $119, $117, $118
__else__label__3__:
brz __else__label__3__, $119
call ifs2, 0
ifs2:
$121:
pop $121
mov ifs4_aux, $121
$121:
return ifs4_aux
ifs4_aux:
__end__ifelse__label__3__:
jump __end__ifelse__label__3__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__3__:
return 3
3:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__3__:

ifs5:
ifs5:
mov $130, 2
2:
mov $131, 3
3:
$130:
seq $132, $130, $131
__else__label__4__:
brz __else__label__4__, $132
mov $134, 2
2:
mov $135, 3
3:
$134:
seq $136, $134, $135
__else__label__5__:
brz __else__label__5__, $136
return 4
4:
__end__ifelse__label__5__:
jump __end__ifelse__label__5__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__5__:
mov $141, 2
2:
mov $142, 5
5:
$141:
seq $143, $141, $142
__else__label__6__:
brz __else__label__6__, $143
return 5
5:
__end__ifelse__label__6__:
jump __end__ifelse__label__6__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__6__:
mov $148, 2
2:
mov $149, 2
2:
$149:
sleq $150, $149, $148
__else__label__7__:
brz __else__label__7__, $150
return 1
1:
__end__ifelse__label__7__:
jump __end__ifelse__label__7__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__7__:
return 0
0:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__7__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__6__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__5__:
__end__ifelse__label__4__:
jump __end__ifelse__label__4__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__4__:
return 3
3:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__4__:

main:
main:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__begin__loop__label__8__:
mov $165, 2
2:
mov $166, 3
3:
$166:
slt $167, $166, $165
__end__loop__label__8__:
brz __end__loop__label__8__, $167
__begin__loop__label__8__:
jump __begin__loop__label__8__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__loop__label__8__:
mov $171, 2
2:
mov main_a, $171
$171:
mov $173, 2
2:
mov main_b, $173
$173:
mov $175, main_a
main_a:
mov $176, main_b
main_b:
$175:
seq $177, $175, $176
__else__label__9__:
brz __else__label__9__, $177
__end__ifelse__label__9__:
jump __end__ifelse__label__9__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__9__:
mov $181, main_a
main_a:
mov $182, main_b
main_b:
$182:
slt $183, $182, $181
__else__label__10__:
brz __else__label__10__, $183
mov $185, main_a
main_a:
mov $186, 1
1:
add $187, $185, $186
$185:
mov main_a, $187
$187:
__end__ifelse__label__10__:
jump __end__ifelse__label__10__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__10__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__10__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__9__:
mov $193, main_a
main_a:
mov $194, 2
2:
$193:
seq $195, $193, $194
__else__label__11__:
brz __else__label__11__, $195
mov $197, &main_"4"
&main_"4":
mov $199, &main_str2
&main_str2:
mov $201, 0
0:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__string__attribution__label__203:
mov $204, $197[$201]
$197:
$204:
push $204
$207:
pop $207
mov $199[$201], $207
$201:
add $201, $201, 1
$201:
mov $211, $199[$201]
$199:
mov $213, '\0'
'\0':
$211:
seq $215, $211, $213
__string__attribution__label__203:
brz __string__attribution__label__203, $215
return main_str2
main_str2:
__end__ifelse__label__11__:
jump __end__ifelse__label__11__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__11__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__11__:
mov $222, 1
1:
mov $223, 2
2:
$222:
sleq $224, $222, $223
__else__label__12__:
brz __else__label__12__, $224
mov $226, 4
4:
mov main_a, $226
$226:
__end__ifelse__label__12__:
jump __end__ifelse__label__12__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__12__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__12__:
mov $231, 4
4:
mov main_a, $231
$231:
__else__label__13__:
jump __else__label__13__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__13__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__13__:
mov $236, 4
4:
mov main_a, $236
$236:
__else__label__14__:
jump __else__label__14__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__14__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__14__:
mov $241, main_a
main_a:
mov $242, main_b
main_b:
$241:
seq $243, $241, $242
__else__label__15__:
brz __else__label__15__, $243
mov $245, 4
4:
mov main_a, $245
$245:
__end__ifelse__label__15__:
jump __end__ifelse__label__15__
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__else__label__15__:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__end__ifelse__label__15__:
mov $250, 2
2:
mov main_errada, $250
$250:
return main_FIXME
main_FIXME:
mov $253, 4
4:
mov main_a, $253
$253:
return main_b2
main_b2:
mov $256, &main_"3"
&main_"3":
mov $258, &main_b2
&main_b2:
mov $260, 0
0:
mov $0, $0 //this is a dummy line, to prevent two labels in a row.
__string__attribution__label__262:
mov $263, $256[$260]
$256:
$263:
push $263
$266:
pop $266
mov $258[$260], $266
$260:
add $260, $260, 1
$260:
mov $270, $258[$260]
$258:
mov $272, '\0'
'\0':
$270:
seq $274, $270, $272
__string__attribution__label__262:
brz __string__attribution__label__262, $274
return main_b2
main_b2:
return main_b2
main_b2:
return main_str1
main_str1:
return main_str1
main_str1:
return main_result
main_result:
return main_result
main_result:
mov $283, 2
2:
mov main_a, $283
$283:
param 2
2:
call f6, 1
f6:
$286:
pop $286
param main_str2
main_str2:
call f82, 1
f82:
$289:
pop $289
param "texto"
"texto":
call f82, 1
f82:
$292:
pop $292
param "a"
"a":
call f82, 1
f82:
$295:
pop $295
param main_str
main_str:
call f82, 1
f82:
$298:
pop $298
mov $300, 3
3:
mov main_inteiro, $300
$300:
mov $302, 2
2:
mov $303, 3
3:
add $304, $302, $303
$302:
mov main_a, $304
$304:
mov $306, 2
2:
mov main_a, $306
$306:
mov $308, 2
2:
mov $309, 3
3:
mul $310, $308, $309
$308:
mov $311, 4
4:
mul $312, $310, $311
$310:
mov main_a, $312
$312:
call f, 0
f:
$314:
pop $314
mov main_a, $314
$314:
mov $317, 2
2:
mov main_a, $317
$317:

