#include <stdio.h>

struct Student {
    int id;
    int age;
    float gpa;
    char name[50];
};
void saveToFile(struct Student students[], int n) {
    FILE *f = fopen("students.txt", "w");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %d %.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].age, 
                students[i].gpa);
    }
    
    fclose(f);
    printf("Da luu danh sach vao file students.txt\n");
}

int loadFromFile(struct Student students[]) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Khong tim thay file students.txt hoac khong mo duoc file!\n");
        return 0; 
    }
    
    int n = 0;
    while (n < 5 && fscanf(f, "%d %s %d %f", 
                           &students[n].id, 
                           students[n].name, 
                           &students[n].age, 
                           &students[n].gpa) == 4) {
        n++;
    }
    
    fclose(f);
    return n;
}

int main() {
    struct Student students[5];
    int n;
        n = loadFromFile(students);
    
    if (n == 0) {
        printf("Khong co du lieu nao trong file.\n");
        return 0;
    }
        printf("Danh sach doc tu file:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
    
    return 0;
}