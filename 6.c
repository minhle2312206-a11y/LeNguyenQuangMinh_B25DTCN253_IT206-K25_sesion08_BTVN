#include <stdio.h>

#define SO_SV 10 

struct Student {
    int id;
    int age;
    float gpa;
    char name[50];
};

int main() {
    struct Student students[SO_SV] = {
        {1, 18, 8.5, "An"},
        {2, 19, 7.2, "Binh"},
        {3, 18, 9.0, "Cuong"},
        {4, 20, 6.8, "Dung"},
        {5, 18, 8.7, "Em"},
        {6, 19, 7.5, "Phuong"},
        {7, 18, 9.3, "Giang"},
        {8, 20, 5.9, "Hoa"},
        {9, 19, 8.1, "Hung"},
        {10,18, 7.8, "Lan"}
    };
        printf("=== DANH SACH SINH VIEN ===\n");
    printf("STT  Ten     Tuoi  GPA\n");
    printf("------------------------\n");
        float tongGPA = 0;
    for (int i = 0; i < SO_SV; i++) {
        printf("%2d   %-6s  %2d   %.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
        
        tongGPA += students[i].gpa; 
    }
        float gpaTrungBinh = tongGPA / SO_SV;
    
    printf("------------------------\n");
    printf("GPA TRUNG BINH LOP: %.2f\n", gpaTrungBinh);
    
    return 0;
}