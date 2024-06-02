
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int size;

typedef struct
{
    int id;
    char name[50];
    int marks[5];
    float gpa;
} Student;

void *calc_gpa(void *arg)
{
    Student *student = (Student *)arg;
    float totalMarks=0;
    for (int i = 0; i < 5; i++)
    {
        totalMarks+=student->marks[i];
    }
    
    student->gpa = (totalMarks / (5 * 100)) * 4.00;

    pthread_exit(NULL);
}

int main()
{
    printf("Enter number of students:\n");
    scanf("%d", &size);

    pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * size);
    Student *students = (Student *)malloc(sizeof(Student) * size);


    for (int i = 0; i < size; i++)
    {
        printf("Enter ID %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter name :");
        scanf("%s", students[i].name);
        printf("Enter marks :\n");
        for (int j = 0; j < 5; j++)
        {
            printf("Enter marks for Subj %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        pthread_create(&threads[i], NULL, calc_gpa, &students[i]);
    }
    for (int i = 0; i < size; i++)
    {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < size; i++)
    {
        printf("Student id: %d Name:%s GPA: %.2f\n", students[i].id, students[i].name,students[i].gpa);
    }

    free(threads);
    free(students);

    return 0;
}