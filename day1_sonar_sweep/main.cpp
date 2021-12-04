#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream file;
    file.open("input.txt", ios::in);

    if (file.is_open()) {
        int depth_count = 0;
        int prev_dep = -1;
        int cur_dep = 0;
        char input[100];
        while (file >> input){
            cur_dep = atoi(input);
            if (cur_dep > prev_dep && prev_dep != -1) depth_count++;
            prev_dep = cur_dep;
        }

        cout << depth_count << '\n';
    } else {
        cout << "Could not open file.\n";
    }


    return 0;
}
