/*THIS PROGRAM IS WRIIEN FOR A CLASS OF 50 STUDENTS HAVING 10 SUBJECTS IN THEIR COURSE USER ARE ASKED TO 
JUST CHANGE THE NO OF MAX_STUDENTS FROM 50 TO AS PER THE STRENGTH OF THE CLASS BY JUST CFHANGING THE NUMVBER 
THE NUMBER OF SUBJECTS IS 5 HERE TEACHERS OR USERS CAN CHANGE THE NUMBER OF SUBJECTS STUDENTS STUDY ACCORDING
TO THE PRESCRIBED COURSE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 50 // 50 students (CAN BE CHANGED ACCORDING TO THE NUMBER OF STUDENTS IN THE CLASS)
#define MAX_SUBJECTS 5 //10 subjects (CAN BE CHANGED ACCORDING TO THE NO OF SUBJECTS IN THE COURSE)
#define NAME_LENGTH 20 // maximum name of 20  characters
struct Student 
{
    char name[NAME_LENGTH];
    float scores[MAX_SUBJECTS];
    float avg;
};//developed the structure
void add_student(struct Student students[], int *num_students) 
{
    if (*num_students >= MAX_STUDENTS) 
    {
        printf("Details of 50 students over\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", students[*num_students].name);
    (*num_students)++;
    printf("Student added successfully!\n");
}//this function is to add students name
void add_scores(struct Student students[], int num_students) {
    if (num_students == 0) 
    {
        printf("No students added yet. Please add a student first.\n");
        return;
    }
    char name[NAME_LENGTH];
    int found = 0;
    printf("Enter student name: ");
    scanf("%s", name);
    for (int i = 0; i < num_students; i++) 
    {
        if (strcmp(students[i].name, name) == 0) //compares whether the given name and resuilts asked for name is same
        {
            printf("Enter scores for %s (space in between) out of 100: ", students[i].name);
            for (int j = 0; j < MAX_SUBJECTS; j++)
            {
                scanf("%f", &students[i].scores[j]);
            }
            printf("Scores added successfully!\n");
            found = 1;
            break;
        }
    }
    if (found=0)
    {
        printf("Student not found.\n");
    }
}//enter the marks of students
void calculate_average(struct Student students[], int num_students)
{
    for (int i = 0; i < num_students; i++) {
        float total = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++)
        {
            total += students[i].scores[j];
        }
        students[i].avg = total / MAX_SUBJECTS;
    }
}
void display_summary(struct Student students[], int num_students) 
{
    for (int i = 0; i < num_students; i++)
    {
        printf("\nStudent Name: %s\n", students[i].name);
        printf("Scores: ");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%.2f ", students[i].scores[j]);
        }
        printf("\nAverage Score: %.2f\n", students[i].avg);

        float h= students[i].scores[0];
        float l = students[i].scores[0];
        for (int j = 1; j < MAX_SUBJECTS; j++) {
            if (students[i].scores[j] > h) 
            {
                h= students[i].scores[j];
            }
            if (students[i].scores[j] < l) {
                l = students[i].scores[j];
            }
        }
        printf("Highest Score: %.2f\n", h);
        printf("Lowest Score: %.2f\n", l);
        int marks=students[i].avg;
        if (marks<50){printf("Grade is of the student %d is F\n",i+1);} 
        else if (marks>=50 && marks<60){printf("Grade is C\n");} 
        else if (marks>=60 && marks<70){printf("Grade is B\n");} 
        else if (marks>=70 && marks<80){printf("Grade is B+\n");} 
        else if (marks>=80 && marks<90){printf("Grade is A\n");} 
        else if (marks>=90 && marks<100){printf("Grade is A+\n");}
    }
}
int main() 
{
    struct Student students[MAX_STUDENTS];
    int num_students = 0;
    char choice;
    do
    {
        printf("\nOptions:\n");
        printf("1. Add a student\n");
        printf("2. Add scores for a student\n");
        printf("3. Display summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_student(students, &num_students);
                break;
            case '2':
                add_scores(students, num_students);
                break;
            case '3':
                calculate_average(students, num_students);
                display_summary(students, num_students);
                break;
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != '4');
    return 0;

}

