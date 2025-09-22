#include <iostream>
#include <vector>
using namespace std;

class mysize {
private:
    int len;

public:
    mysize() : len(0) {}

    mysize(const int leng) {
        len = leng;
    }

    mysize(const mysize& length) {
        len = length.len;
    }

    friend ostream& operator<<(ostream& os, const mysize& s) {
        os << s.len;
        return os;
    }
};

int main() {
    int n = 71;

    // Single prime check
    bool prime = true;
    if (n <= 1) {
        cout << "Enter a number greater than 1." << endl;
    } else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            cout << "Prime" << endl;
        else
            cout << "Not prime" << endl;
    }

    // Prime list generation
    int countprimes = 0;
    vector<int> primes;

    for (int i = 2; i < n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            countprimes++;
            primes.push_back(i);
        }
    }

    cout << "Number of prime elements: " << primes.size() << endl;
    cout << "Total primes: " << countprimes << endl;
    cout << "Primes: ";
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;

    // Test mysize class
    mysize s1;
    mysize s2 = 34;
    mysize s3 = s2;
    cout << "mysize s3: " << s3 << endl;

    return 0;
}
