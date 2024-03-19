#include<iostream>
#include<mutex>

using namespace std;

mutex _m;

class singleton {
private:
	singleton() { cout << "Constructor called" << endl; }
	~singleton() { cout << "Destructor called" << endl; }
	static singleton* instance;
	static int count;

	static void addRef()
	{
		++count;
		cout << "Count Increament:" << count << endl;;
	}

	static void releaseRef()
	{
		--count;
		cout << "Count Decreament:" << count << endl;;
	}

public:

	singleton(const singleton&) = delete;
	singleton& operator = (singleton&) = delete;

	/*static singleton& GetInstance()
	{
		static singleton instance;
		return instance;
	}*/

	static singleton* GetInstance()
	{
		if (instance == nullptr)
		{
			lock_guard<mutex>lck(_m);
			if (instance == nullptr)
			{
				instance = new singleton();

			}
		}
		addRef();
		return instance;
	}

	static void ReleaseInstance()
	{
		releaseRef();
		if (count == 0 && instance != nullptr)
		{
			delete instance;
			instance = NULL;
		}
	}

	void Display()
	{
		cout << count;
	}
};

singleton* singleton::instance = nullptr;
int singleton::count = NULL;

int main0()
{
	//singleton &A = singleton::GetInstance();

	singleton *A = singleton::GetInstance();
	singleton *B = singleton::GetInstance();


	singleton::ReleaseInstance();
	singleton::ReleaseInstance();

	std::cin.get();

	return 0;
}