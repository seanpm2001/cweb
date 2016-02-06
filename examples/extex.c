#define discard_to(x){while(get()!=x);} \

#define pair(x,y)(a==x&&b==y) \

#define nop 0
#define start_section 1
#define start_C 2
#define start_name 3
#define start_index 4
#define start_insert 5
#define end_item 6 \

/*2:*/
#line 46 "extex.w"

#include <stdio.h>
#include <ctype.h>

/*3:*/
#line 73 "extex.w"

int c;

/*:3*//*14:*/
#line 229 "extex.w"

char ptab[]= {0,1,1,1,1,0,
1,1,1,1,1,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,
1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,
0,0,1,1,1,0,0,0,
0,1,1,0,1,0,0,1,
0,0,0,0,1,1,1,0,
0,0,0,1,1,1,0};

/*:14*//*17:*/
#line 285 "extex.w"

char wtab[]= {start_section,nop,nop,nop,nop,nop,nop,nop,
start_name,nop,start_section,nop,nop,nop,start_index,nop,
nop,nop,nop,nop,nop,nop,nop,nop,
nop,nop,start_index,nop,start_name,start_insert,end_item,nop,

nop,nop,nop,start_C,start_C,nop,start_C,nop,
nop,nop,nop,nop,nop,nop,nop,nop,
start_C,nop,nop,nop,start_insert,nop,nop,nop,
nop,nop,nop,nop,nop,nop,start_index,nop,
nop,nop,nop,start_C,start_C,nop,start_C,nop,
nop,nop,nop,nop,nop,nop,nop,nop,
start_C,nop,nop,nop,start_insert};

/*:17*/
#line 50 "extex.w"

/*6:*/
#line 105 "extex.w"

int get()
{register int x;
x= getchar();
if(x==EOF)exit(0);
return x;
}

/*:6*//*12:*/
#line 184 "extex.w"

controlseq()
{
int l;
char a,b;
l= 0;
a= c= getchar();
while(isalpha(c)){
l++;
c= getchar();
if(l==1)b= c;
}
if(l==0)c= getchar();
/*13:*/
#line 204 "extex.w"

if(a>='"'&&a<='~'&&ptab[a-'"']==l||
(l==2&&(pair('a','e')||pair('A','E')
||pair('o','e')||pair('O','E')
||pair('a','a')||pair('A','A')||pair('s','s')))){
putchar('\\');
putchar(a);
if(l==2)putchar(b);
if(l&&c==' '){
putchar(' ');
c= getchar();
}
if(c=='{'){
do{putchar(c);
c= get();
}while(c!='}');
putchar(c);
c= 0;
}
return 1;
}

/*:13*/
#line 198 "extex.w"
;
return 0;
}

/*:12*/
#line 51 "extex.w"


main(argc,argv)
int argc;
char*argv[];
{
/*4:*/
#line 76 "extex.w"

int web;
int comment;
int skipping;
int save_skipping;
register int cc;

/*:4*/
#line 57 "extex.w"
;
if(strcmp(*argv,"excweb")==0){
web= 1;
/*15:*/
#line 244 "extex.w"

ptab[12]= 1;

/*:15*/
#line 60 "extex.w"
;
}else web= 0;
comment= skipping= c= 0;
main_cycle:if(c)goto big_switch;
restart:c= get();
big_switch:switch(c){
/*5:*/
#line 90 "extex.w"

case'%':discard_to('\n');goto restart;
case'$':c= getchar();
if(c!='$')discard_to('$')
else{
do discard_to('$')
while(getchar()!='$');
}
goto restart;

/*:5*//*7:*/
#line 117 "extex.w"

case'a':case'A':
case'b':case'B':
case'c':case'C':
case'd':case'D':
case'e':case'E':
case'f':case'F':
case'g':case'G':
case'h':case'H':
case'i':case'I':
case'j':case'J':
case'k':case'K':
case'l':case'L':
case'm':case'M':
case'n':case'N':
case'o':case'O':
case'p':case'P':
case'q':case'Q':
case'r':case'R':
case's':case'S':
case't':case'T':
case'u':case'U':
case'v':case'V':
case'w':case'W':
case'x':case'X':
case'y':case'Y':
case'z':case'Z':
goto out_word;

/*:7*//*11:*/
#line 180 "extex.w"

case'\\':if(controlseq())goto control_seq_in_word;
goto main_cycle;

/*:11*//*16:*/
#line 258 "extex.w"

case'@':if(web)goto do_web;
goto restart;
case'|':if(web>1){
save_skipping= skipping;
goto skip_C_prime;
}
goto restart;
case'*':if(!comment)goto restart;
c= getchar();
if(c=='/'){
comment= 0;
goto skip_C;
}
goto big_switch;

/*:16*/
#line 66 "extex.w"

case EOF:exit(0);
default:goto restart;
}
/*8:*/
#line 150 "extex.w"

out_word:putchar(c);
continue_word:c= getchar();
checkout_word:
if(isalpha(c))goto out_word;
if(c=='\''){
c= getchar();
if(isalpha(c)){
putchar('\'');goto out_word;
}
goto end_word;
}
if(c=='\\'&&controlseq())goto control_seq_in_word;
end_word:putchar('\n');
goto main_cycle;

/*:8*//*10:*/
#line 176 "extex.w"

control_seq_in_word:if(!c)goto continue_word;
goto checkout_word;

/*:10*//*18:*/
#line 301 "extex.w"

do_web:c= getchar();
if(c<' '||c>'t')goto restart;
switch(wtab[c-' ']){
case nop:case start_index:goto restart;
case start_section:web++;
comment= skipping= 0;goto restart;
case start_C:if(web>1)goto skip_C;
goto restart;
case start_name:case start_insert:if(web>1)skipping= 1;
goto restart;
case end_item:if(skipping)goto skip_C;
goto restart;
}

/*:18*//*19:*/
#line 321 "extex.w"

skip_C:save_skipping= 2;
skip_C_prime:skipping= 1;
while(1){
c= get();
C_switch:switch(c){
case'/':c= get();
if(c!='*')goto C_switch;
comment= 1;
case'|':if(save_skipping==2)continue;
skipping= save_skipping;goto restart;
case'@':c= getchar();
inner_switch:if(c<' '||c>'t')continue;
switch(wtab[c-' ']){
case nop:case start_C:case end_item:continue;
case start_section:web++;
comment= skipping= 0;goto restart;
case start_name:case start_index:goto restart;
case start_insert:do discard_to('@')while((c= getchar())=='@');
goto inner_switch;
}
case'\'':case'"':
while((cc= get())!=c&&cc!='\n')
if(cc=='\\')getchar();
else if(cc=='@'){
cc= getchar();
if(cc!='@'){
c= cc;goto inner_switch;
}
};
continue;
default:continue;
}
}

/*:19*/
#line 70 "extex.w"
;
}

/*:2*/
