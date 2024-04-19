#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char *name;
    float exam1_marks[5];
    float exam2_marks[5];
    char grade1;
    char grade2;
};

const char *subject_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};

struct Student* createStudent();
void inputStudentData(struct Student *student);
float calculateAverage(float marks[], int size);
char gradeAssignment(float avg);
void generateGradeCard(struct Student *student);
void destroyStudent(struct Student *student);

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        struct Student *student = createStudent();

        printf("\nStudent %d:\n\n", i + 1);
        inputStudentData(student);

        float avg1 = calculateAverage(student->exam1_marks, 5);
        float avg2 = calculateAverage(student->exam2_marks, 5);

        student->grade1 = gradeAssignment(avg1);
        student->grade2 = gradeAssignment(avg2);

        generateGradeCard(student);

        destroyStudent(student);
    }

    return 0;
}

struct Student* createStudent() {
    struct Student *student = (struct Student*)malloc(sizeof(struct Student));
    if (student == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    student->name = (char*)malloc(50 * sizeof(char));
    if (student->name == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return student;
}

void inputStudentData(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    for (int i = 0; i < 5; i++) {
        printf("Enter marks for %s: ", subject_names[i]);
        scanf("%f", &student->exam1_marks[i]);
    }

    printf("Enter marks for exam 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter marks for %s: ", subject_names[i]);
        scanf("%f", &student->exam2_marks[i]);
    }
}

float calculateAverage(float marks[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}

char gradeAssignment(float avg) {
    if (avg >= 90) {
        return 'S';
    } else if (avg >= 80) {
        return 'A';
    } else if (avg >= 70) {
        return 'B';
    } else if (avg >= 60) {
        return 'C';
    } else if (avg >= 50) {
        return 'D';
    } else if (avg >= 40) {
        return 'E';
    } else {
        return 'F';
    }
}

void generateGradeCard(struct Student *student) {
    printf("\n===== Grade Card =====\n");
    printf("Name: %s\n", student->name);
    printf("Exam 1 Grade: %c\n", student->grade1);
    printf("Exam 2 Grade: %c\n", student->grade2);
}

void destroyStudent(struct Student *student) {
    free(student->name);
    free(student);
}
