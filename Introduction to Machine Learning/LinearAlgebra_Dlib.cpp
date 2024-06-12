#include <dlib/image_processing.h>
#include <dlib/matrix.h>
#include <iostream>

using namespace std;

int main()
{
	////////////////////////////////// Dlib //////////////////////////////////

	// Create a matrix sized at compile time
	dlib::matrix<double, 3, 1> y;
	// Create a dynamically sized matrix
	dlib::matrix<double> m(2, 2);
		// Later we can change the size of above matrix using 'set_size()' method
	m.set_size(3, 3);

	// Initialize matrix values using a comma operator
	m = 54.2, 7.4, 12.1,
		1, 2, 3,
		5.9, 0.05, 1;

	cout << m << endl << endl;

	// Wrap an existing array to the matrix object
	double data[] = { 1, 2, 3, 4, 5, 6 };
	auto a = dlib::mat(data, 2, 3); // create a matrix with size 2x3

	cout << a << endl << endl;

	// Access matrix elements with the '()' operator
	m(1, 2) = 6;

	// Predefined functions to initialize a matrix
	auto b = dlib::identity_matrix<double>(3); // fill matrix as Identity matrix
	auto c = dlib::ones_matrix<double>(3, 4); // fill matrix with 1s
	auto d = dlib::randm(3, 4); // matrix with random values with size 3x3

	cout << d << endl;

	// Arithmetic operations
	auto e = c + c;
	auto f = b * c;
	auto g = dlib::pointwise_multiply(c, c); // element-wise multiplication
	dlib::matrix<double, 4, 3> h;
	h = dlib::trans(c); // transpose matrix

	// Get partial access to matrices
	auto j = dlib::rowm(c, 0); // takes first row of matrix
	auto k = dlib::rowm(c, dlib::range(0, 1)); // takes first two rows
	auto l = dlib::colm(c, 0); // takes first column
	auto n = dlib::subm(c, dlib::range(1, 2), dlib::range(1, 2)); // takes a rectangular part from center
	dlib::set_subm(m, dlib::range(0, 1), dlib::range(0, 1)) = 7; // initialize part of the matrix
	dlib::set_subm(m, dlib::range(0, 1), dlib::range(0, 1)) += 8; // add a value to the part of the matrix

	// Broadcasting can be modeled with 'set_rowm()', 'set_colm()', and 'set_subm()' functions
		dlib::matrix<float, 2, 2> x;
		dlib::matrix<float, 2, 3> z;
		dlib::set_colm(z, dlib::range(0, 1)) += x; // selects the first two columns(columns 0 and 1) of z, resulting in a submatrix with 2 rows and 2 columns.


	return 0;
}