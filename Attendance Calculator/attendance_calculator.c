/*****************
 * The Program is used to calculate student's 
 * total attendance
 * attendance percentage
 * store and access it from files
 * Author: G. Venkata Sai Ram
*****************/
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void createFiles();
void totalClasses(int);
void totalAttended(int);
void extraClasses(int);
void extraAttended(int);
float calculateTotalAttendance();
float calculateExtraAttendance();
void displayDetailedAttendance();
void resetAttendance();

int main()
{
    int update_total_classes,update_total_attended,update_extra_classes,update_extra_attended;
    float total_attendance,extra_attendance;
    int choice;
    FILE *file;
    file = fopen("total_classes.txt","r");    
    if(file == NULL){
        createFiles();
    }
    fclose(file);
    do{
        printf("--------------------Attendance Calculator--------------------\n");
        printf("1. Update Attendance\n");
        printf("2. View Attendance Percentage\n");
        printf("3. View Detailed Attendance\n");
        printf("4. Reset Attendance\n");
        printf("5. Exit\n");
        printf("--------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter new total classes held: ");
                scanf("%d",&update_total_classes);
                totalClasses(update_total_classes);
                printf("Enter new total classes attended: ");
                scanf("%d",&update_total_attended);
                totalAttended(update_total_attended);
                printf("Enter new extra classes held: ");
                scanf("%d",&update_extra_classes);
                extraClasses(update_extra_classes);
                printf("Enter new extra classes attended: ");
                scanf("%d",&update_extra_attended);
                extraAttended(update_extra_attended);
                printf("Attendance updated successfully\n");
                break;
                while(choice != 6)
                {
                    printf("Enter 6 to continue: ");
                    scanf("%d",&choice);
                }
            case 2: 
                total_attendance = calculateTotalAttendance();
                extra_attendance = calculateExtraAttendance();
                printf("--------------------Attendance Percentage--------------------\n");
                if(total_attendance == 0.0)
                    printf("Total Attendance: %.2f%%\n",0.0);
                else{
                    printf("Total Attendance: %.2f%%\n",total_attendance);
                    if(total_attendance < 75)
                        printf("You need to attend more classes to reach 75%% attendance\n");
                    else
                        printf("You have reached the minimum attendance requirement\n");
                }
                if(extra_attendance == 0.0)
                    printf("Extra Attendance: %.2f%%\n",0.0);
                else{
                    printf("Extra Attendance: %.2f%%\n",extra_attendance);
                    if(extra_attendance < 75)
                        printf("You need to attend more classes to reach 75%% attendance\n");
                    else
                        printf("You have reached the minimum attendance requirement\n");
                }
                while(choice != 6)
                {
                    printf("Enter 6 to continue: ");
                    scanf("%d",&choice);
                }
                break;
            case 3:
                displayDetailedAttendance();
                while(choice != 6)
                {
                    printf("Enter 6 to continue: ");
                    scanf("%d",&choice);
                }
                break; 
            case 4:
                resetAttendance();
                while(choice != 6)
                {
                    printf("Enter 6 to continue: ");
                    scanf("%d",&choice);
                }
                break;
            case 5:
                printf("Thanks for using my Program - GVSR, Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 5);
    return 0;
}

// Function to update the total classes held
void totalClasses(int updated_total_classes){
    FILE *file;
    int total_classes;
    file = fopen("total_classes.txt","r");
    fscanf(file,"%d",&total_classes);
    fclose(file);
    total_classes += updated_total_classes;
    file = fopen("total_classes.txt","w");
    fprintf(file,"%d",total_classes);
    fclose(file);
}

// Function to update the total classes attended
void totalAttended(int updated_total_attended){
    FILE *file;
    int total_attended;
    file = fopen("total_attended.txt","r");
    fscanf(file,"%d",&total_attended);
    fclose(file);
    total_attended += updated_total_attended;
    file = fopen("total_attended.txt","w");
    fprintf(file,"%d",total_attended);
    fclose(file);
}

// Function to update the extra classes held
void extraClasses(int updated_extra_classes){
    FILE *file;
    int extra_classes;
    file = fopen("extra_classes.txt","r");
    fscanf(file,"%d",&extra_classes);
    fclose(file);
    extra_classes += updated_extra_classes;
    file = fopen("extra_classes.txt","w");
    fprintf(file,"%d",extra_classes);
    fclose(file);
}

// Function to update the extra classes attended
void extraAttended(int updated_extra_attended){
    FILE *file;
    int extra_attended;
    file = fopen("extra_attended.txt","r");
    fscanf(file,"%d",&extra_attended);
    fclose(file);
    extra_attended += updated_extra_attended;
    file = fopen("extra_attended.txt","w");
    fprintf(file,"%d",extra_attended);
    fclose(file);
}

// Function to calculate the total attendance percentage
float calculateTotalAttendance(){
    FILE *file;
    int total_classes,total_attended;
    float total_attendance;
    file = fopen("total_classes.txt","r");
    fscanf(file,"%d",&total_classes);
    fclose(file);
    file = fopen("total_attended.txt","r");
    fscanf(file,"%d",&total_attended);
    fclose(file);
    total_attendance = (float)total_attended/total_classes * 100;
    if(total_classes == 0)
        total_attendance = 0.0;
    return total_attendance;
}

// Function to calculate the extra attendance percentage
float calculateExtraAttendance(){
    FILE *file;
    int extra_classes,extra_attended;
    float extra_attendance;
    file = fopen("extra_classes.txt","r");
    fscanf(file,"%d",&extra_classes);
    fclose(file);
    file = fopen("extra_attended.txt","r");
    fscanf(file,"%d",&extra_attended);
    fclose(file);
    extra_attendance = (float)extra_attended/extra_classes * 100;
    if(extra_classes == 0)
        extra_attendance = 0.0;
    return extra_attendance;
}

// Function to create the necessary files if they don't exist
void createFiles(){
    FILE *file;
    file = fopen("total_classes.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    file = fopen("total_attended.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    file = fopen("extra_classes.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    file = fopen("extra_attended.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
}

// Function to display the detailed attendance information
void displayDetailedAttendance(){
    FILE *file;
    int total_classes,total_attended,extra_classes,extra_attended;
    float total_attendance,extra_attendance;
    file = fopen("total_classes.txt","r");
    fscanf(file,"%d",&total_classes);
    fclose(file);
    file = fopen("total_attended.txt","r");
    fscanf(file,"%d",&total_attended);
    fclose(file);
    file = fopen("extra_classes.txt","r");
    fscanf(file,"%d",&extra_classes);
    fclose(file);
    file = fopen("extra_attended.txt","r");
    fscanf(file,"%d",&extra_attended);
    fclose(file);
    total_attendance = (float)total_attended/total_classes * 100;
    extra_attendance = (float)extra_attended/extra_classes * 100;
    printf("--------------------Total Class Attendance Details--------------------\n");
    printf("Total Classes: %d\n",total_classes);
    if(total_classes == 0)
    {
        printf("Total Classes Attended: %d\n",0);
        printf("Total Attendance: %.2f%%\n",0.0);
    }
    else
    {
        printf("Total Classes Attended: %d\n",total_attended);
        printf("Total Attendance: %.2f%%\n",total_attendance);
        if(total_attendance < 75)
            printf("You need to attend more classes to reach 75%% attendance\n");
        else
            printf("You have reached the minimum attendance requirement\n");
    }
    printf("--------------------Extra Class Attendance Details--------------------\n");
    printf("Extra Classes: %d\n",extra_classes);
    if(extra_classes == 0)
    {
        printf("Extra Classes Attended: %d\n",0);
        printf("Extra Attendance: %.2f%%\n",0.0);
    }
    else
    {
        printf("Extra Classes Attended: %d\n",extra_attended);
        printf("Extra Attendance: %.2f%%\n",extra_attendance);
        if(extra_attendance < 75)
            printf("You need to attend more classes to reach 75%% attendance\n");
        else
            printf("You have reached the minimum attendance requirement\n");
    }
}

// Function to reset the attendance data
void resetAttendance(){
    FILE *file;
    // Backup the data
    file = fopen("total_classes.txt","r");
    int total_classes;
    fscanf(file,"%d",&total_classes);
    fclose(file);
    file = fopen("total_classes_bak.txt","w");
    fprintf(file,"%d",total_classes);
    fclose(file);
    file = fopen("total_attended.txt","r");
    int total_attended;
    fscanf(file,"%d",&total_attended);
    fclose(file);
    file = fopen("total_attended_bak.txt","w");
    fprintf(file,"%d",total_attended);
    fclose(file);
    file = fopen("extra_classes.txt","r");
    int extra_classes;
    fscanf(file,"%d",&extra_classes);
    fclose(file);
    file = fopen("extra_classes_bak.txt","w");
    fprintf(file,"%d",extra_classes);
    fclose(file);
    file = fopen("extra_attended.txt","r");
    int extra_attended;
    fscanf(file,"%d",&extra_attended);
    fclose(file);
    file = fopen("extra_attended_bak.txt","w");
    fprintf(file,"%d",extra_attended);
    fclose(file);
    // Reset the data
    file = fopen("total_classes.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    file = fopen("total_attended.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    file = fopen("extra_classes.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    file = fopen("extra_attended.txt","w");
    fprintf(file,"%d",0);
    fclose(file);
    printf("Attendance Reset Successfully\n");
}