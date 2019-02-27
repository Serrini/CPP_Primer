#include <iostream>
using std::ceer; using std::cin; using std::cout; using std::endl;
#include "sale_data.h"

int main(){
	sale_data toatal; //total是保存当前求和结果的变量
	if (read(cin, trans))
	{
		sale_data trans; //trans是保存下一次交易数据的变量
		while(read(cin, trans)){
			if (total.isbn() == trans.isbn()) 
			{
				//如果还是当前这一本书
				total.combine(trans); //更新total
			}else{
				print(cout, total) << endl; //输出结果
				total = trans; //处理下一本书
			}
		}
		print(cout, total) << endl; //退出while循环后输出最后一条交易
	}else{
		cerr << "No Data?!" << endl;
		//通知用户没有数据输入
	}
}