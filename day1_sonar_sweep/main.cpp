#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void problem_1() {
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
}

void problem_2() {
    ifstream file;
    file.open("input_2.txt", ios::in);


    if (file.is_open()) {
        int count = std::count(std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>(), '\n');
        file.clear();
        file.seekg(0);

        char input[20];
        int cur_dep = -1;
        int index = 0;
        int arr[count];
        while (file >> input){
            cur_dep = atoi(input);
            arr[index] = cur_dep;
            index ++;
        }

        int sum = -1;
        int prev_sum = -1;
        int inc_count = 0;
        for (int i = 0; i < index - 2; ++i){
            sum = 0;
            for (int j = 0; j < 3; ++j){
                sum += arr[i+j];
            }
            if (prev_sum != -1 && prev_sum < sum){
                inc_count++;
            }
            prev_sum = sum;
        }

        cout << inc_count << '\n';



    } else {
        cout << "Could not open file.\n";
    }
}

int main(int argc, char** argv){
    // problem_1();
    problem_2();
    return 0;
}
