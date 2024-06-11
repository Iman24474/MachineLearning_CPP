#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xtensor.hpp>
#include <xtensor/xfixed.hpp>
#include <xtensor/xrandom.hpp>
#include <xtensor-blas/xlinalg.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	////////////////////////////////// Xtensor //////////////////////////////////

	// Define dynamically sized multidimensional array
	vector<size_t> shape = { 3,2,4 };
	xt::xarray<double, xt::layout_type::row_major> a(shape);

	cout << a << endl << endl;

	// Define a multidimensional array whose dimensions are fixed at compilation time
	//		Exact dimension values can be configured in the initialization step shown below
	//		The first dimension (size 3) can be thought of as layers or slices of the array.
	//		The second dimension (size 2) represents the number of rows within each layer.
	//		The third dimension (size 4) represents the number of columns within each row.
	array<size_t, 3> shape1 = { 3,2,4 };
	xt::xtensor<double, 3> a1(shape1);

	cout << a1 << endl << endl;

	// Define a multidimensional array with a dimension shape fixed at compile time
	xt::xtensor_fixed<double, xt::xshape<3, 2, 4>> a2;

	cout << a2 << endl << endl;

	// Different kinds of container initialization
	// Initialization of xtensor arrays
	xt::xarray<double> arr1
	{
		{1.0, 2.0, 3.0},
		{2.0, 5.0, 7.0},
		{2.0, 5.0, 7.0}
	}; // initialize a 3x3 array

	// Builder functions for initialization
	vector<uint64_t> shape2 = { 2,2 };
	xt::ones<double>(shape2); // fill matrix elements with ones
	xt::zeros<double>(shape2); // fill matrix elements with zeros
	xt::eye<double>(shape2); // matrix with ones on the diagonal

	// Use direct access to container elements with the '()' operator
	vector<size_t> shape3 = { 3, 2, 1 }; 
	xt::xarray<float> a3 = xt::ones<float>(shape3);
	a3(1, 1, 0) = 3.14f;

	cout << a3 << endl << endl;

	// Arithmetic operations
	auto b = xt::random::rand<double>({ 2,2 });
	auto c = xt::random::rand<double>({ 2,2 });
	auto d = b + c;
	cout << b << endl << endl << c << endl << endl << d << endl << endl;
	
	auto e = xt::linalg::dot(b, c);

	// Get partial access to the xtensor containers
	xt::xarray<int> a4
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	auto f = xt::view(a4, xt::range(1, 3), xt::range(1, 3));

	cout << a4 << endl << endl<< f << endl;

	// Xtensor implements automatic broadcasting in most cases
	//		When the operation involves two arrays of different dimensions, it transmits the array with the smaller
	//		dimension across the leading dimension of the other array, so we can directly add a vector to a matrix
	auto m = xt::random::rand<double>({ 2,2 });
	auto v = xt::random::rand<double>({ 2,1 });
	auto g = m + v;


	return 0;
}