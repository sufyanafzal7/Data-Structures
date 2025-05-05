#include <iostream>
using namespace std;

int iterativeMultiplication(int a, int b) {

    int result = 0;
    for (int i = 1; i <= b; i++)
        result += a;
    return result;

}

int main() {

    int a, b;
    cout << "Brather Enter two positive integers: ";
    cin >> a >> b;

    int product = iterativeMultiplication(a, b);
    cout << "The product of " << a << " and " << b << " is: " << product << endl;

    return 0;
    
}
