#include <stdio.h>

struct Student
{
    int id;
    int age;
    float gpa;
    char name[50];
};

int main(void)
{
    struct Student students[3] = {
        {1, 18, 1.50f, "Tung"},
        {2, 18, 1.80f, "Bach"},
        {3, 8, 1.20f, "Dung"}};

    for (int i = 0; i < 3; ++i)
    {
        printf("Student %d: id=%d, name=%s, age=%d, gpa=%.2f\n",
               i + 1,
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
    return 0;
}