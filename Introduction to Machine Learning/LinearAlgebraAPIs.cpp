#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;

int main()
{
	// Define the type for a matrix with known dimensions and floating data type
	typedef Eigen::Matrix<float, 3, 3> MyMatrix33f;
	// Define a vector
	typedef Eigen::Matrix<float, 3, 1> MyVector3f;
	// Define a matrix of doubles with dynamic dimensions where we take
	//		the number of rows and coulumns at initialization during runtime
	typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MyMatrix;

	// Objects initialized from the types defined above
	MyMatrix33f a;
	MyVector3f v;
	MyMatrix m(10, 15);

	// Put some values into these objects
	a = MyMatrix33f::Zero(); // fill matrix elements with zeros
	a = MyMatrix33f::Identity(); // fill matrix as Identity matrix
	v = MyVector3f::Random(); // fill matrix elements with random values

	// Use the comma-initializer syntax
	a << 1, 2, 3,
		 4, 5, 6,
		 7, 8, 9;
	// Use direct element access to set or change matrix coefficients using () operator.
	a(0, 0) = 3;

	cout << a << endl;
	cout << v << endl;
	cout << endl;

	
	// Use the object of the 'Map' type to wrap an existent c++ array or vector
	//		in the 'Matrix' type object.
	int data[] = { 1,2,3,4 };
	Eigen::Map<Eigen::RowVectorXi> v2(data, 4);
	cout << v2 << endl;
	cout << endl;

	vector<float> data2 = { 1,2,3,4,5,6,7,8,9 };
	Eigen::Map<MyMatrix33f> a2(data2.data());
	cout << a2 << endl;
	cout << endl;
	
	
	// Perform operations only on a part of the matrix using 'block' method.
	//		'block' method takes four parameters: i, j, p, q
	//		These parameters are starting point i, j and the block size p, q
	Eigen::MatrixXf m2 = Eigen::MatrixXf::Random(4, 4);
	cout << "Original m2 matrix:\n" << m2 << endl << endl;
	Eigen::Matrix2f m3 = m2.block(1, 1, 2, 2); // Copying the middle part of matrix
	cout << "Copied portion to m3 matrix from m2\n" << m3 << endl << endl;
	m2.block(1, 1, 2, 2) *= 4; // change values in original matrix
	cout << "m2 matrix after modification\n" << m2 << endl << endl;

	// Use 'col' and 'row' methods to access rows and columns by index
	m2.row(1).array() += 3;
	m2.col(2).array() /= 2;
	cout << "New m2 matrix:\n" << m2 << endl << endl;

	// Broadcasting a matrix (Replicating a matrix in one direction) colwise and rowwise
	Eigen::MatrixXf mat = Eigen::MatrixXf::Random(2, 4);
	Eigen::VectorXf vec(2);
	vec << 0,
		   1;
	cout << "Original mat matrix:\n" << mat << endl << endl;
	cout << "Vector vec:\n" << vec << endl << endl;

	mat.colwise() += vec;
	cout << "mat after colwise addition:\n" << mat << endl << endl;




	return 0;
}
