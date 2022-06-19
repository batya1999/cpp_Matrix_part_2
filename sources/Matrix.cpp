#include <iostream>
#include <fstream>
#include "Matrix.hpp"
using namespace std;
// using namespace zich;
namespace zich {

    //need to add constructors

    ostream& operator<<(ostream& out, const Matrix& a) {
        int k = 0;
        for (int i = 0; i < a.row; i++)
        {
            out << "[";
            for (int j = 0; j < a.column; j++)
            {
                out << a.vector[static_cast<std::vector<int>::size_type>(k)];
                if (j + 1 != a.column) {
                    out << " ";
                }
                k++;
            }
            out << "]";
            if (i + 1 != a.row) {
                out << endl;
            }
        }
        return out;
    }
    istream& operator>>(istream& in, Matrix& a) {
        while(true)
        {
            if (in.peek() != '[') {
                throw("Invalid");
            }
            in.get();
            while(true)
            {
                a.vector.push_back(in.get());
                if (in.peek() == ' ') {
                    in.get();
                }
                else if (in.peek() == ']') {
                    in.get();
                    break;
                }
                else {
                    throw("Invalid");
                }
            }
            if (in.peek() == '\n') {
                in.get();
                break;
            }
            else {
                if (in.peek() != ',') {
                    throw("Invalid");
                }
                in.get();
                if (in.peek() != ' ') {
                    throw("Invalid");
                }
                in.get();
            }
        }
        return in;
    }
    Matrix operator+(const Matrix& a, const Matrix& b) {
        vector<double> vector;
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] + b.vector[static_cast<std::vector<int>::size_type>(k)]);
                    k++;
                }
            }
        }
        else {
            throw("Invalid Addition");
        }
        Matrix temp(vector, a.row, a.column);
        return temp;
    }
    Matrix operator+(const Matrix& a, double b) {
        vector<double> vector;
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] + b);
                k++;
            }
        }
        Matrix temp(vector, a.row, a.column);
        return temp;
    }
    Matrix operator+(Matrix& a) {
        return a;
    }
    Matrix operator-(Matrix& a) {
        return a*(-1);
    }
    Matrix operator+=(Matrix& a, const Matrix& b) {
        vector<double> vector;
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] + b.vector[static_cast<std::vector<int>::size_type>(k)]);
                    k++;
                }
            }
        }
        else {
            throw("Invalid Addition");
        }
        Matrix temp(vector, a.row, a.column);
        a = temp;
        return temp;
    }
    Matrix operator-(const Matrix& a, const Matrix& b) {
        vector<double> vector;
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] - b.vector[static_cast<std::vector<int>::size_type>(k)]);
                    k++;
                }
            }
        }
        else {
            throw("Invalid Subtraction");
        }
        Matrix temp(vector, a.row, a.column);
        return temp;
    }
    Matrix operator-(const Matrix& a, double b) {
        vector<double> vector;
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] - b);
                k++;
            }
        }
        Matrix temp(vector, a.row, a.column);
        return temp;
    }
    Matrix operator-=(Matrix& a, const Matrix& b) {
        vector<double> vector;
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] - b.vector[static_cast<std::vector<int>::size_type>(k)]);
                    k++;
                }
            }
        }
        else {
            throw("Invalid Subtraction");
        }
        Matrix temp(vector, a.row, a.column);
        a = temp;
        return temp;
    }
    Matrix operator++(Matrix& a) {
        int  k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                a.vector[static_cast<std::vector<int>::size_type>(k)] = (a.vector[static_cast<std::vector<int>::size_type>(k)] + 1);
                k++;
            }
        }
        return a;
    }
    Matrix operator++(Matrix& a, int) {
        Matrix temp(a);
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                a.vector[static_cast<std::vector<int>::size_type>(k)] = (a.vector[static_cast<std::vector<int>::size_type>(k)] + 1);
                k++;
            }
        }
        return temp;
    }
    Matrix operator--(Matrix& a) {
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                a.vector[static_cast<std::vector<int>::size_type>(k)] = (a.vector[static_cast<std::vector<int>::size_type>(k)] - 1);
                k++;
            }
        }
        return a;
    }
    Matrix operator--(Matrix& a, int) {
        Matrix temp(a);
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                a.vector[static_cast<std::vector<int>::size_type>(k)] = (a.vector[static_cast<std::vector<int>::size_type>(k)] - 1);
                k++;
            }
        }
        return temp;
    }
    Matrix operator*(Matrix& a, double b) {
        vector<double> vector;
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] * b);
                k++;
            }
        }
        Matrix temp(vector, a.row, a.column);
        return temp;
    }
    Matrix operator*(Matrix& a, Matrix& b) {
        vector<vector<double>> vector;
        std::vector<std::vector<double>> avector;
        std::vector<std::vector<double>> bvector;
        std::vector<double> vtr;
        int k = 0;
        for (int i = 0; i < a.row;i++) {
            std::vector<double> inner;
            for (int j = 0;j < a.column;j++) {
                inner.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)]);
                k++;
            }
            avector.push_back(inner);
        }
        k = 0;
        for (int i = 0; i < b.row;i++) {
            std::vector<double> inner;
            for (int j = 0;j < b.column;j++) {
                inner.push_back(b.vector[static_cast<std::vector<int>::size_type>(k)]);
                k++;
            }
            bvector.push_back(inner);
        }
        if (a.column == b.row) {
            for (int i = 0; i < a.row; i++) {
                std::vector<double> inner;
                for (int j = 0; j < b.column;j++) {
                    double sum = 0;
                    for (int l = 0; l < a.column; l++) {
                        sum = sum + (avector[static_cast<std::vector<int>::size_type>(i)][static_cast<std::vector<int>::size_type>(l)] * bvector[static_cast<std::vector<int>::size_type>(l)][static_cast<std::vector<int>::size_type>(j)]);
                    }
                    inner.push_back(sum);
                }
                vector.push_back(inner);
            }
            for (int i = 0; i < vector.size();i++) {
                for (int j = 0; j < vector.at(static_cast<std::vector<int>::size_type>(0)).size();j++) {
                    vtr.push_back(vector[static_cast<std::vector<int>::size_type>(i)][static_cast<std::vector<int>::size_type>(j)]);
                }
            }
        }
        else {
            throw("Invalid Multiplication");
        }
        Matrix temp(vtr, a.row, b.column);
        return temp;
    }
    Matrix operator*=(Matrix& a, Matrix& b) {
        vector<vector<double>> vector;
        std::vector<std::vector<double>> avector;
        std::vector<std::vector<double>> bvector;
        std::vector<double> vtr;
        int k = 0;
        for (int i = 0; i < a.row;i++) {
            std::vector<double> inner;
            for (int j = 0;j < a.column;j++) {
                inner.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)]);
                k++;
            }
            avector.push_back(inner);
        }
        k = 0;
        for (int i = 0; i < b.row;i++) {
            std::vector<double> inner;
            for (int j = 0;j < b.column;j++) {
                inner.push_back(b.vector[static_cast<std::vector<int>::size_type>(k)]);
                k++;
            }
            bvector.push_back(inner);
        }
        if (a.column == b.row) {
            for (int i = 0; i < a.row; i++) {
                std::vector<double> inner;
                for (int j = 0; j < b.column;j++) {
                    double sum = 0;
                    for (int k = 0; k < a.column; k++) {
                        sum = sum + (avector[static_cast<std::vector<int>::size_type>(i)][static_cast<std::vector<int>::size_type>(k)] * bvector[static_cast<std::vector<int>::size_type>(k)][static_cast<std::vector<int>::size_type>(j)]);
                    }
                    inner.push_back(sum);
                }
                vector.push_back(inner);
            }
            for (int i = 0; i < vector.size();i++) {
                for (int j = 0; j < vector.at(static_cast<std::vector<int>::size_type>(0)).size();j++) {
                    vtr.push_back(vector[static_cast<std::vector<int>::size_type>(i)][static_cast<std::vector<int>::size_type>(j)]);
                }
            }
        }
        else {
            throw("Invalid Multiplication");
        }
        Matrix temp(vtr, a.row, b.column);
        a = temp;
        return temp;
    }
    Matrix operator*(double a, Matrix& b) {
        vector<double> vector;
        int k = 0;
        for (int i = 0; i < b.row; i++) {
            for (int j = 0; j < b.column; j++) {
                vector.push_back(b.vector[static_cast<std::vector<int>::size_type>(k)] * a);
                k++;
            }
        }
        Matrix temp(vector, b.row, b.column);
        return temp;
    }
    Matrix operator*=(Matrix& a, double b) {
        vector<double> vector;
        int k = 0;
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.column; j++) {
                vector.push_back(a.vector[static_cast<std::vector<int>::size_type>(k)] * b);
                k++;
            }
        }
        Matrix temp(vector, a.row, a.column);
        a = temp;
        return temp;
    }
    Matrix operator*=(double a, Matrix& b) {
        vector<double> vector;
        int k = 0;
        for (int i = 0; i < b.row; i++) {
            for (int j = 0; j < b.column; j++) {
                vector.push_back(b.vector[static_cast<std::vector<int>::size_type>(k)] * a);
                k++;
            }
        }
        Matrix temp(vector, b.row, b.column);
        b = temp;
        return temp;
    }
    bool operator>(const Matrix& a, const Matrix& b) {
        bool flag = true;
        bool equal = false;
        if (a.row != b.row || a.column != b.column) {
            throw("Comparison not possible");
        }
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    if (a.vector[static_cast<std::vector<int>::size_type>(k)] < b.vector[static_cast<std::vector<int>::size_type>(k)]) {
                        flag = false;
                    }
                    if (a.vector[static_cast<std::vector<int>::size_type>(k)] != b.vector[static_cast<std::vector<int>::size_type>(k)]) {
                        equal = true;
                    }
                    k++;
                }
            }
            return flag && equal;
        }
        else {
            return false;
        }
    }
    bool operator>=(const Matrix& a, const Matrix& b) {
        return a > b || a == b;
    }
    bool operator<(const Matrix& a, const Matrix& b) {
        bool flag = true;
        bool equal = false;
        if (a.row != b.row || a.column != b.column) {
            throw("Comparison not possible");
        }
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    if (a.vector[static_cast<std::vector<int>::size_type>(k)] > b.vector[static_cast<std::vector<int>::size_type>(k)]) {
                        flag = false;
                    }
                    if (a.vector[static_cast<std::vector<int>::size_type>(k)] != b.vector[static_cast<std::vector<int>::size_type>(k)]) {
                        equal = true;
                    }
                    k++;
                }
            }
            return flag && equal;
        }
        else {
            return false;
        }
    }
    bool operator<=(const Matrix& a, const Matrix& b) {
        return a < b || a == b;
    }
    bool operator==(const Matrix& a, const Matrix& b) {
        if (a.row != b.row || a.column != b.column) {
            throw("Comparison not possible");
        }
        if (a.row == b.row && a.column == b.column) {
            int k = 0;
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < a.column; j++) {
                    if (a.vector[static_cast<std::vector<int>::size_type>(k)] != b.vector[static_cast<std::vector<int>::size_type>(k)]) {
                        return false;
                    }
                    k++;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
    bool operator!=(const Matrix& a, const Matrix& b) {
        return !(a == b);
    }
}