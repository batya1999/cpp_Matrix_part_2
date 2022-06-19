#include <vector>
#include <iostream>
using namespace std;

namespace zich {
    class Matrix {
    private:
        std::vector<double> vector;
        int row;
        int column;

    public:
        Matrix() {
            vector = {};
            row = 0;
            column = 0;
        }
        Matrix(std::vector<double> vector, int row, int column) {
            if (row * column != vector.size() || row <= 0 || column <= 0) {
                throw("Invalid");
            }
            this->vector = vector;
            this->row = row;
            this->column = column;
        }
        Matrix(const Matrix& rhs) {
            row = rhs.row;
            column = rhs.column;
            /*for (int i = 0; i < rhs.vector.size();i++) {
                vector.push_back(rhs.vector.at(i));
            }*/
            vector = rhs.vector;
        }
        Matrix operator=(const Matrix& rhs) {
            vector.clear();
            row = rhs.row;
            column = rhs.column;
            /*for (int i = 0; i < rhs.vector.size();i++) {
                vector.push_back(rhs.vector.at(i));
            }*/
            vector = rhs.vector;
            return *this;
        }
        friend Matrix operator+(const Matrix& a, const Matrix& b);
        friend Matrix operator+(const Matrix& a, double b);
        friend Matrix operator+(Matrix& a);
        friend Matrix operator+=(Matrix& a, const Matrix& b);
        friend Matrix operator-(const Matrix& a, const Matrix& b);
        friend Matrix operator-(const Matrix& a, double b);
        friend Matrix operator-(Matrix& a);
        friend Matrix operator-=(Matrix& a, const Matrix& b);
        friend Matrix operator++(Matrix& a);
        friend Matrix operator++(Matrix& a, int);
        friend Matrix operator--(Matrix& a);
        friend Matrix operator--(Matrix& a, int);
        friend Matrix operator*(Matrix& a, double b);
        friend Matrix operator*(Matrix& a, Matrix& b);
        friend Matrix operator*=(Matrix& a, Matrix& b);
        friend Matrix operator*(double a, Matrix& b);
        friend Matrix operator*=(Matrix& a, double b);
        friend Matrix operator*=(double a, Matrix& b);
        friend bool operator>(const Matrix& a, const Matrix& b);
        friend bool operator>=(const Matrix& a, const Matrix& b);
        friend bool operator<(const Matrix& a, const Matrix& b);
        friend bool operator<=(const Matrix& a, const Matrix& b);
        friend bool operator==(const Matrix& a, const Matrix& b);
        friend bool operator!=(const Matrix& a, const Matrix& b);
        friend ostream& operator<<(ostream& out, const Matrix& a);
        friend istream& operator>>(istream& in, Matrix& a);
    };
}