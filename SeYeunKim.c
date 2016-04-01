//
//  SeYeunKim.c
//  Resume
//
//  Created by BadBoy17 on 1/04/2016.
//  Copyright (c) 2016 Sam. All rights reserved.
//

#include "SeYeunKim.h"

// skill node
typedef struct _skills{
    char *skillType;
    char *skillName;
    struct _skills *next;
}_skills;

// work experience node
typedef struct _workExp{
    char *companyName;
    char *dateFrom;
    char *dateTo;
    char *description;
    struct _workExp *next;
}_workExp;

// achievement node
typedef struct _achievement{
    char *achievementName;
    char *date;
    struct _achievement *next;
}_achievement;

// education node
typedef struct _education{
    char *institutionName;
    char *dateFrom;
    char *dateTo;
    struct _education *next;
}_education;

// language node
typedef struct _language{
    char *languageName;
    struct _language *next;
}_language;

// the skeleton for Se Yeun Kim
typedef struct _seyeunkim {
    int erstingThingsAboutMe;
    char *name;
    char *DOB;
    int age;
    char gender;
    // since ints won't allow for number to start with '0'
    char *mobile;
    
    struct _skills *mySkills;
    struct _workExp *myWorkExp;
    struct _achievement *myAcheivement;
    struct _education *myEducation;
    struct _language *myLanguage;
}_seyeunkim;


// create a new skill for Se Yeun Kim
static _skills *newSkill(char *sT, char *sN){
    struct _skills *skill;
    skill = malloc(sizeof(_skills));
    assert(skill != NULL);
    
    skill->next = NULL;
    skill->skillType = strdup(sT);
    skill->skillName = strdup(sN);
    return skill;
}

// create a new work experience for Se Yeun Kim
static _workExp *newWorkExp (char *cN, char *dF, char *dT, char *d){
    struct _workExp *workExp;
    workExp = malloc(sizeof(_workExp));
    assert(workExp != NULL);
    
    workExp->next = NULL;
    workExp->companyName = strdup(cN);
    workExp->dateFrom = strdup(dF);
    workExp->dateTo = strdup(dT);
    workExp->description = strdup(d);
    
    return workExp;
}

// create a new achievement for Se Yeun Kim
static _achievement *newAchievement(char *aN, char *d){
    struct _achievement *achievement;
    achievement = malloc(sizeof(_achievement));
    assert(achievement != NULL);
    
    achievement->next = NULL;
    achievement->achievementName = strdup(aN);
    achievement->date = strdup(d);
    
    return achievement;
}

// create a new education for Se Yeun Kim
static _education *newEducation(char *iN, char *dF, char *dT){
    struct _education *education;
    education = malloc(sizeof(_education));
    assert(education != NULL);
    
    education->next = NULL;
    education->institutionName = strdup(iN);
    education->dateFrom = strdup(dF);
    education->dateTo = strdup(dT);
    
    return education;
}

// create a new language for Se Yeun Kim
static _language *newLanguage(char *lN){
    struct _language *language;
    language = malloc(sizeof(_language));
    assert(language != NULL);
    
    language->next = NULL;
    language->languageName = strdup(lN);
    
    return language;
}


// the day Se Yeun was born
// creates a Se Yeun Kim Node. <<Constructor>>
sam on_15_04_1994()
{
    struct _seyeunkim *hereICome;
    hereICome = malloc(sizeof(_seyeunkim));
    assert (hereICome != NULL);
    
    hereICome->name = "Se Yeun Kim";
    hereICome->DOB = "15th April 1994";
    hereICome->age = 21;
    hereICome->gender = 'm';
    hereICome->mobile = "0403594187";
    
    hereICome->mySkills = NULL;
    hereICome->myWorkExp = NULL;
    hereICome->myAcheivement = NULL;
    hereICome->myEducation = NULL;
    hereICome->myLanguage = NULL;
    
    return hereICome;
}

