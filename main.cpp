#include <iostream>

class Matrix{
	private:
		int m_row;
		int m_column;
		int** m_arr_2d;
	public:
		Matrix(){
			m_row = m_column = 3;
			m_arr_2d = new int*[m_row];
			for(int i = 0; i < m_row; i++){
				m_arr_2d[i] = new int[m_column];
			}
		}

		Matrix(int n, int m){
			if (n < 1 || m < 1){
				std::cerr << "Sizes of matrix can't be negative or 0\n";
				abort();
			}
			m_row = n;
			m_column = m;
			m_arr_2d = new int*[m_row];
			for(int i = 0; i < m_row; i++){
				m_arr_2d[i] = new int[m_column];
			}
		}

		~Matrix(){
			for(int i = 0; i < m_row; i++){
				delete[] m_arr_2d[i];
				m_arr_2d[i] = nullptr;
			}
			delete[] m_arr_2d;
			m_arr_2d = nullptr;
		}
		
		Matrix(const Matrix& obj){
			this->m_row = obj.m_row;
			this->m_column = obj.m_column;
			this->m_arr_2d = new int*[this->m_row];
			for (int i = 0; i < this->m_row; i++){
				this->m_arr_2d[i] = new int[this->m_column];
				for (int j = 0; j < m_column; j++){
					this->m_arr_2d[i][j] = obj.m_arr_2d[i][j];
				}
			}
		}

		Matrix& operator = (const Matrix& obj){
			if (this != &obj){
				for (int i = 0; i < this->m_row; i++){
					delete[] this->m_arr_2d[i];
					this->m_arr_2d[i] = nullptr;
				}
				delete[] this->m_arr_2d;
				this->m_arr_2d = nullptr;
				this->m_row = obj.m_row;
				this->m_column = obj.m_column;
				this->m_arr_2d = new int*[this->m_row];
				for (int i = 0; i < this->m_row; i++){
					this->m_arr_2d[i] = new int[this->m_column];
					for (int j = 0; j < m_column; j++){
						this->m_arr_2d[i][j] = obj.m_arr_2d[i][j];
					}
				}
			}
			return *this;
		}

		Matrix(Matrix&& obj)
			: m_row(obj.m_row), m_column(obj.m_column), m_arr_2d(obj.m_arr_2d)
		{
			obj.m_row = 0;
			obj.m_column = 0;
			obj.m_arr_2d = nullptr;
		}

		Matrix& operator=(Matrix&& obj)
		{
			if (this != &obj){
				for (int i = 0; i < this->m_row; i++){
					delete[] this->m_arr_2d[i];
				}
				delete[] this->m_arr_2d;
				this->m_row = obj.m_row;
				this->m_column = obj.m_column;
				this->m_arr_2d = obj.m_arr_2d;
				obj.m_row = 0;
				obj.m_column = 0;
				obj.m_arr_2d = nullptr;
			}
			return *this;
		}

	public:
		void print(){
			for (int i = 0; i < m_row; i++){
				for (int j = 0; j < m_column; j++){
					std::cout << m_arr_2d[i][j] << "\t";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		void init(){
			for (int i = 0; i < m_row; i++){
				for (int j = 0; j < m_column; j++){
					m_arr_2d[i][j] = rand() % 90 + 10;
				}
			}
		}

};

void delete_and_nullptr(Matrix* obj){
	delete obj;
	obj = nullptr;
}

int main(){
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
	
	Matrix a(3,3);
	a.init();
	a.print();
	Matrix b(7,7);
	b.init();
	b.print();

	b = std::move(a);	

	b.print();

	return 0;
}
