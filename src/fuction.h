//���������ʵ�� 
void show1(){
	cout << "*******    ��ӭʹ��һ��ͨ�˳�ϵͳ!   *******" << endl;
	cout << endl;
	cout << "********        1  �½���           ********" << endl;
	cout << "********        2  ע����           ********" << endl;
	cout << "********        3  ��ֵ             ********" << endl;
	cout << "********        4  ˢ���˳�         ********" << endl;
	cout << "********        5  �����೵         ********" << endl;
	cout << "********        6  ��ѯ�೵��Ϣ     ********" << endl;
	cout << "********        7  ��ѯ������Ϣ     ********" << endl;
	cout << "********        8  �˳�             ********" << endl;
	cout << endl << endl << endl;
	cout << "��ѡ�����֣�"; 
}//����

void show2()
{
	cout << "******** ��ѡ����ʹ�õ�һ��ͨ���� *****" << endl << endl;
	cout << "********        1 ��ʦ��       ********" << endl;
	cout << "********        2 ѧ����       ********" << endl;
	cout << "********        3 ���ƿ�       ********" << endl << endl;
	cout << "********        4 ����         ********" << endl;
	cout << endl << endl << endl;
	cout << "��ѡ�����֣�"; 
}//���� 

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
			cout << "�����������������" << endl << endl << endl; 
		}
}//ˢ�� 

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
			cout << "�����������������" << endl << endl << endl; 
		}
}//��ֵ 

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
			cout << "�����������������" << endl << endl << endl; 
		}
}//ע���� 

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
			cout << "�����������������" << endl << endl << endl; 
		}
}//�½���
