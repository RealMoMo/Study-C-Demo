#include <iostream>

//继承
//代码的重用性
using namespace std;

/*
//人类
class Human{
public:
	void say(){
		cout << "说话" << endl;
	}
protected:
	char* name;
	int age;
};

//男人
class Man : public Human{
public:
	//泡妞
	void chasing(){
		cout << "泡妞" << endl;		
	}
private:
	//兄弟
	char* brother;
};

void work(Human& h){
	h.say();
}

void main(){
	Man m1;
	m1.say();

	//1.父类类型的引用或指针
	Human* h_p = &m1;
	h_p->say();

	Human &h1 = m1;
	h1.say();

	//子类对象初始化父类类型的对象
	Human h2 = m1;

	system("pause");
}
*/

//向父类构造方法传参
//人类
/*
class Human{
public:
	Human(char* name, int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "说话" << endl;
	}
protected:
	char* name;
	int age;
};

//男人
class Man : public Human{
public:
	//给父类构造函数传参，同时给属性对象赋值
	Man(char *brother, char *s_name, int s_age, char *h_name, int h_age) : Human(s_name, s_age), h(h_name,h_age){
		this->brother = brother;
	}
	//泡妞
	void chasing(){
		cout << "泡妞" << endl;
	}
private:
	//兄弟
	char* brother;
	Human h;
};

void main(){
	Man m1("danny","jack",18,"jason",18);

	system("pause");
}
*/


//构造函数与析构函数调用的顺序
/*
class Human{
public:
	Human(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Human 构造函数" << endl;
	}
	~Human(){
		cout << "Human 析构函数" << endl;
	}
	void say(){
		cout << "说话" << endl;
	}
protected:
	char* name;
	int age;
};

//男人
class Man : public Human{
public:
	//给父类构造函数传参，同时给属性对象赋值
	Man(char *brother, char *s_name,int s_age) : Human(s_name, s_age){
		this->brother = brother;
		cout << "Man 构造函数" << endl;
	}
	~Man(){
		cout << "Man 析构函数" << endl;
	}
	//泡妞
	void chasing(){
		cout << "泡妞" << endl;
	}
private:
	//兄弟
	char* brother;	
};

void func(){
	//父类构造函数先调用
	//子类的析构函数先调用
	Man m1("danny", "jack", 18);
}

void main(){
	func();

	system("pause");
}
*/


//子类对象调用父类的成员
/*
class Human{
public:
	Human(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Human 构造函数" << endl;
	}
	~Human(){
		cout << "Human 析构函数" << endl;
	}
	void say(){
		cout << "说话" << endl;
	}
public:
	char* name;
	int age;
};

//男人
class Man : public Human{
public:
	//给父类构造函数传参，同时给属性对象赋值
	Man(char *brother, char *s_name, int s_age) : Human(s_name, s_age){
		this->brother = brother;
		cout << "Man 构造函数" << endl;
	}
	~Man(){
		cout << "Man 析构函数" << endl;
	}
	//泡妞
	void chasing(){
		cout << "泡妞" << endl;
	}
	void say(){
		cout << "男人喜欢装逼" << endl;
	}
private:
	//兄弟
	char* brother;
};

void main(){
	//是覆盖，并非动态
	Man m1("alan","john",18);
	m1.say();
	m1.Human::say();

	m1.Human::age = 10;

	system("pause");
}
*/

//多继承
/*
//人
class Person{

};

//公民
class Citizen{

};

//学生，既是人，又是公民
class Student : public Person, public Citizen{

};
*/

//继承的访问修饰
//基类中      继承方式             子类中
//public     ＆ public继承 = > public
//public     ＆ protected继承 = > protected
//public     ＆ private继承 = > private
//
//protected  ＆ public继承 = > protected
//protected  ＆ protected继承 = > protected
//protected  ＆ private继承 = > private
//
//private    ＆ public继承 = > 子类无权访问
//private    ＆ protected继承 = > 子类无权访问
//private    ＆ private继承 = > 子类无权访问
//人类
/*
class Human{
public:
	void say(){
		cout << "说话" << endl;
	}
private:
	char* name;
	int age;
};

//男人
class Man : protected Human{
public:
	//泡妞
	void chasing(){
		cout << "泡妞" << endl;		
	}
private:
	//兄弟
	char* brother;
};
*/

//继承的二义性
//虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
/*
class A{
public:
	char* name;
};

class A1 : virtual public A{
	
};

class A2 : virtual public A{

};

class B : public A1, public A2{

};

void main(){
	B b;	
	b.name = "jason";
	//指定父类显示调用
	//b.A1::name = "jason";
	//b.A2::name = "jason";
	system("pause");
}
*/

/*
//虚函数
//多态（程序的扩展性）
//动态多态：程序运行过程中，觉得哪一个函数被调用（重写）
//静态多态：重载

//发生动态的条件：
//1.继承
//2.父类的引用或者指针指向子类的对象
//3.函数的重写

#include "Plane.h"
#include "Jet.h"
#include "Copter.h"
//业务函数
void bizPlay(Plane& p){
	p.fly();
	p.land();
}

void main(){
	Plane p1;
	bizPlay(p1);

	//直升飞机
	Jet p2;
	bizPlay(p2);

	Copter p3;
	bizPlay(p3);

	system("pause");
}
*/

//纯虚函数(抽象类)
//1.当一个类具有一个纯虚函数，这个类就是抽象类
//2.抽象类不能实例化对象
//3.子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
//抽象类的作用：为了继承约束，根本不知道未来的实现
//形状
/*
class Shape{
public:
	//纯虚函数
	virtual void sayArea() = 0;
	void print(){
		cout << "hi" << endl;
	}
};

//圆
class Circle : public Shape{
public:
	Circle(int r){
		this->r = r;
	}
	void sayArea(){
		cout << "圆的面积：" << (3.14 * r * r) << endl;
	}
private:
	int r;
};

void main(){
	//Shape s;
	Circle c(10);

	system("pause");
}

*/

//接口（只是逻辑上的划分，语法上跟抽象类的写法没有区别）
//可以当做一个接口
/*
class Drawble{
	virtual void draw();
};
*/

//模板函数（泛型）
/*
void myswap(int& a,int& b){
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void myswap(char& a, char& b){
	char tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
*/

//发现：这两个函数业务逻辑一样，数据类型不一样
template <typename T>
void myswap(T& a, T& b){
	T tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void main(){
	//根据实际类型，自动推导
	int a = 10, b = 20;
	myswap<int>(a,b);
	cout << a << "," << b << endl;

	char x = 'v', y = 'w';
	myswap(x, y);
	cout << x << "," << y << endl;

	system("pause");
}


