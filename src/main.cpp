#include<iostream>
#include<fstream>
#include<string.h> 
#include<stdlib.h>
#include <iomanip>
#include <time.h>
#include"bus.h"
#include"bus_member.h"//班车类成员函数 
#include"people.h"
#include"card.h"
#include"card_member.h"//卡类成员函数 
#include"people_member.h"//人类成员函数 
#include"fuction.h"//界面等函数 
using namespace std;
//主函数： 
int main()
{
	int in;
	Bus bus; 
	do{ 
		show1();
	    cin >> in; cout << endl;
	    system("cls");//清屏 
		switch(in)
		{
		case 1: 
			{ build();//新增卡 
			break;}
		case 2:
			{ Delete();//删除卡 
			break;}	
		case 3:
			{ Rechange();//充值卡 
			break;}
		case 4:
	     	{ use();//刷卡 
			break;}
		case 5:
			{ bus.buildbus();//新增班车 
			break;}
		case 6:
		    { bus.show();//班车信息 
			break;}	
	    case 7:
		    { people p;
			  p.show();//人信息 
			break;}	
		case 8:
			break;
		default:
			cout << "输入错误！请重新输入" << endl << endl << endl; 
		}
	}while(in!=8);
	return 0;
} 
