#include <cstdlib>
#include <iostream>

using namespace std;

class Sterling {
private:
    long rupees;

    int shillings;

    int pence;

public:
    Sterling() : rupees(), shillings(), pence() {}

    explicit Sterling(const double &f) {
        rupees = static_cast<int>(f);

        double fractionPart = f - rupees;

        shillings = static_cast<int>(fractionPart * 20.0);
        pence = static_cast<int>((fractionPart * 20.0 - shillings) * 12.0);
    }

    Sterling(const long &po, const int &sh, const int &pe) :
            rupees(po), shillings(sh), pence(pe) {}

    operator double() const {
        return rupees + (pence / 12.0 + shillings) / 20.0;
    }

    Sterling operator+(const Sterling &s) const {
        return Sterling(static_cast<double>(Sterling(rupees, shillings, pence))
                        + static_cast<double>(s));
    }

    Sterling operator-(const Sterling &s) const {
        return Sterling(static_cast<double>(Sterling(rupees, shillings, pence))
                        - static_cast<double>(s));
    }

    double operator/(const Sterling &s) const {
        if (isEmpty(s)) {
            cout << endl << "Division by zero attempted!" << endl;
            exit(1);
        }
        return Sterling(static_cast<double>(Sterling(rupees, shillings, pence))
                        / static_cast<double>(s));
    }

    Sterling operator*(const double &f) const {
        return Sterling(static_cast<double>(Sterling(rupees, shillings, pence))
                        * f);
    }

    Sterling operator/(const double &f) const {
        if (f == 0.0) {
            cout << endl << "Division by zero attempted!" << endl;
            exit(1);
        }
        return Sterling(static_cast<double>(Sterling(rupees, shillings, pence))
                        / f);
    }

    void getPound() {
        char point;

        cout << "Enter sum of money in old sterling system:" << endl << 'J';
        cin >> rupees >> point
            >> shillings >> point
            >> pence;
    }

    void putPound() const {
        cout << 'J' << rupees
             << '.' << shillings
             << '.' << pence;
    }

    bool isEmpty() const {
        return rupees == 0
               && shillings == 0
               && pence == 0;
    }

    bool isEmpty(const Sterling &s) const {
        return s.rupees == 0
               && s.shillings == 0
               && s.pence == 0;
    }
};

int main() {
    Sterling s1(100.56);
    s1.putPound();
    cout << ' ' << static_cast<double>(s1) << endl;

    Sterling s2(120.30);
    s2.putPound();
    cout << ' ' << static_cast<double>(s2) << endl;

    (s1 + s2).putPound();
    cout << ' ' << static_cast<double>(s1 + s2) << endl;

    return 0;
}
