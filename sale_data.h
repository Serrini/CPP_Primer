#include <string>
#include <iostream>
//声明
class sale_data
{
//为sale_data的非成员函数所做的友元声明，为了使他们可以访问到priva内的数据成员
friend sale_data add(const sale_data&, const sale_data&);
friend std::ostream &print(std::ostream&, const sale_data&);
friend std::istream &read(std::istream&, sale_data&);

public: //访问说明符（access specifiers）
	//constructors构造函数
	sale_data() = default; //这是一个空参数列表，即默认构造函数
	/*c++11标准中，需要默认，可在参数列表后面写上=default要求编译器生成构造函数。
	=default可在类的内部则该constructor是inline的，反之则外联。*/

	/*WARNING！对内置类型的数据成员提供了初始值，如果编译器不支持类内初始值，
	则constructor应该使用构造函数初始值列表,如下两个*/
	sale_data(const std::string &s): bookNo(s) { }
				//:与{}之间为构造函数初始值列表
				//构造函数const string&，用于表示isbn编号
	sale_data(const std::string &s, unsigned n, double p):
				bookNo(s), units_sold(n), revenue(p*n) { }
				//{}内为空是因为构造函数唯一目的是为数据成员赋初值，没有其他任务要执行
				//构造函数const string&，用于表示isbn编号
				//usigned，用于表示售出的图书数量
				//double，用于表示图书的售出价格
	sale_data(std::istream &); //构造函数istream&，用于读取一条交易信息

	//关于sale_data对象的操作
	//成员函数体
	std::string isbn() const {return bookNo; }
	//紧随参数列表后的const关键字作用是修改隐式this指针的类型
	//isbn()则为常量成员函数
	sale_data& combine(const sale_data);

private:
	double avg_price() const;
	
	//数据成员
	std::string bookNo;	//表示ISBN编号
	unsigned units_sold =0;	//表示本书销量
	double revenue = 0.0;	//表示本书总销售收入

};

//sale_data的非成员接口函数,与类相关的辅助函数
//将运算定义为普通函数，执行加法和IO的函数不作为类的成员
//执行复合赋值运算的函数是成员函数，如combine函数
sale_data add(const sale_data&, const sale_data&);
std::ostream &print(std::ostream&, const sale_data&);
std::istream &read(std::istream&, sale_data&);

//在类的外部定义构造函数istream
//用于读取一条交易信息
sale_data::sale_data (std::istream &is) //该成员名字和类名相同，所以他是一个constructor
{
	read(is, *this);
	//read函数表示从is中读取一条交易信息然后存入this对象中去
	//没有构造函数初始值列表，但因为执行了函数体，所以成员仍然可以被初始化
}






