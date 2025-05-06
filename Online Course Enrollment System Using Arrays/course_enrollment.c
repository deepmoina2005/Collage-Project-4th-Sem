#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 50
#define MAX_ENROLLMENTS 50

// Structure to store course details
typedef struct {
    int courseID;
    char courseName[50];
    char instructor[50];
    float fee;
} Course;

// Structure to store student enrollment details
typedef struct {
    int studentID;
    char studentName[50];
    int enrolledCourses[MAX_COURSES];  // Stores indices of enrolled courses
    int numCourses;
} Student;

// Function to add a new course
void addCourse(Course courses[], int *courseCount) {
    if (*courseCount >= MAX_COURSES) {
        printf("Course limit reached.\n");
        return;
    }

    Course newCourse;
    printf("Enter course ID: ");
    scanf("%d", &newCourse.courseID);
    getchar(); // consume newline

    printf("Enter course name: ");
    fgets(newCourse.courseName, sizeof(newCourse.courseName), stdin);
    newCourse.courseName[strcspn(newCourse.courseName, "\n")] = '\0';

    printf("Enter instructor name: ");
    fgets(newCourse.instructor, sizeof(newCourse.instructor), stdin);
    newCourse.instructor[strcspn(newCourse.instructor, "\n")] = '\0';

    printf("Enter course fee: ");
    scanf("%f", &newCourse.fee);

    courses[*courseCount] = newCourse;
    (*courseCount)++;
    printf("Course added successfully!\n");
}

// Function to display all available courses
void displayCourses(Course courses[], int courseCount) {
    if (courseCount == 0) {
        printf("No courses available.\n");
        return;
    }

    printf("\n--- Available Courses ---\n");
    for (int i = 0; i < courseCount; i++) {
        printf("ID: %d | Name: %s | Instructor: %s | Fee: %.2f\n",
               courses[i].courseID,
               courses[i].courseName,
               courses[i].instructor,
               courses[i].fee);
    }
}

// Function to search for a course by name
void searchCourse(Course courses[], int courseCount) {
    char searchName[50];
    getchar(); // consume leftover newline
    printf("Enter course name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strstr(courses[i].courseName, searchName)) {
            printf("Course Found: ID: %d | Name: %s | Instructor: %s | Fee: %.2f\n",
                   courses[i].courseID, courses[i].courseName, courses[i].instructor, courses[i].fee);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching course found.\n");
    }
}

// Function to enroll a student in a course
void enrollStudent(Student *student, Course courses[], int courseCount) {
    if (student->numCourses >= MAX_COURSES) {
        printf("Student has reached the maximum number of enrollments.\n");
        return;
    }

    int courseID;
    printf("Enter Course ID to enroll in: ");
    scanf("%d", &courseID);

    int foundIndex = -1;
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].courseID == courseID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    for (int i = 0; i < student->numCourses; i++) {
        if (student->enrolledCourses[i] == foundIndex) {
            printf("⚠️ You are already enrolled in this course.\n");
            return;
        }
    }

    student->enrolledCourses[student->numCourses] = foundIndex;
    student->numCourses++;
    printf("Enrollment successful!\n");
}

// Function to display student's enrolled courses
void displayEnrolledCourses(Student student, Course courses[]) {
    if (student.numCourses == 0) {
        printf("You are not enrolled in any courses.\n");
        return;
    }

    printf("\n--- Enrolled Courses ---\n");
    for (int i = 0; i < student.numCourses; i++) {
        int index = student.enrolledCourses[i];
        printf("ID: %d | Name: %s | Instructor: %s | Fee: %.2f\n",
               courses[index].courseID,
               courses[index].courseName,
               courses[index].instructor,
               courses[index].fee);
    }
}

int main() {
    Course courses[MAX_COURSES];
    Student student = {1, "John Doe", {0}, 0};
    int courseCount = 0;
    int choice;

    while (1) {
        printf("\n======= Online Course Enrollment System =======\n");
        printf("1. Add Course\n");
        printf("2. View All Courses\n");
        printf("3. Search Course\n");
        printf("4. Enroll in a Course\n");
        printf("5. View Enrolled Courses\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCourse(courses, &courseCount);
                break;
            case 2:
                displayCourses(courses, courseCount);
                break;
            case 3:
                searchCourse(courses, courseCount);
                break;
            case 4:
                enrollStudent(&student, courses, courseCount);
                break;
            case 5:
                displayEnrolledCourses(student, courses);
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
