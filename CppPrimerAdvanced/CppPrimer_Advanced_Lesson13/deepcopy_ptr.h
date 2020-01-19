#pragma once

class CHasPtr
{
private:
	int val;
	int* ptr;

public:
	CHasPtr(const int& p, int i) :ptr(new int(p)), val(i) {}
	CHasPtr(const CHasPtr& chp):ptr(new int(*(chp.ptr)))
	{
		this->val = chp.val;
	}
	CHasPtr& operator=(const CHasPtr& chp) 
	{
		this->val = chp.val;
		this->ptr = new int(*(chp.ptr));
	}
	~CHasPtr() { delete ptr; }

	int* get_ptr() const { return ptr; }
	int get_int() const { return val; }

	void set_ptr(int* p) { ptr = p; }
	void set_int(int i) { val = i; }

	int get_ptr_val() const { return *ptr; }
	void set_ptr_val(int val) { *ptr = val; }

};
