using namespace std;
#include <iostream>
#include <memory>

class xyz {
	public:
        xyz(int a, int b) {
            x = a;
            y = b;
        }
        void print(void) {
            cout << "X:" << x << endl;
            cout << "Y:" << y << endl;
        }
	private:
        int x;
        int y;
};

int main(void) {
	cout << "hello world" << endl;
	
	unique_ptr<xyz> ptr(new xyz(1,2));
	ptr->print();
	
	unique_ptr<xyz> instance;
	instance = move(ptr);
	
	instance->print();
// 	ptr->print(); 
	
	return 0;
}
