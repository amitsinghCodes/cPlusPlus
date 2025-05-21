// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

class Vector{
  
  private:
  int* arr;
  int capacity;
   int size;
  
  public:
  Vector(): arr(new int[2]), capacity(2), size(0){
      cout<<"default constructor is called"<<endl;
  }
  
  Vector(Vector& other){
    size = other.size;
    arr = new int[size];
    for(int i =  0; i<size;i++){
        arr[i] = other.arr[i];
    }
}

  int getsize() const{
      return size;
  }
 
   int getcapacity() const{
      return capacity;
   }
   
   void push_back(int t) {
       if(capacity == size)
       resize();
       
       arr[size++] = t;
   }
   void resize(){
       capacity *= 2;
       int *temp = new int[capacity];
       
       for(int i = 0;i<size; i++){
           temp[i] = arr[i];
       }
       
       delete[] arr;
       arr = temp;
   }
   
   int operator[](int index){
       if(index>= size && index<=0)
       throw out_of_range("Index out of range");
       
       return arr[index];
   }
   
};


int main() {
Vector vec1; // default constructor
vec1.push_back(10);
vec1.push_back(20);
vec1.push_back(30);
for(int i = 0; i< vec1.getsize(); i++)
cout<<vec1[i]<<endl;

cout<<vec1.getsize()<<endl;
cout<<vec1.getcapacity()<<endl;


    return 0;
}