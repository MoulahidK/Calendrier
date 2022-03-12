//
//  main.c
//  Calendrier
//
//  Created by MacBookPro on 2/3/2022.
//


#include"calendrier.c"






int main(void)
{
    int d;
    int year, daycode, leapyear;
    
    year = inputYear();
    daycode = determinedaycode(year);
    printf("\t%d\n",daycode);
    determineleapyear(year);
    // calendar(year, daycode);
    getWeekNum(year,daycode,6);
    printf("\n");
}