// print the details of Se Yeun
void showResume(sam thisGuy, int section){
    assert(thisGuy != NULL);
    int length = 50;
    
    if (section == 0 || section == 1){
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
        printf("%s\n",thisGuy->name);
        printf("DOB: %s\n",thisGuy->DOB);
        printf("Age: %d\n",thisGuy->age);
        printf("Gender: %c\n",thisGuy->gender);
        printf("Mobile: %s\n",thisGuy->mobile);
        printf("\n");
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
        if (section == 1) return;
    }
    
    if (section == 0 || section == 2){
        printf("Work Experience\n\n");
        for (_workExp *ptr = thisGuy->myWorkExp; ptr != NULL; ptr = ptr->next) {
            printf("Company Name: %s\n", ptr->companyName);
            printf("From - %s\n",ptr->dateFrom);
            printf("To - %s\n",ptr->dateTo);
            printf("Description: \n%s\n\n",ptr->description);
        }
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
        if (section == 2) return;
    }
    
    if (section == 0 || section == 3){
        printf("Education\n\n");
        for (_education *ptr = thisGuy->myEducation; ptr != NULL; ptr = ptr->next) {
            printf("Institute: %s\n", ptr->institutionName);
            printf("From - %s\n",ptr->dateFrom);
            printf("To - %s\n\n",ptr->dateTo);
        }
        
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
        
        if (section == 3) return;
    }

    if (section == 0 || section == 4){
        printf("Skills\n\n");
        for (_skills *ptr = thisGuy->mySkills; ptr != NULL; ptr = ptr->next) {
            printf("Type: %s\n", ptr->skillType);
            printf("Name: %s\n\n",ptr->skillName);
        }
        
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
        
        if (section == 4) return;
    }
    
    if (section == 0 || section == 5){
        printf("Achievements\n\n");
        for (_achievement *ptr = thisGuy->myAcheivement; ptr != NULL; ptr = ptr->next) {
            printf("Title: %s\n", ptr->achievementName);
            printf("Date: %s\n\n",ptr->date);
        }
        
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
    }
}


// function to add skills to Se Yeun
void addSkill(sam thisGuy, char *sT, char *sN){
    assert(thisGuy != NULL);
    _skills *skill = newSkill(sT, sN);
    _skills *ptr = thisGuy->mySkills;
    // If Se Yeun has no skills :'(
    if (ptr == NULL) {
        // add the skill
        thisGuy->mySkills = skill;
    // If Se Yeun has skills :D
    } else {
        // find the last skill he's learnt
        while (ptr->next != NULL) ptr = ptr->next;
        // add the skill
        ptr->next = skill;
    }
}

// function to add work experience to Se Yeun
void addWorkExp(sam thisGuy, char *cN, char *dF, char *dT, char *d){
    assert(thisGuy != NULL);
    _workExp *workExp = newWorkExp(cN, dF, dT, d);
    _workExp *ptr = thisGuy->myWorkExp;
    // if Se Yeun has no work experience :'(
    if (ptr == NULL) {
        // add the work experience
        thisGuy->myWorkExp = workExp;
    // if Se Yeun has work experience :D
    } else {
        // find the last work experience he's had
        while (ptr->next != NULL) ptr = ptr->next;
        // add the work experience
        ptr->next = workExp;
    }
}

// function to add an achievement to Se Yeun
void addAchievement(sam thisGuy, char *aN, char *d){
    assert(thisGuy != NULL);
    _achievement *achievement = newAchievement(aN, d);
    _achievement *ptr = thisGuy->myAcheivement;
    // if Se Yeun has no achievements :'(
    if (ptr == NULL) {
        // add the achievement
        thisGuy->myAcheivement = achievement;
    // if Se Yeun has some achievements :D
    } else {
        // find the last achievement he's received
        while (ptr->next != NULL) ptr = ptr->next;
        // add the achievement
        ptr->next = achievement;
    }
}

// function to get Se Yeun educated
void addEducation(sam thisGuy, char *iN, char *dF, char *dT){
    assert(thisGuy != NULL);
    _education *education = newEducation(iN, dF, dT);
    _education *ptr = thisGuy->myEducation;
    // if Se Yeun has no education :'(
    if (ptr == NULL) {
        // give him education!
        thisGuy->myEducation = education;
    // if Se Yeun has been educated :D
    } else {
        // find the last education he partook
        while (ptr->next != NULL) ptr = ptr->next;
        // add the education
        ptr->next = education;
    }
}

