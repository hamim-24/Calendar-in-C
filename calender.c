#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int i,j,k,weekDays,space,year;
    char *months[] = {"-January-","February-","--March--","--April--","---May---","---June--",
                      "---July--","--August-","September","-October-","-November","-December"
                     };
    char *days[] = {"Sun","Mon","Tue","Wed","Thu","Fry","Sat"};
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    printf("\n\tEnter a year : ");
    scanf("%d",&year);
    fflush(stdin);

    //by this law, we can get the first day of a year
    weekDays = (year*365+((year-1)/4)-((year-1)/100)+((year-1)/400))%7;///law

    if((year%4==0&&year%100!=0)||(year%400==0)) {
        daysInMonth[1] = 29;
    }
    printf("\n\n\n\t================= Calendar of %d ================",year);

    for(i=0; i<12; i++) {
        printf("\n\n\t---------------------%s---------------------\n",months[i]);
        //printing days
        for(j=0; j<7; j++) {
            printf("\t%s\t",days[j]);
        }
        printf("\n");
        //printing first empty days of a month
        for(space=0; space<weekDays; space++) {
            printf("\t\t");
        }
        //printing dates
        for(k=1; k<=daysInMonth[i]; k++) {
            printf("\t %d\t",k);
            weekDays++;
            //printing a new line after 7 days
            if(weekDays > 6) {
                printf("\n");
                weekDays = 0;
            }
        }
    }
    printf("\n\n");
    char letter,fileName[100];
    FILE *fp;
again:
    printf("\tDo you want to save it (y/n) : ");
    scanf("%c",&letter);
    fflush(stdin);

    if(letter == 'y') {
        printf("\n\tEnter the file name : ");
        fgets(fileName,100,stdin);
        strcat(fileName,".txt");
        fp = fopen(fileName,"w");

        fprintf(fp,"\n\n\n\t================= Calender of %d ================",year);

        for(i=0; i<12; i++) {
            fprintf(fp,"\n\n\t---------------------%s---------------------\n",months[i]);
            //printing days
            for(j=0; j<7; j++) {
                fprintf(fp,"\t%s",days[j]);
            }
            fprintf(fp,"\n");
            //printing first empty days of a month
            for(space=0; space<weekDays; space++) {
                fprintf(fp,"\t");
            }
            //printing dates
            for(k=1; k<=daysInMonth[i]; k++) {
                fprintf(fp,"\t %d",k);
                weekDays++;
                //printing a new line after 7 days
                if(weekDays > 6) {
                    fprintf(fp,"\n");
                    weekDays = 0;
                }
            }
        }
        printf("\n\tFile is saved.\n");
        fprintf(fp,"\n\n");
        fclose(fp);
    } else if(letter == 'n'){
        printf("\n\tFile is not saved.\n");
    }else{
        goto again;
    }
    getchar();
}















