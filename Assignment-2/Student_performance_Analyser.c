#include<stdio.h>


struct Student {
    int roll;
    char name[50];
    int marks1;
    int marks2;
    int marks3;
};
int total_sum(struct Student s) {
    return s.marks1 + s.marks2 + s.marks3;
}
float Avg(int total) {
    return total / 3.0;
}
char gradefn(float average) {
    if (average >= 85)
        return 'A';
    else if (average >= 70)
        return 'B';
    else if (average >= 50)
        return 'C';
    else if (average >= 35)
        return 'D';
    else
        return 'F';
}
void printPattern(char grade) {
    int stars;
    if (grade == 'A')
        stars = 5;
    else if (grade == 'B')
        stars = 4;
    else if (grade == 'C')
        stars = 3;
    else
        stars = 2;
int i=0;
    for ( i = 0; i < stars; i++) {
        printf("*");
    }

    printf("\n");
}
void printRollNumbers(int i, int n) {
    if (i>n)
        return;
    printf("%d ",i);
    printRollNumbers(i + 1, n);
}
int main(){
	 int n;
    int maximum = 100;
    scanf("%d", &n);
    if (n<1 || n>maximum) {
        printf("Invalid number of students.\n");
        return 0;
    }
	struct Student students[100];
	int i=0;
	for ( i = 0; i < n; i++) {
        scanf("%d %s %d %d %d",
              &students[i].roll,
              students[i].name,
              &students[i].marks1,
              &students[i].marks2,
              &students[i].marks3);
    }
     i=0;
     for (i = 0; i < n; i++) {

        int total = total_sum(students[i]);
        float average = Avg(total);
        char grade = gradefn(average);

        printf("Roll: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Total: %d\n", total);
        printf("Average: %.2f\n", average);
        printf("Grade: %c\n", grade);
        if (average < 35) {
            continue;
        }

        printf("Performance: ");
        printPattern(grade);
    }
      printf("List of Roll Numbers (via recursion): ");
    printRollNumbers(1, n);
    printf("\n");

    return 0;
}
