//
// Created by maoxiunan on 2019.09.09.
//

#include "Brackets.h"

Status bracket(char a, SqStack *S){
    if (!S) {
        return  ERROR;
    }
    if (a == '(' || a == '[' ) {
        Push_Sq(S, a);
    } else {
        SElemType_Sq e;
        Pop_Sq(S, &e);
        printf("%d\n",a);
        printf("%d\n",e);

        if (e == '(' && a != ')' || e == '[' && a != ']') {
            printf("当前数据不匹配");
        }
    }
}