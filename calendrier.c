
#include"calendrier.h"

int inputYear(void){
    int year;
    int  flag = 0;
    printf("Please enter a year : ");
    scanf("%d", &year);
    do{
        
        if (year<1900 || year>2022){
            printf("Please enter a year (entre 1900 et 2022) !! ");
            scanf("%d", &year);
        }
        else{
            flag = 1;
        }

    }while(flag==0);

    return year;
}
void checkInput(void){
    int day1, day2;
    int flag = 0;
    printf("Please enter first day : ");
    scanf("%d", &day1);
    printf("Please enter second day : ");
    scanf("%d", &day2);
    do{
        
        if (MAX(day1, day2)>=27 || ((day1-day2)%7==0)){
            printf("Respectez les contraintes !! \n");
            printf("Please enter first day : ");
            scanf("%d", &day1);
            printf("Please enter second day : ");
            scanf("%d", &day2);
        }
        else{
            flag = 1;
        }

    }while(flag==0);
}

int* getWeekNum(int year, int daycode, int day1){
    int month, day, week=1,i=0;
    int *weekNum = (int*) malloc(sizeof(int));
    
    for ( month = 1; month <= 12; month++ ){
      
        
        for ( day = 1; day <= days_in_month[month]; day++ ){
            // Is day before Sat? Else start next line Sun.
            if(day1==day){
                    weekNum[i]=week;
                    i++;
                    printf("%d",week);
                    printf("\n");
                    
            }    
            if ( ( day + daycode ) % 7 <=0 ){
                
                week++; 
                
            } 
            
        }
         
        // Set position for next month
        daycode = ( daycode + days_in_month[month] ) % 7;
    }
    return weekNum;
}
int* getWeekDay(int year, int daycode, int day1){
    int month, day,_day,j=0;
    int *weekDay = (int*) malloc(sizeof(int));
    
    
    for ( month = 1; month <= 12; month++ ){
        _day=daycode;
      
        for ( day = 1; day <= days_in_month[month]; day++ ){
            
            // Is day before Sat? Else start next line Sun.
            if ( ( day + daycode ) % 7 <= 0 ){
                _day=0;
            } 
            else{
                if(day1==day){
                    weekDay[j]=_day;
                    j++;
                    printf("%d",_day);
                    printf("\n");

                }
            _day++;
            }
        }
        // Set position for next month
        daycode = ( daycode + days_in_month[month] ) % 7;
    }
    return weekDay;
}

int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;
    
    d1 = (year - 1.)/ 4.0;
    d2 = (year - 1.)/ 100.;
    d3 = (year - 1.)/ 400.;
    daycode = (year + d1 - d2 + d3) %7;
    return daycode;
}


int determineleapyear(int year)
{
    if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}

void calendar(int year, int daycode)
{
    int month, day, i=1,_day;
    FILE* fichier = NULL;
 
    fichier = fopen("test.txt", "w");
 
    if (fichier != NULL){
        for ( month = 1; month <= 12; month++ ){
             _day=daycode;
            printf("%s", months[month]);
            fprintf(fichier, "%s", months[month]);
            printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
            fprintf(fichier, "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");
            printf("%d\n",daycode);

            // Correct the position for the first date
            for ( day = 1; day <= 1 + daycode * 5; day++ ){
                printf(" ");
                
                fprintf(fichier, " ");
            }
            
            // Print all the dates for one month
            for ( day = 1; day <= days_in_month[month]; day++ ){
                printf("%2d", day );
                fprintf(fichier, "%2d", day);
                _day++;
                // Is day before Sat? Else start next line Sun.
                if ( ( day + daycode ) % 7 > 0 ){
                    
                    printf("   " );
                    fprintf(fichier,"   ");
                  
                }  
                else{
                    printf(" \t %d semaine\n ",i );
                    i++;
                    fprintf(fichier,"\n ");
                    _day=0;
                   
                   
                }
                
            }
            // Set position for next month
            daycode = ( daycode + days_in_month[month] ) % 7;
        }
    }
    fclose(fichier);
}