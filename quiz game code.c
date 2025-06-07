#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUESTIONS_PER_LEVEL 10
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

typedef struct {
    char question[256];
    char options[4][100];
    int correctOption;
} Question;

typedef struct {
    char topicName[50];
    Question questions[QUESTIONS_PER_LEVEL];
} Topic;

Topic gk, sci, math;

// General Knowledge Questions
void fillGK(Topic *t) {
    strcpy(t->topicName, "General Knowledge");
    char *q[] = {
        "What is the capital of India?",
        "Which ocean is the largest?",
        "Who wrote India's national anthem?",
        "Currency used in Japan?",
        "Planet known as the Red Planet?",
        "First President of India?",
        "National animal of India?",
        "When is India's Independence Day?",
        "Longest river in the world?",
        "Host of 2020 Summer Olympics?"
    };
    char *opts[][4] = {
        {"1) Mumbai", "2) Delhi", "3) Kolkata", "4) Chennai"},
        {"1) Atlantic", "2) Indian", "3) Pacific", "4) Arctic"},
        {"1) Rabindranath Tagore", "2) Nehru", "3) Subhash Bose", "4) Gandhi"},
        {"1) Rupee", "2) Dollar", "3) Yen", "4) Won"},
        {"1) Earth", "2) Venus", "3) Mars", "4) Jupiter"},
        {"1) Rajendra Prasad", "2) Nehru", "3) Abdul Kalam", "4) Patel"},
        {"1) Tiger", "2) Lion", "3) Elephant", "4) Leopard"},
        {"1) 26 Jan", "2) 15 Aug", "3) 2 Oct", "4) 14 Nov"},
        {"1) Amazon", "2) Ganges", "3) Nile", "4) Yangtze"},
        {"1) China", "2) Japan", "3) France", "4) Brazil"}
    };
    int a[] = {2, 3, 1, 3, 3, 1, 1, 2, 3, 2};
int i;
    for ( i = 0; i < QUESTIONS_PER_LEVEL; i++) {
        strcpy(t->questions[i].question, q[i]);
        int j;
        for ( j = 0; j < 4; j++) strcpy(t->questions[i].options[j], opts[i][j]);
        t->questions[i].correctOption = a[i];
    }
}

// Science Questions
void fillScience(Topic *t) {
    strcpy(t->topicName, "Science");
    char *q[] = {
        "What is H2O?",
        "Closest planet to the sun?",
        " Which Gas is essential for breathing?",
        "Force pulling objects to Earth?",
        "Which organ pumps blood?",
        "Boiling point of water in Celsius?",
        "Part of plant making food?",
        "Vitamin from sunlight?",
        "Largest organ in human body?",
        "What protects the brain?"
    };
    char *opts[][4] = {
        {"1) Hydrogen", "2) Oxygen", "3) Water", "4) Steam"},
        {"1) Venus", "2) Mercury", "3) Earth", "4) Mars"},
        {"1) Nitrogen", "2) Carbon Dioxide", "3) Oxygen", "4) Helium"},
        {"1) Friction", "2) Gravity", "3) Magnetism", "4) Force"},
        {"1) Heart", "2) Brain", "3) Liver", "4) Lung"},
        {"1) 90", "2) 100", "3) 80", "4) 110"},
        {"1) Leaf", "2) Stem", "3) Root", "4) Fruit"},
        {"1) Vitamin A", "2) Vitamin B", "3) Vitamin C", "4) Vitamin D"},
        {"1) Skin", "2) Lungs", "3) Brain", "4) Heart"},
        {"1) Skull", "2) Spine", "3) Ribs", "4) Neck"}
    };
    int a[] = {3, 2, 3, 2, 1, 2, 1, 4, 1, 1};
int i;
    for ( i = 0; i < QUESTIONS_PER_LEVEL; i++) {
        strcpy(t->questions[i].question, q[i]);
        int j;
        for (j = 0; j < 4; j++) strcpy(t->questions[i].options[j], opts[i][j]);
        t->questions[i].correctOption = a[i];
    }
}

// Mathematics Questions
void fillMath(Topic *t) {
    strcpy(t->topicName, "Mathematics");
    char *q[] = {
        "What is 5 + 3?",
        "What is 12 - 4?",
        "What is 6 x 2?",
        "What is 15 / 3?",
        "What is the square of 4?",
        "What is the cube of 2?",
        "What is 10 mod 3?",
        "What is 7 x 6?",
        "What is 9 - 5?",
        "What is 3^2?"
    };
    char *opts[][4] = {
        {"1) 7", "2) 8", "3) 6", "4) 10"},
        {"1) 8", "2) 9", "3) 6", "4) 7"},
        {"1) 14", "2) 10", "3) 12", "4) 16"},
        {"1) 4", "2) 5", "3) 6", "4) 3"},
        {"1) 12", "2) 14", "3) 16", "4) 18"},
        {"1) 6", "2) 7", "3) 8", "4) 9"},
        {"1) 1", "2) 0", "3) 2", "4) 3"},
        {"1) 42", "2) 44", "3) 36", "4) 48"},
        {"1) 2", "2) 3", "3) 4", "4) 5"},
        {"1) 6", "2) 8", "3) 9", "4) 12"}
    };
    int a[] = {2, 1, 3, 2, 3, 3, 1, 1, 3, 3};  // Q9 corrected (9 - 5 = 4 => option 3)
int i;
    for ( i = 0; i < QUESTIONS_PER_LEVEL; i++) {
        strcpy(t->questions[i].question, q[i]);
        int j;
        for (j = 0; j < 4; j++) strcpy(t->questions[i].options[j], opts[i][j]);
        t->questions[i].correctOption = a[i];
    }
}

// Play a quiz topic
int runLevel(Topic *t) {
    int score = 0, ans;
    printf(BLUE "\n-- Quiz: %s --\n" RESET, t->topicName);
    int i;
    for ( i = 0; i < QUESTIONS_PER_LEVEL; i++) {
        Question q = t->questions[i];
        printf(CYAN "\nQ%d: %s\n" RESET, i + 1, q.question);
        int j;
        for (j = 0; j < 4; j++) printf("%s\n", q.options[j]);
        printf("Enter your answer (1-4): ");
        scanf("%d", &ans);
        if (ans == q.correctOption) {
            printf(GREEN "Correct!\n" RESET);
            score++;
        } else {
            printf(RED "Wrong! Correct answer: %s\n" RESET, q.options[q.correctOption - 1]);
        }
    }
    printf(YELLOW "\nYour Final Score in %s: %d/%d\n" RESET, t->topicName, score, QUESTIONS_PER_LEVEL);
    return score;
}

// Main Menu
int main() {
    char name[50];
    int choice;

    printf(CYAN "Enter your name: " RESET);
    scanf("%s", name);
    getchar();

    fillGK(&gk);
    fillScience(&sci);
    fillMath(&math);

    printf(GREEN "\nWelcome %s to the Quiz Game!\n" RESET, name);

    do {
        printf(YELLOW "\nChoose a topic:\n" RESET);
        printf("1. General Knowledge\n2. Science\n3. Mathematics\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: runLevel(&gk); break;
            case 2: runLevel(&sci); break;
            case 3: runLevel(&math); break;
            case 4: printf(GREEN "\nThank you for playing, %s! Goodbye!\n" RESET, name); break;
            default: printf(RED "Invalid choice. Please enter 1–4.\n" RESET);
        }
    } while (choice != 4);

    return 0;
}


