#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

void problem_1(){
    ifstream file;
    file.open("input_1.txt", ios::in);

    if (file.is_open()) {
        char input[20];
        int rates[20] = {0};
        int count = 0;
        int i;
        while (file >> input){
            for(i = 0; input[i] != '\0'; ++i){
                rates[i] += (int)input[i] - 48;
            }
            count++;
        }

        int gamma = 0;
        int epsilon = 0;
        for (int j = 1; j <= i; ++j){
            if (rates[j-1] >= count/2){
                gamma += pow(2, i-j);
            } else {
                epsilon += pow(2, i-j);
            }
        }
        cout << "gamma: " << gamma << "  epsilon: " << epsilon << '\n';
        cout << gamma*epsilon << '\n';

    } else {
        cout << "Could not open file.\n";
    }

}

int main(int argc, char *argv[]) {
    problem_1();

    return 0;
}
