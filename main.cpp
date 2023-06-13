#include <iostream>

class Matrix{
	private:
		int** arr_2d;
		int row;
		int column;
	public:
		Matrix(){
			row = column = 3;
			arr_2d = new int*[row];
			for(int i = 0; i < row; i++){
				arr_2d[i] = new int[column];
			}
		}

		Matrix(int n, int m){
			if (n < 1 || m < 1){
				std::cerr << "Sizes of matrix can't be negative or 0\n";
				abort();
			}
			row = n;
			column = m;
			arr_2d = new int*[row];
			for(int i = 0; i < row; i++){
				arr_2d[i] = new int[column];
			}
		}

		~Matrix(){
			for(int i = 0; i < row; i++){
				delete[] arr_2d[i];
				arr_2d[i] = nullptr;
			}
			delete[] arr_2d;
			arr_2d = nullptr;
		}
		
		Matrix(const Matrix& obj){
			this->row = obj.row;
			this->column = obj.column;
			this->arr_2d = new int*[this->row];
			for (int i = 0; i < this->row; i++){
				this->arr_2d[i] = new int[this->column];
				for (int j = 0; j < column; j++){
					this->arr_2d[i][j] = obj.arr_2d[i][j];
				}
			}
		}

		Matrix& operator = (const Matrix& obj){
			if (this != &obj){
				this->row = obj.row;
				this->column = obj.column;
				this->arr_2d = new int*[this->row];
				for (int i = 0; i < this->row; i++){
					this->arr_2d[i] = new int[this->column];
					for (int j = 0; j < column; j++){
						this->arr_2d[i][j] = obj.arr_2d[i][j];
					}
				}
			}
			return *this;
		}

		void print(){
			for (int i = 0; i < row; i++){
				for (int j = 0; j < column; j++){
					std::cout << arr_2d[i][j] << "\t";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		void init(){
			for (int i = 0; i < row; i++){
				for (int j = 0; j < column; j++){
					arr_2d[i][j] = rand() % 90 + 10;
				}
			}
		}

};

void delete_and_nullptr(Matrix* obj){
	delete obj;
	obj = nullptr;
}

int main(){
	Matrix* obj_default = new Matrix;
	obj_default->init();
	std::cout << "Default constructor\n";
	obj_default->print();

	int n, m;
	std::cout << "Row = ";
	std::cin >> n;
	std::cout << "Column = ";
	std::cin >> m;
	Matrix* obj_parameterized = new Matrix(n,m);
	obj_parameterized->init();
	std::cout << "Parameterized constuctor\n";
	obj_parameterized->print();

	Matrix* obj_copy = new Matrix(*obj_default);
	std::cout << "Copy constuctor\n";
	obj_copy->print();

	Matrix* obj_oper_as = new Matrix;
	*obj_oper_as = *obj_parameterized;
	std::cout << "Operator =\n";
	obj_oper_as->print();

	delete_and_nullptr(obj_default);
	delete_and_nullptr(obj_parameterized);
	delete_and_nullptr(obj_copy);
	delete_and_nullptr(obj_oper_as);
	
	return 0;
}