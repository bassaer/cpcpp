#include <stdio.h>
#include <string>

using namespace std;

class Foo {
 public:
  Foo(string name) : name_(name) {}
  ~Foo() {}
  Foo(const Foo& foo) : name_(foo.getName()) {
    printf("Copied from %s\n", foo.getName().c_str());
  }
  void hello() const {
    printf("hello [%s]\n", name_.c_str());
  }

  void setName(string name) {
    name_ = name;
  }
  const string getName() const {
    return name_;
  }
 private:
  string name_;
};

int main() {
  printf("==foo1==\n");
  Foo foo1("foo1");
  foo1.hello();

  printf("==foo2==\n");
  Foo foo2 = foo1;
  foo2.hello();

  printf("==foo3==\n");
  Foo foo3 = Foo(foo1);
  foo3.hello();

  printf("==foo4==\n");
  Foo& foo4 = foo1;
  foo4.hello();

  printf("==foo5==\n");
  const Foo& foo5 = foo1;
  foo5.hello();

  printf("==foo6==\n");
  Foo* foo6 = new Foo("foo6");
  foo6->hello();

  printf("==foo7==\n");
  Foo* foo7 = foo6;
  foo7->hello();
  delete foo6;
}
