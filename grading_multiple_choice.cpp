#include <iostream>

int main() {
    const int NUM_STUDENTS = 8;
    const int NUM_QUESTIONS = 10;

    char answers[NUM_STUDENTS][NUM_QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    char keys[NUM_QUESTIONS] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int correctCount = 0;
        for (int j = 0; j < NUM_QUESTIONS; ++j) {
            if (answers[i][j] == keys[j]) {
                correctCount++;
            }
        }
        std::cout << "Student " << i << "'s correct count is " << correctCount << std::endl;
    }

    return 0;
}