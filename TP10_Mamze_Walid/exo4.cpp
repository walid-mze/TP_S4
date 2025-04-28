#include <iostream>
#include <array>
#include <cassert>

template<typename T, std::size_t M, std::size_t N>
class Matrix;

template<typename T, std::size_t M1, std::size_t N1, std::size_t M2, std::size_t N2>
struct MatrixAdder {
    static Matrix<T, M1, N1> add(const Matrix<T, M1, N1>& a, const Matrix<T, M2, N2>& b) {
        static_assert(M1 == M2 && N1 == N2, "Matrix dimensions must match for addition.");
        Matrix<T, M1, N1> result;
        for (std::size_t i = 0; i < M1; ++i) {
            for (std::size_t j = 0; j < N1; ++j) {
                result.set(i, j, a.get(i, j) + b.get(i, j));
            }
        }
        return result;
    }
};

template<typename T, std::size_t M, std::size_t N>
class Matrix {
private:
    std::array<T, M * N> data{};
public:
    void set(std::size_t i, std::size_t j, const T& value) {
        assert(i < M && j < N);
        data[i * N + j] = value;
    }

    T get(std::size_t i, std::size_t j) const {
        assert(i < M && j < N);
        return data[i * N + j];
    }

    template<std::size_t M2, std::size_t N2>
    auto add(const Matrix<T, M2, N2>& other) const {
        return MatrixAdder<T, M, N, M2, N2>::add(*this, other);
    }
};

int main() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);

    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);

    auto m3 = m1.add(m2);

    std::cout << m3.get(0, 0) << " " << m3.get(0, 1) << std::endl; // 6 8
    std::cout << m3.get(1, 0) << " " << m3.get(1, 1) << std::endl; // 10 12

    Matrix<int, 2, 3> m4;

    return 0;
}
