//
//  SeYeunKim.h
//  Resume
//
//  Created by BadBoy17 on 1/04/2016.
//  Copyright (c) 2016 Sam. All rights reserved.
//

#ifndef __Resume__SeYeunKim__
#define __Resume__SeYeunKim__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _seyeunkim *sam;

// Constructor for Sam - inspired my momma kim
sam on_15_04_1994();

// print the details of Se Yeun
void showResume(sam thisGuy, int section);

// print the life of Se Yeun
void showChronological(sam thisGuy);

// function to add skills to Se Yeun
void addSkill(sam thisGuy, char *sT, char *sN);

// function to add work experience to Se Yeun
void addWorkExp(sam thisGuy, char *cN, char *dF, char *dT, char *d);

// function to add an achievement to Se Yeun
void addAchievement(sam thisGuy, char *aN, char *d);

// function to get Se Yeun educated
void addEducation(sam thisGuy, char *iN, char *dF, char *dT);

// function to give Se Yeun a voice
void addLanguage(sam thisGuy, char *lN);

// fill in the details for Se Yeun
void createResume(sam thisGuy);

// show some options
void options(sam thisGuy);

#endif /* defined(__Resume__SeYeunKim__) */
