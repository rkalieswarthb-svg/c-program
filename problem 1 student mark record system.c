#include <stdio.h>

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

int main() {
    struct Student s;

    // Accept student details
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);   // reads full name with spaces

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Display student details
    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}