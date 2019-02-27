#include <iostream>
using std::istream; using std::ostream;
#include "sale_data.h"

//使用avg_price成员函数
double
sale_data::avg_price() const{
	if (units_sold)
	{
		return revenue/units_sold;
	}else{
		return 0;
	}
}

//定义combine函数
sale_data&
sale_data::combine(const sale_data $rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this; //返回调用该函数的对象
}

//定义read函数和print函数
//IO类型不能拷贝，引用来传递，read和print操作会改变内容，所以是普通引用而非对常量的引用
istream&
read(istream &is, sale_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	//读入ISBN、销售数量和单价,读入到is中去
	item.revenue = price * item.units_sold;
	return is;
}

ostream&
print(ostream &os, const sale_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

sale_data
add(const sale_data &lhs, const sale_data &rhs)
{
	sale_data sum = lhs; //定义一个sale_data的对象sum，并用lhs的副本初始化sum
	sum.combine(rhs); //调用combine函数，将rhs的units_sold和revenue添加给sum
	return sum; //函数返回sum的副本
}