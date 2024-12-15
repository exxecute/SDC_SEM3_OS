#include <stdio.h>
#include <stdint.h>

#define ENTER_NAME "Enter students name: "
#define ENTER_SECOND_NAME "Enter students second name: "
#define ENTER_AGE "Enter students age: "
#define ENTER_GROUP "Enter students group: "
#define ENTER_COURSE "Enter students course: "

#define ENTER_STRING "%255s"
#define ENTER_BYTE "%hhu"

#define STUDENTS_CARD "\r\nStudents card:\r\n"
#define NAME "Name: %s\r\n"
#define SECOND_NAME "Second name: %s\r\n"
#define AGE "Age: %d\r\n"
#define GROUP "Group: %d\r\n"
#define COURSE "Course: %d\r\n"

#define OK 0
#define ERROR 1

#define ERROR_MSG "Error with input line\r\n"

#define MAX_STRING_LENGTH 256

struct student_info_t {
    unsigned char name[MAX_STRING_LENGTH];
    unsigned char second_name[MAX_STRING_LENGTH];
    unsigned char age;
    unsigned char group;
    unsigned char course;
};

int set_students_struct(struct student_info_t * student_info) {
    printf(ENTER_NAME);
    if(scanf (ENTER_STRING, student_info->name) != 1) {
        printf(ERROR_MSG);
        return ERROR;
    }
    printf(ENTER_SECOND_NAME);
    if(scanf (ENTER_STRING, student_info->second_name) != 1) {
        printf(ERROR_MSG);
        return ERROR;
    }
    printf(ENTER_AGE);
    if(scanf (ENTER_BYTE, &student_info->age) != 1) {
        printf(ERROR_MSG);
        return ERROR;
    }
    printf(ENTER_GROUP);
    if(scanf (ENTER_BYTE, &student_info->group) != 1) {
        
        printf(ERROR_MSG);
        return ERROR;
    }
    printf(ENTER_COURSE);
    if(scanf (ENTER_BYTE, &student_info->course) != 1) {
        printf(ERROR_MSG);
        return ERROR;
    }
    return OK;
}

void print_students_struct(struct student_info_t student_info) {
    printf(STUDENTS_CARD);
    printf(NAME, student_info.name);
    printf(SECOND_NAME, student_info.second_name);
    printf(AGE, student_info.age);
    printf(GROUP, student_info.group);
    printf(COURSE, student_info.course);
}

int main(void) {
    struct student_info_t student_info;

    int is_valid = set_students_struct(&student_info);
    if(is_valid == OK) {
        print_students_struct(student_info);
    }

    return is_valid;
}