#include<iostream>
#include<fstream>
#include<string.h> 
#include<stdlib.h>
#include <iomanip>
#include <time.h>
#include"bus.h"
#include"bus_member.h"//�೵���Ա���� 
#include"people.h"
#include"card.h"
#include"card_member.h"//�����Ա���� 
#include"people_member.h"//�����Ա���� 
#include"fuction.h"//����Ⱥ��� 
using namespace std;
//�������� 
int main()
{
	int in;
	Bus bus; 
	do{ 
		show1();
	    cin >> in; cout << endl;
	    system("cls");//���� 
		switch(in)
		{
		case 1: 
			{ build();//������ 
			break;}
		case 2:
			{ Delete();//ɾ���� 
			break;}	
		case 3:
			{ Rechange();//��ֵ�� 
			break;}
		case 4:
	     	{ use();//ˢ�� 
			break;}
		case 5:
			{ bus.buildbus();//�����೵ 
			break;}
		case 6:
		    { bus.show();//�೵��Ϣ 
			break;}	
	    case 7:
		    { people p;
			  p.show();//����Ϣ 
			break;}	
		case 8:
			break;
		default:
			cout << "�����������������" << endl << endl << endl; 
		}
	}while(in!=8);
	return 0;
} 
