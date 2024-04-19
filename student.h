#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char *name;
    float *exam1_marks;
    float *exam2_marks;
};

void inputStudentData(struct Student *student);
float calculateAverage(float *marks, int size);
char gradeAssignment(float avg);
void generateGradeCard(struct Student *student);
void freeStudentMemory(struct Student *student);

#endif
