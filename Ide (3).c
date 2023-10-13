#include <stdio.h>
#include <string.h>

typedef struct {
    char username[30];
    char password[30];
} User;

#define m_user 50

User users[m_user];
int userCount = 0;

void registerUser() {
    if (userCount == m_user) {
        printf("Maximum user limit exceeded. Cannot register more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("User registered successfully!\n");
}

void loginUser() {
    char username[30], password[30];
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("User logged in successfully!\n");
            return;
        }
    }

    printf("The username and password are incorrect, try again\n");
}
int main() {
    int option;
 
    while (1) {
        printf("Press 'A' to Register \n Press 'B' to Login \n Press 'C' to Exit \n");
        scanf("%d", &option);
        if (option == 1) {
            registerUser();
        } else if (option == 2) {
            loginUser();
        } else if (option == 3) {
            printf("Program terminated.\n");
            break;
        } else {
            printf(".Choose an error Please try again.\n");
        }
        printf("\n");
    }

return 0;
}