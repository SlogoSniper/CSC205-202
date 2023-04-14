// Yes, you can have a function that yields a value
#include <iostream>
using namespace std;
#include <math.h>


int myFunction(int x) {
  return 5 + x;
}

int main() {
  cout << myFunction(3);
  return 0;
}

