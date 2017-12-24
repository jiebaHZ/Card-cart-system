//功能与界面实现 
void show1(){
	cout << "*******    欢迎使用一卡通乘车系统!   *******" << endl;
	cout << endl;
	cout << "********        1  新建卡           ********" << endl;
	cout << "********        2  注销卡           ********" << endl;
	cout << "********        3  充值             ********" << endl;
	cout << "********        4  刷卡乘车         ********" << endl;
	cout << "********        5  新增班车         ********" << endl;
	cout << "********        6  查询班车信息     ********" << endl;
	cout << "********        7  查询个人信息     ********" << endl;
	cout << "********        8  退出             ********" << endl;
	cout << endl << endl << endl;
	cout << "请选择数字："; 
}//界面

void show2()
{
	cout << "******** 请选择您使用的一卡通类型 *****" << endl << endl;
	cout << "********        1 教师卡       ********" << endl;
	cout << "********        2 学生卡       ********" << endl;
	cout << "********        3 限制卡       ********" << endl << endl;
	cout << "********        4 返回         ********" << endl;
	cout << endl << endl << endl;
	cout << "请选择数字："; 
}//界面 

void use(){
	int in;
	system("cls"); 
	show2();
	cin >> in; cout << endl;
	system("cls");
	switch(in){
		case 1: 
			{ Tcard Tcd;
			  bus_data bus; 
			  Tcd.showcard(bus);
			break;}
		case 2:
	     	{ Scard Scd;
	     	  bus_data bus; 
	     	  Scd.showcard(bus);
			break;}
		case 3:
	     	{ Lcard Lcd;
	     	  bus_data bus; 
              Lcd.showcard(bus);
			break;}
		case 4:
			break;
		default:
			cout << "输入错误！请重新输入" << endl << endl << endl; 
		}
}//刷卡 

void Rechange(){
    int in;
    system("cls"); 
	show2();
	cin >> in; cout << endl;
	system("cls");
	switch(in){
		case 1: 
			break;
		case 2:
	     	{  Scard_data scd;
			   scd.rechange();
			break;}
		case 3:
	     	{  Lcard_data lcd;
			   lcd.rechange();
			break;}
		case 4:
			break;
		default:
			cout << "输入错误！请重新输入" << endl << endl << endl; 
		}
}//充值 

void Delete(){
	int in;
	people p;
	system("cls"); 
	show2();
	cin >> in; cout << endl;
	system("cls");
	switch(in){
		case 1: 
			{  p.deleteTcard();  
			break;}
		case 2:
	     	{  p.deleteScard();
			break;}
		case 3:
	     	{  p.deleteLcard();   
			break;}
		case 4:
			break;
		default:
			cout << "输入错误！请重新输入" << endl << endl << endl; 
		}
}//注销卡 

void build(){
	int in;
	people p;
	system("cls"); 
	show2();
	cin >> in; cout << endl;
	system("cls");
	switch(in){
		case 1: 
			{  p.buildTcard();   
			break;}
		case 2:
	     	{  p.buildScard();
			break;}
		case 3:
			{  p.buildLcard();	   
			break;}
		case 4:
			break;
		default:
			cout << "输入错误！请重新输入" << endl << endl << endl; 
		}
}//新建卡
