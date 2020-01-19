#include <iostream>
#include "plain_ptr.h"
#include "deepcopy_ptr.h"
#include "smart_ptr.h"
#include <memory>

using namespace std;

void test_AHasPtr()
{
	int i = 42;
	AHasPtr p1(&i, 42);
	AHasPtr p2 = p1;
	cout << i << ", " << p1.get_int()<<", " << p1.get_ptr_val()<< endl;
	cout << i << ", " << p2.get_int() <<", "<< p2.get_ptr_val() << endl << endl;

	p1.set_ptr_val(0);
	cout << i << ", " << p1.get_int() << ", " << p1.get_ptr_val() << endl;
	cout << i << ", " << p2.get_int() << ", " << p2.get_ptr_val() << endl << endl;

	int* ip = new int(42);
	AHasPtr ptr(ip, 42);
	cout << ptr.get_ptr_val() << endl;
	delete ip;
	cout << ptr.get_ptr_val() << endl;
}

void test_CHasPtr()
{
	//int obj = 0;
	//CHasPtr ptr1(obj, 42);
	int* obj = new int(0);
	CHasPtr ptr1(*obj, 42);
	CHasPtr ptr2(ptr1);

	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
}

void test_BHasPtr()
{
	int obj = 0;

	BHasPtr ptr1(&obj, 42);
	BHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
}


class auto_ptr_Test
{
public:
	auto_ptr_Test(string s) :str(s) { cout << "Test creat" << endl; }
	~auto_ptr_Test() { cout << "Test delete" << endl; }

	string& getStr() { return str; }
	void setStr(string s) { str = s; }
	void print() { cout << str << endl; }

private:
	string str;
};

class unique_ptr_Test
{
	friend unique_ptr<unique_ptr_Test> fun();
public:
	unique_ptr_Test() {}
	unique_ptr_Test(string s) :str(s) { cout << "Test creat" << endl; }
	~unique_ptr_Test() { cout << "Test delete" << endl; }

	string& getStr() { return str; }
	void setStr(string s) { str = s; }
	void print() { cout << str << endl; }
	
private:
	string str;
};

class Entity
{
public:
	Entity() { std::cout << "Created Entity!" << std::endl; }
	~Entity() { std::cout << "Destroyed Entity!" << std::endl; }

	void print() { cout << "the print has been invocated! "<<endl; }
};

unique_ptr<unique_ptr_Test> fun()
{

	unique_ptr<unique_ptr_Test> npt(new unique_ptr_Test("123456"));

	return npt;
}
 
int main()
{
	{
		test_AHasPtr();
		test_CHasPtr();
		test_BHasPtr();
	}
	

	{
		//std::unique_ptr<Entity> entity(new Entity());//yes
		//entity->print();
		//std::unique_ptr<Entity> entity = new Entity();//error
		std::unique_ptr<Entity> unique_entity = std::make_unique<Entity>();
		unique_entity->print();

		std::shared_ptr<Entity> share_entity = std::make_shared<Entity>();
		//share_entity->print();

		std::weak_ptr<Entity> weak_entity = share_entity;
		share_entity->print();
	}

	{
		auto_ptr<auto_ptr_Test> atptest(new auto_ptr_Test("123"));
		atptest->print();
		atptest->setStr("hello ");
		//atptest.release(); // it is to set atptest to null, and it is different to delete() and reset()
		if (atptest.get() != NULL)
		{
			atptest.get()->print();
		}
		
		atptest->getStr() += "world !";
		if (atptest.get() != NULL)
		{
			atptest.get()->print();
		}

		atptest.reset(new auto_ptr_Test("1234"));
		if (atptest.get() != NULL)
		{
			atptest.get()->print();
		}
	}

	{
		unique_ptr<unique_ptr_Test> uqptest1(new unique_ptr_Test("123456789"));
		unique_ptr<unique_ptr_Test> uqptest2(new unique_ptr_Test("987654321"));
		uqptest1->print();
		uqptest2->print();

		uqptest1 = std::move(uqptest2);
		if (uqptest1==NULL)
		{
			cout << "uqptest1 is not null";
		}
		//unique_ptr_Test* p = uqptest2.release();
		//p->print();
		//uqptest1.reset(p);
		//uqptest1->print();
		//uqptest2 = fun();
		//uqptest2->print();
				
	}

	{
		shared_ptr<unique_ptr_Test> sdpTest1(new unique_ptr_Test("fewfe"));
		shared_ptr<unique_ptr_Test> sdpTest2(new unique_ptr_Test("fsadff"));
	
		cout << sdpTest2->getStr() << endl;
		cout << sdpTest2.use_count() << endl;

		sdpTest1 = sdpTest2;
		cout << sdpTest1->getStr() << endl;
		cout << sdpTest1.use_count() << endl;
		cout << sdpTest2.use_count() << endl;

		sdpTest1.reset();
		sdpTest2.reset();
		cout << sdpTest1.use_count() << endl;
		cout << sdpTest2.use_count() << endl;

	}

	return 0;
}