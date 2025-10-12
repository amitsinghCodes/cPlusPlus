#include <iostream>
using namespace std;

class singleton{
  public:
  static singleton* instance(){
      return inst;
  }
  void show(){
      cout<<"singleton";
  }
  
  singleton(const singleton& other) = delete;
  singleton& operator=(const singleton& other) = delete;
  singleton(const singleton&& other) = delete;
  singleton& operator=(const singleton&& other) = delete;
  
  private:
  
  static singleton* inst;
  singleton(){}
  ~singleton(){}
};

singleton* singleton::inst = NULL;

int main(){
    singleton* ptr = singleton::instance();
    ptr->show();
    
    return 0;
}