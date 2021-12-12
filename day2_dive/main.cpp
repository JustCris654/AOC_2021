#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct position {
    int x;
    int y;
};

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

int main(int argc, char *argv[]) {
    problem_1();

    return 0;
}
