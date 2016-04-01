//
//  main.c
//  Resume
//
//  Created by BadBoy17 on 1/04/2016.
//  Copyright (c) 2016 Sam. All rights reserved.
//

#include <stdio.h>
#include "SeYeunKim.h"

int main(int argc, char *argv[]){
    printf("Hello, Google!\n");
    printf("This is my interactive Resume.\n");
    
    sam SYK = on_15_04_1994();
    createResume(SYK);
    showResume(SYK, 0);
    options(SYK);
    return 0;
}