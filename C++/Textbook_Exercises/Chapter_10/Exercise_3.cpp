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

vector<int> histogram(vector<int> myvector, int upper_bound) {
    vector<int> histogram(upper_bound, 0);

    for (int i = 0; i < 100; i++) {
        int index = myvector[i];
        histogram[index]++;
    }
    return histogram;
}

int main() {
    int i = 0;
    int upper_bound = 20;
    int num_values = 20;
    srand((unsigned) time(NULL));
    vector<int> myvector = random_vector(num_values, upper_bound);
    vector<int> my_histogram = histogram(myvector, upper_bound);
    for (i=0;i<num_values;i++) {
        cout << my_histogram[i] << endl;
    }
    return 0;
}