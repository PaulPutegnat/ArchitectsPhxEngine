#pragma once
#include <A4Engine/Export.hpp>
#include <A4Engine/Vector2.inl>
#include <iostream>
#include <vector>

class A4ENGINE_API Matrix3 {
	/*private:
		int NbLines;
		int NbColumns;
		std::vector<std::vector<float>> Mat;*/

	public:
		int NbLines;
		int NbColumns;
		std::vector<std::vector<float>> matSize;

		Matrix3();
		Matrix3(int x, int y);
		void Add(float i);
		void Add(Matrix3 mat2);
		void Multiply(float i);
		void Multiply(Matrix3 mat2);
		Matrix3 Transpose();

		static Matrix3 Add(Matrix3 mat, float i);
		static Matrix3 Add(Matrix3 mat, Matrix3 mat2);
		static Matrix3 Substract(Matrix3 mat, float i);
		static Matrix3 Substract(Matrix3 mat, Matrix3 mat2);
		static Matrix3 Multiply(Matrix3 mat, float i);
		static Matrix3 Multiply(Matrix3 mat, Matrix3 mat2);

		Matrix3 operator+(const Matrix3& mat) const;
		Matrix3 operator-(const Matrix3& mat) const;
		Matrix3 operator*(const Matrix3& mat) const;
		Matrix3 operator*(float value) const;
		Vector2f operator*(const Vector2f& vector) const;

		Matrix3& operator=(const Matrix3& mat);
		Matrix3& operator+=(const Matrix3& mat);
		Matrix3& operator*=(const Matrix3& mat);
		Matrix3& operator*=(float value);
};