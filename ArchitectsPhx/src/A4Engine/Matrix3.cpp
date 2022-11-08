#include <A4Engine/Matrix3.hpp>

Matrix3::Matrix3()
{
	NbLines = 3;
	NbColumns = 3;
	matSize = std::vector<std::vector<float>>(NbLines, std::vector<float>(NbColumns));

	for (int i = 0; i < matSize.size(); i++) {
		for (int j = 0; j < matSize[i].size(); j++)
			std::cout << matSize[i][j] << " ";
		std::cout << std::endl;
	}
}

Matrix3::Matrix3(int x, int y)
{
	NbLines = x;
	NbColumns = y;
	matSize = std::vector<std::vector<float>>(NbLines, std::vector<float>(NbColumns));
}

void Matrix3::Add(float i)
{
	for (int x = 0; x < NbLines; x++)
	{
		for (int y = 0; y < NbColumns; y++)
		{
			matSize[y][x] = matSize[y][x] + i;
		}
	}
}

void Matrix3::Add(Matrix3 mat2)
{
	for (int x = 0; x < NbLines; x++)
	{
		for (int y = 0; y < NbColumns; y++)
		{
			matSize[x][y] += matSize[x][y];
		}
	}
}

void Matrix3::Multiply(float i)
{
	for (int x = 0; x < NbLines; x++)
	{
		for (int y = 0; y < NbColumns; y++)
		{
			matSize[y][x] = matSize[y][x] * i;
		}
	}
}

void Matrix3::Multiply(Matrix3 mat2)
{
	Matrix3 matResult = Matrix3(NbLines, mat2.NbColumns);
	for (int i = 0; i < matResult.NbLines; i++)
	{
		for (int y = 0; y < matResult.NbColumns; y++)
		{
			for (int x = 0; x < NbColumns; x++)
			{
				int tempResult = matSize[i][x] * mat2.matSize[x][y];
				matResult.matSize[i][y] += tempResult;
			}
		}
	}
}

Matrix3 Matrix3::Transpose()
{
	Matrix3 mat2 = Matrix3(NbColumns, NbLines);
	for (int i = 0; i < mat2.NbLines; i++)
	{
		for (int y = 0; y < mat2.NbColumns; y++)
		{
			mat2.matSize[i][y] = matSize[y][i];
		}
	}
	return mat2;
}

Matrix3 Matrix3::Add(Matrix3 mat, float i)
{
	Matrix3 matResult = mat;
	for (int x = 0; x < mat.NbLines; x++)
	{
		for (int y = 0; y < mat.NbColumns; y++)
		{
			matResult.matSize[x][y] += i;
		}
	}
	return matResult;
}

Matrix3 Matrix3::Add(Matrix3 mat, Matrix3 mat2)
{
	Matrix3 matResult = mat;
	for (int x = 0; x < mat.NbLines; x++)
	{
		for (int y = 0; y < mat.NbColumns; y++)
		{
			matResult.matSize[x][y] = mat.matSize[x][y] + mat2.matSize[x][y];
		}
	}
	return matResult;
}

Matrix3 Matrix3::Substract(Matrix3 mat, float i)
{
	Matrix3 matResult = mat;
	for (int x = 0; x < mat.NbLines; x++)
	{
		for (int y = 0; y < mat.NbColumns; y++)
		{
			matResult.matSize[x][y] -= i;
		}
	}
	return matResult;
}

Matrix3 Matrix3::Substract(Matrix3 mat, Matrix3 mat2)
{
	Matrix3 matResult = mat;
	for (int x = 0; x < mat.NbLines; x++)
	{
		for (int y = 0; y < mat.NbColumns; y++)
		{
			matResult.matSize[x][y] = mat.matSize[x][y] - mat2.matSize[x][y];
		}
	}
	return matResult;
}

Matrix3 Matrix3::Multiply(Matrix3 mat, float i)
{
	Matrix3 matResult = mat;
	for (int x = 0; x < mat.NbLines; x++)
	{
		for (int y = 0; y < mat.NbColumns; y++)
		{
			matResult.matSize[x][y] = matResult.matSize[x][y] * i;
		}
	}
	return matResult;
}

Matrix3 Matrix3::Multiply(Matrix3 mat, Matrix3 mat2)
{
	Matrix3 matResult = Matrix3(mat.NbLines, mat2.NbColumns);
	for (int i = 0; i < matResult.NbLines; i++)
	{
		for (int y = 0; y < matResult.NbColumns; y++)
		{
			for (int x = 0; x < mat.NbColumns; x++)
			{
				int tempResult = mat.matSize[i][x] * mat2.matSize[x][y];
				matResult.matSize[i][y] += tempResult;
			}
		}
	}
	return matResult;
}

Matrix3 Matrix3::operator+(const Matrix3& mat) const
{
	return Matrix3::Add(*this, mat);
}

Matrix3 Matrix3::operator-(const Matrix3& mat) const
{
	return Matrix3::Substract(*this, mat);
}

Matrix3 Matrix3::operator*(const Matrix3& mat) const
{
	return Matrix3::Multiply(*this, mat);
}

Matrix3 Matrix3::operator*(float value) const
{
	return Matrix3::Multiply(*this, value);
}
 
Vector2f Matrix3::operator*(const Vector2f& vector) const
{
	float vIn[3] = { vector.x, vector.y, 1 };
	float vOut[3]{};

	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < 3; j++)
			vOut[i] += matSize[i][j] * vIn[j];

	return Vector2(vOut[0], vOut[1]);
}

Matrix3& Matrix3::operator=(const Matrix3& mat)
{
	NbLines = mat.NbLines;
	NbColumns = mat.NbColumns;
	matSize = mat.matSize;

	return *this;
}

Matrix3& Matrix3::operator+=(const Matrix3& mat)
{
	Add(mat);

	return *this;
}

Matrix3& Matrix3::operator*=(const Matrix3& mat)
{
	Multiply(mat);

	return *this;
}

Matrix3& Matrix3::operator*=(float value)
{
	Multiply(value);

	return *this;
}



