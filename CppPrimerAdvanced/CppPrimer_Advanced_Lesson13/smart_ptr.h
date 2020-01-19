#pragma once

class U_Ptr
{
	friend class BHasPtr;
private:
	int* ip;
	size_t use;//count
	U_Ptr(int* p) :ip(p), use(1) {}
	//~U_Ptr() { delete ip; }

};


class BHasPtr
{
private:
	int val;
	U_Ptr* ptr;

public:
	BHasPtr(int* p, int i) :ptr(new U_Ptr(p)), val(i) {}
	BHasPtr(const BHasPtr& orig) :ptr(orig.ptr), val(orig.val) 
	{
		++ptr->use;
	}
	BHasPtr& operator=(const BHasPtr& bhp)
	{
		++bhp.ptr->use;
		if (--ptr->use == 0)
		{
			delete ptr;
		}
		ptr = bhp.ptr;
		val = bhp.val;

		return *this;
	}
	~BHasPtr()
	{
		if (--ptr->use == 0)
		{
			delete ptr;
		}
	}

	int* get_ptr() const { return ptr->ip; }
	int get_int() const { return val; }

	void set_ptr(int* p) { ptr->ip = p; }
	void set_int(int i) { val = i; }

	int get_ptr_val() const { return *(ptr->ip); }
	void set_ptr_val(int val) { *(ptr->ip) = val; }

};