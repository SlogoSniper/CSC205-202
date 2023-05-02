#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

vector<int> random_vector(int n, int upper_bound)
{
    vector<int> vec(n);

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % upper_bound;
    }

    return vec;
}

int how_many(const vector<int>& vec, int value)
{
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) count++;
    }
    return count;
}

int main() {
    int num_values = 100;
    int upper_bound = 10;
    srand((unsigned) time(NULL));
    vector<int> vector = random_vector(num_values, upper_bound);
    cout << "value\thow_many" << endl;
    for (int i = 0; i < upper_bound; i++) {
        cout << i << '\t' << how_many(vector, i) << endl;
    }
}

// Increasing num_values ends up increasing the output value of how_many. Srand makes the numbers that appear different on every run of the program.