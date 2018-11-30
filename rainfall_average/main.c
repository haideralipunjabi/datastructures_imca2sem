/*
 * Title: Rainfall Average
 * Author: Haider Ali Punjabi
 * Email: haideralipunjabi@hackesta.org
 * Date: 20-11-2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
// Macros
#define MONTHS 12
#define YEARS 10
#define MAX 100;
#define MIN 0;
// Global Declaration
float Rainfall[YEARS][MONTHS];
float AvgYears[YEARS];
float AvgMonths[MONTHS];
int main()
{
    srand(time(NULL));      // Used to define starting point for rand() used in populate(), time(NULL) returns current time
    int ch,year,month;
    while(1){
        system("cls");
        printf("1. Populate Random Data Data\n2. Display Data\n3. Average Rainfall of each year\n4. Average Rainfall of each month\n5. Highest Rainfall among years\n6. Lowest Rainfall among years\n7. Highest Rainfall among months\n8. Lowest Rainfall among months\n9. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            populate();
            processData();
            break;
        case 2:
            displayData();
            break;
        case 3:
            displayArray(AvgYears,YEARS,"Year");
            break;
        case 4:
            displayArray(AvgMonths,MONTHS, "Month");
            break;
        case 5:
            year = findMax(AvgYears,YEARS);
            printf("Highest Rainfall is for Year %d = %.2f", year+1, AvgYears[year]);
            getch();
            break;
        case 6:
            year = findMin(AvgYears,YEARS);
            printf("Lowest Rainfall is for Year %d = %.2f",year+1, AvgYears[year]);
            getch();
            break;
        case 7:
            month = findMax(AvgMonths,MONTHS);
            printf("Highest Rainfall is for Month %d = %.2f",month+1, AvgMonths[month]);
            getch();
            break;
        case 8:
            month = findMin(AvgMonths,MONTHS);
            printf("Lowest Rainfall is for Month %d = %.2f",month+1, AvgMonths[month]);
            getch();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Error: Wrong Input, Try Again!");
            getch();
            break;
        }
    }
}

void populate(){
    int i,j;
    for(i=0;i<YEARS;i++){
        for(j=0;j<MONTHS;j++){
           // Uncomment the following two lines, and comment the third to Insert data manually 
           //printf("Insert Avg. Rainfall for Year %d, Month %d: ", i+1,j+1);
           //scanf("%f",&Rainfall[i][j]);
           Rainfall[i][j] = rand() % MAX    // Populate with random data
        }
    }
}

void displayData(){
    int i,j;
    for(i=0;i<YEARS;i++){
        for(j=0;j<MONTHS;j++){
            printf("%.2f\t",Rainfall[i][j]);
        }
        printf("\n");
    }
    getch();
}
void displayArray(float *arr, int size, char *prefix){
    int i;
    for(i=0;i<size;i++){
        printf("%s %d: %.2f\n",prefix,i+1,arr[i]);
    }
    getch();
}
void processData(){
    // Average of each year
    int i,j;
    float sum;
    for(i=0;i<YEARS;i++){
        sum = 0;
        for(j=0;j<MONTHS;j++){
            sum += Rainfall[i][j];
        }
        AvgYears[i] = sum/MONTHS;
    }

    // Average of each month
    for(i=0;i<MONTHS;i++){
        sum = 0;
        for(j=0;j<YEARS;j++){
            sum += Rainfall[j][i];
        }
        AvgMonths[i] = sum/YEARS;
    }
}

int findMin(float *arr, int size){
    int i, index;
    float min = MAX;
    for(i=0;i<size;i++){
        if(arr[i] < min){
            min = arr[i];
            index = i;
        }
    }
    return index;
}
int findMax(float *arr, int size){
    int i, index;
    float max = MIN;
    for(i=0;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }
    return index;
}