// function to give Se Yeun a voice
void addLanguage(sam thisGuy, char *lN){
    assert(thisGuy != NULL);
    _language *language = newLanguage(lN);
    _language *ptr = thisGuy->myLanguage;
    // if Se Yeun doesn't know how to talk :'(
    if (ptr == NULL) {
        // give him a book dammit!
        thisGuy->myLanguage =  language;
    // if Se Yeun is polylinguistic :D
    } else {
        // find the last language he learnt
        while (ptr->next != NULL) ptr = ptr->next;
        // add the language
        ptr->next = language;
    }
}

// fill in the details for Se Yeun
void createResume(sam thisGuy){
    // add work experience
    char *companyName = "One Click Australia";
    char *dateFrom = "June 2014";
    char *dateTo = "Feb 2015";
    char *description = "Internship as assistant iOS application developer.";
    addWorkExp(thisGuy, companyName, dateFrom, dateTo, description);
    
    companyName = "CNY/Victoria Bar and Grill";
    dateFrom = "October 2014";
    dateTo = "Feb 2016";
    description = "Barista, Bartender, Waiter. People skills & customer service!!";
    addWorkExp(thisGuy, companyName, dateFrom, dateTo, description);
    
    
    // add education
    char *institutionName = "Willoughby Public School";
    dateFrom = "2000";
    dateTo = "2006";
    addEducation(thisGuy, institutionName, dateFrom, dateTo);
    
    institutionName = "Chatswood High School";
    dateFrom = "2007";
    dateTo = "2012";
    addEducation(thisGuy, institutionName, dateFrom, dateTo);
    
    institutionName = "UNSW - Commerce/Computer Science";
    dateFrom = "2014";
    dateTo = "2019";
    addEducation(thisGuy, institutionName, dateFrom, dateTo);
    
    // add skills
    char *skillType = "ComputerLanguage";
    char *skillName = "C";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Objective C";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Shell";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Perl";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Javscript (basic)";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Python (basic)";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "SQL";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Assembly Language - AVR Atmega2560";
    addSkill(thisGuy, skillType, skillName);
    
    skillName = "Java";
    addSkill(thisGuy, skillType, skillName);
    
    skillType = "Art";
    skillName = "Latte Art";
    addSkill(thisGuy, skillType, skillName);
    
    // add achievements
    char *achievementName = "Australian Mathematics Trust (AMT) 2010 Medal Award Winner";
    char *date = "October 2010";
    addAchievement(thisGuy, achievementName, date);
    
    achievementName = "HSC Graduate 97.25 ATAR";
    date = "2012";
    addAchievement(thisGuy, achievementName, date);
    
    achievementName = "High School - House Captain";
    date = "2011 - 2012";
    addAchievement(thisGuy, achievementName, date);
    
    achievementName = "High School - Mock Trial Team";
    date = "2011";
    addAchievement(thisGuy, achievementName, date);
    
    achievementName = "High School - Volleyball Captain";
    date = "2011";
    addAchievement(thisGuy, achievementName, date);
}

void options(sam thisGuy){
    char *P = "P";
    char *W = "W";
    char *E = "E";
    char *S = "S";
    char *A = "A";
    char *O = "O";
    char *exit = "exit";
    
    printf("Type the following to seek specific information (case sensitive):\n");
    printf("P - Personal Information\n");
    printf("W - Work Experience\n");
    printf("E - Education\n");
    printf("S - Skills\n");
    printf("A - Achievements\n");
    printf("O - Whole resume\n");
    printf("exit - stop viewing the resume\n");
    
    char input[1000];
    scanf("%s",input);
    int length = 50;
    for (int counter = 0; counter < length; counter++) printf("-");
    printf("\n");
    while (*input != *exit) {
        
        if (*input == *P) {
            showResume(thisGuy, 1);
        } else if (*input == *W){
            showResume(thisGuy, 2);
        } else if (*input == *E){
            showResume(thisGuy, 3);
        } else if (*input == *S){
            showResume(thisGuy, 4);
        } else if (*input == *A){
            showResume(thisGuy, 5);
        } else if (*input == *O){
            showResume(thisGuy, 0);
        } else {
            printf("Not a valid input...\n");
        }
        
        printf("Type the following to seek specific information (case sensitive):\n");
        printf("P - Personal Information\n");
        printf("W - Work Experience\n");
        printf("E - Education\n");
        printf("S - Skills\n");
        printf("A - Achievements\n");
        printf("exit - stop viewing the resume\n");
        for (int counter = 0; counter < length; counter++) printf("-");
        printf("\n");
        scanf("%s",input);
        
    }
}
