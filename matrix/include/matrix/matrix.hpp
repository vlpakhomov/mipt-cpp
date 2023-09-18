#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

template <std::size_t N, std::size_t M, typename T, typename D>
class MatrixBase {
  public:
    MatrixBase() = default;
    MatrixBase(MatrixBase<N, M, T, D> const& mat) = default; 
    ~MatrixBase() = default;

    void Swap(D& mat);
    D& operator=(D const& mat);

    /*explicit*/ MatrixBase(std::vector<std::vector<T>> const& arr);
    
    /*explicit*/ MatrixBase(T const& elem);

    D& operator+=(D const& mat);
    D& operator-=(D const& mat);

    D& operator*=(T const& elem);

    T& operator()(std::size_t i, std::size_t j);
    T const& operator()(std::size_t i, std::size_t j) const;
   
    std::size_t GetRow() const;
    std::size_t GetCol() const;
  protected:
    std::vector<std::vector<T>> arr = std::vector<std::vector<T>>(N, std::vector<T>(M));
    std::size_t row = N;
    std::size_t col = M;
};

template <std::size_t N, std::size_t M, typename T = int64_t>
class Matrix: public MatrixBase<N, M, T, Matrix<N, M, T>>
{
    using MatrixBase<N, M, T, Matrix>::MatrixBase;

  public:
    Matrix<M, N, T> Transposed() const;

};

template <std::size_t N, typename T>
class Matrix<N, N, T>: public MatrixBase<N, N, T, Matrix<N, N, T>>
{
    using MatrixBase<N, N, T, Matrix<N, N, T>>::MatrixBase;
  public:
    Matrix<N, N, T> Transposed() const;

    T Trace() const;
};

template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator+(Matrix<N, M, T> const& mat1, 
    Matrix<N, M, T> const& mat2);
template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator-(Matrix<N, M, T> const& mat1,
    Matrix<N, M, T> const& mat2);

template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator*(Matrix<N, M, T> const& mat, T const& elem);
template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator*(T const& elem, Matrix<N, M, T> const& mat);

template <std::size_t N, std::size_t M, std::size_t K, typename T>
Matrix<N, K, T> operator*(Matrix<N, M, T> const& mat1, 
    Matrix<M, K, T> const& mat2);

template <std::size_t N, std::size_t M, typename T>
bool operator==(Matrix<N, M, T> const& mat1, Matrix<N, M, T> const& mat2);

#include "../../src/matrix.ipp"
