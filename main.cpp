#include "Matrix.h"
#include <fstream>



void delete_and_nullptr(Matrix* obj){
	delete obj;
	obj = nullptr;
}

int main(){

	std::ofstream txt;

	txt.open("matrix.txt");

	if (!txt.is_open()){
		std::cerr << "Error" << std::endl;
		exit(1);
	}

	Matrix mat(5,5);

	mat.init();
	mat.print();

	for (int i = 0; i < mat.rows(); i++){
		for (int j = 0; j < mat.columns(); j++){
			txt << mat[i][j] << std::endl;
		}
	}

	txt.close();

	// Matrix* obj_default = new Matrix;
	// obj_default->init();
	// std::cout << "Default constructor\n";
	// obj_default->print();

	// int n, m;
	// std::cout << "Row = ";
	// std::cin >> n;
	// std::cout << "Column = ";
	// std::cin >> m;
	// Matrix* obj_parameterized = new Matrix(n,m);
	// obj_parameterized->init();
	// std::cout << "Parameterized constuctor\n";
	// obj_parameterized->print();

	// Matrix* obj_copy = new Matrix(*obj_default);
	// std::cout << "Copy constuctor\n";
	// obj_copy->print();

	// Matrix* obj_oper_as = new Matrix;
	// *obj_oper_as = *obj_parameterized;
	// std::cout << "Operator =\n";
	// obj_oper_as->print();

	// delete_and_nullptr(obj_default);
	// delete_and_nullptr(obj_parameterized);
	// delete_and_nullptr(obj_copy);
	// delete_and_nullptr(obj_oper_as);



	// Matrix a(3,3);
	// a.init();
	// a.print();
	// Matrix b(7,7);
	// b.init();
	// b.print();

	// b = std::move(a);	

	// b.print();

	return 0;
}
