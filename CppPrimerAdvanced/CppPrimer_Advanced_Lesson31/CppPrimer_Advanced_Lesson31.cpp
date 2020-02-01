#include <iostream>

using namespace std;

class A
{
public:
	static std::size_t object_count()
	{
		return 100;
	}

protected:
	static const std::size_t obj_count = 99;;
};

class B :public A
{
public:
	void f(const B& b)
	{	
		cout << A::obj_count << endl;
		cout << B::obj_count << endl;
		cout << b.obj_count << endl;
		cout << obj_count << endl;

		cout << A::object_count() << endl;
		cout << B::object_count() << endl;
		cout << b.object_count() << endl;
		cout << object_count() << endl;
	}
	void f(const B* b)
	{	
		cout << A::obj_count << endl;
		cout << B::obj_count << endl;
		cout << b->obj_count << endl;
		cout << obj_count << endl;

		cout << A::object_count() << endl;
		cout << B::object_count() << endl;
		cout << b->object_count() << endl;
		cout << object_count() << endl;
	}
};

//std::size_t A::obj_count = 99;

int main()
{
	B b;
	b.f(b);

	B* b1 = new B();
	b1->f(b1);

	system("pause");
	return 0;
}