// Find the output/Error in below code snippned
#include <iostream>

using namespace std;
class Base
{
	private:
		int var1; 
	protected :
		int var2;
	public :
		int var3;
		virtual void fun1(){cout<<"Base";}
		virtual void fun2(){cout<<"Base";}
		void fun3(){cout<<"Base";}
		void fun4(){cout<<"Base";}
		~Base(){cout<<"Base: Destructor";};
};
class Derived : public Base
{
	private:
		int var4;
	protected :
		int var5;
	public :
		int var6;
		void fun1(){cout<<"Derived";}		
		void fun3(){cout<< "Derived";}
		virtual void fun5(){cout<< "Derived";}
		void fun6(){cout<< "Derived";}
		~Derived(){cout<<"Derived: Destructor";}; 
		
		
};
int main()
{
	Base *bPtr= new Derived();
	bPtr ->fun1(); //derived
	bPtr ->fun2(); // base
	bPtr ->fun3(); // base
	bPtr ->fun4(); // base
	//bPtr ->fun5();  //wrong not declared in base class  //Derived* dPtr = dynamic_cast<Derived*>(bPtr);   if (dPtr) dPtr->fun6();  // ✅ now you can call fun6
	//bPtr ->fun6(); //wrong not declared in base class
	delete bPtr;  // will call basedd ddestructor
	Base obj;
	Derived der;
	std::cout << "\n" << sizeof(obj);// 12 + 2 virtual function
	std::cout << "\n" << sizeof(der); // 12 + 1 virtuazzl function
}			