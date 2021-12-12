#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// problem 1
struct position {
    int x;
    int y;
};

// problem 1
void forward(position *pos, int d) {
    pos->x += d;
}

void down(position *pos, int d) {
    pos->y += d;
}

void problem_1(){

    ifstream file;
    file.open("input_1.txt", ios::in);

    if (file.is_open()) {
        char direction[50];
        char distance[50];
        int d = 0;
        position *pos;
        pos = new position;
        pos->x = 0;
        pos->y = 0;
        while (file >> direction && file >> distance){
            d = atoi(distance);
            if(strcmp(direction, "forward") == 0){
                forward(pos, d);
            } else if (strcmp(direction, "down") == 0){
                down(pos, d);
            } else {
               down(pos, d*-1);
            }
        }
        cout << "x: " << pos->x << "  y: " << pos->y << '\n';
        cout << "Result: " << pos->x * pos->y << '\n';

    } else {
        cout << "Could not open file.\n";
    }
}

// problem 2
struct pos_aim {
    int x;
    int y;
    int aim;
};

void go_forward(pos_aim *pos, int d) {
    pos->x += d;
    pos->y += pos->aim * d;
}

void aim_down(pos_aim *pos, int d) {
    pos->aim += d;
}
void problem_2() {
    ifstream file;
    file.open("input_1.txt", ios::in);

    if (file.is_open()) {
        char direction[50];
        char distance[50];
        int d = 0;
        pos_aim *pos;
        pos = new pos_aim;
        pos->x = 0;
        pos->y = 0;
        pos->aim = 0;
        while (file >> direction && file >> distance){
            d = atoi(distance);
            if(strcmp(direction, "forward") == 0){
                go_forward(pos, d);
            } else if (strcmp(direction, "down") == 0){
                aim_down(pos, d);
            } else {
               aim_down(pos, d*-1);
            }
        }
        cout << "x: " << pos->x << "  y: " << pos->y << "  aim: " << pos->aim <<  '\n';
        cout << "Result: " << pos->x * pos->y << '\n';

    } else {
        cout << "Could not open file.\n";
    }

}

int main(int argc, char *argv[]) {
    cout << "Problem 1: \n";
    problem_1();
    cout << "Problem 2: \n";
    problem_2();

    return 0;
}
