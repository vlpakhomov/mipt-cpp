#pragma once
#include "../include/matrix/matrix.hpp"

template <std::size_t N, std::size_t M, typename T, typename D>
void MatrixBase<N, M, T, D>::Swap(D& mat) {
  std::swap(arr, mat.arr);
  std::swap(col, mat.col);
  std::swap(row, mat.row);
}
template <std::size_t N, std::size_t M, typename T, typename D>
D& MatrixBase<N, M, T, D>::operator=(D const& mat) {
  MatrixBase<N, M, T, D> copy = mat;
  Swap(copy);
  return static_cast<D&>(this);
}

template <std::size_t N, std::size_t M, typename T, typename D>
MatrixBase<N, M, T, D>::MatrixBase(std::vector<std::vector<T>> const& arr): arr(arr) {}

template <std::size_t N, std::size_t M, typename T, typename D>
MatrixBase<N, M, T, D>::MatrixBase(T const& elem): 
  arr(std::vector<std::vector<T>>(N, std::vector<T>(M, elem))) {}

template <std::size_t N, std::size_t M, typename T, typename D>
D& MatrixBase<N, M, T, D>::operator+=(D const& mat) {
  for (std::size_t i = 0; i < row; ++i) {
    for (std::size_t j = 0; j < col; ++j) {
      arr[i][j] += mat.arr[i][j];
    }
  }

  return static_cast<D&>(*this);
}
template <std::size_t N, std::size_t M, typename T, typename D>
D& MatrixBase<N, M, T, D>::operator-=(D const& mat) {
  for (std::size_t i = 0; i < row; ++i) {
    for (std::size_t j = 0; j < col; ++j) {
      arr[i][j] -= mat.arr[i][j];
    }
  }

  return static_cast<D&>(*this);
}

template <std::size_t N, std::size_t M, typename T, typename D> 
D& MatrixBase<N, M, T, D>::operator*=(T const& elem) {
  for (std::size_t i = 0; i < row; ++i) {
    for (std::size_t j = 0; j < col; ++j) {
      arr[i][j] *= elem;
    }
  }

  return static_cast<D&>(*this); 
}

template <std::size_t N, std::size_t M, typename T>
Matrix<M, N, T> Matrix<N, M, T>::Transposed() const {
  Matrix<M, N, T> copy;
  for (std::size_t i = 0; i < this->col; ++i) {
    for (std::size_t j = 0; j < this->row; ++j) {
      copy(i, j) = (this->arr)[j][i];
    }
  }

  return copy;
}

template <std::size_t N, typename T>
Matrix<N, N, T> Matrix<N, N, T>::Transposed() const { return (*this); }

template <std::size_t N, std::size_t M, typename T, typename D>
T& MatrixBase<N, M, T, D>::operator()(std::size_t i, std::size_t j) { return arr[i][j]; }
template <std::size_t N, std::size_t M, typename T, typename D>
T const& MatrixBase<N, M, T, D>::operator()(std::size_t i, std::size_t j) const { 
  return arr[i][j]; 
}

template <std::size_t N, std::size_t M, typename T, typename D>
std::size_t MatrixBase<N, M, T, D>::GetRow() const { return row; }
template <std::size_t N, std::size_t M, typename T, typename D>
std::size_t MatrixBase<N, M, T, D>::GetCol() const { return col; }

template <std::size_t N, typename T>
T Matrix<N, N, T>::Trace() const {
  T tmp = 0;
  for (std::size_t i = 0; i < this->row; ++i) { tmp += (this->arr)[i][i]; }
  return tmp;
}

template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator+(Matrix<N, M, T> const& mat1, 
    Matrix<N, M, T> const& mat2) {
  Matrix<N, M, T> copy = mat1;
  copy += mat2;
  return copy;
}
template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator-(Matrix<N, M, T> const& mat1, 
    Matrix<N, M, T> const& mat2) {
  Matrix<N, M, T> copy = mat1;
  copy -= mat2;
  return copy;
}

template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator*(Matrix<N, M, T> const& mat, T const& elem) {
  Matrix<N, M, T> copy = mat;
  copy *= elem;
  return copy;
}
template <std::size_t N, std::size_t M, typename T>
Matrix<N, M, T> operator*(T const& elem, Matrix<N, M, T> const& mat) {
  return mat * elem;
}

template <std::size_t N, std::size_t M, std::size_t K, typename T>
Matrix<N, K, T> operator*(Matrix<N, M, T> const& mat1, 
    Matrix<M, K, T> const& mat2) {
  Matrix<N, K, T> res;
  for (std::size_t i = 0; i < res.GetRow(); ++i) {
    for (std::size_t j = 0; j < res.GetCol(); ++j) {
      for (std::size_t k = 0; k < mat1.GetCol(); ++k) {
        res(i, j) += mat1(i, k) * mat2(k, j);
      }
    }
  }

  return res;
}


template <std::size_t N, std::size_t M, typename T>
bool operator==(Matrix<N, M, T> const& mat1, Matrix<N, M, T> const& mat2) {
  return (mat1.arr == mat2.arr);
}

