#include <string>
#include <iostream>
#include <vector>
#include <ostream>

struct Book {
    std::string author;
    std::string title;
    unsigned int year;
};

void PrintBook(Book book) {
    std::cout << book.author << " " << book.title << " " << book.year << std::endl;
}

class Student {
public:
    Student(std::string name, int age, int grade): name_(name), age_(age), grade_(grade)  {}

    int AddGrade(int value) {
        return grade_ += value;
    }

    std::string GetName() const {
        return name_;
    }

    int GetAge() const {
      return age_;
    }
private:
    std::string name_;
    int age_;
    int grade_;
};

class Matrix {
public:
    Matrix(std::vector<int> m): matrix_(m) {}

    Matrix operator+(Matrix rhs) const {
        std::vector<int> res;
        for (int i = 0; i < matrix_.size(); i++) {
          res.push_back(matrix_[i] + rhs.matrix_[i]);
        }
        return Matrix(res);
    };

    Matrix operator*(Matrix rhs) const {
        std::vector<int> res;
        for (int i = 0; i < matrix_.size(); i++) {
            res.push_back(matrix_[i] * rhs.matrix_[i]);
        }
        return Matrix(res);
    };

    friend std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
        for (int i = 0; i < matrix.matrix_.size(); i++) {
            std::cout << matrix.matrix_[i] << "\n";
        }

        return os;
    };
private:
    std::vector<int> matrix_;
};

int main() {
    Book book = {.author = "John Wedn", .title = "The Book", .year = 2021};
    PrintBook(book);

    Student student("John Wedn", 22, 200);
    student.AddGrade(1001);

    Matrix matrix({8, 4, 5, 9});
    Matrix matrix2({2, 6, 5, 1});

    Matrix matrix3 = matrix * matrix2;

    std::cout << matrix3 << std::endl;
}