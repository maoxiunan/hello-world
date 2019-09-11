//
// Created by maoxiunan on 2019.09.09.
//

#include "Brackets.c"					//**▲03 栈和队列**//

int main_c(int argc, char **argv)
{
   SqStack sqStack ;
    InitStack_Sq(&sqStack);
    bracket('(', &sqStack);
    bracket('(', &sqStack);
    bracket(')', &sqStack);
    bracket('}', &sqStack);
}
