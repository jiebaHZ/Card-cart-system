using namespace std;
//人类的成员函数： 
void people::buildTcard(){
	Tcard_data tcd;
	int card_number;//辅助变量 
	char end_date[20];//辅助数组 
	cout << "新建一卡通，请录入信息："<< endl << endl;
	cout << "请输入卡号："; 	     cin >> card_number;  tcd.card[tcd.i].set_num(card_number);//放入对象数组 
	cout << endl << "请输入姓名：";  cin >> name;         tcd.card[tcd.i].set_name(name);
	cout << endl << "请输入工资号/学号："; cin >> ID;     tcd.card[tcd.i].set_ID(ID);
	cout << endl << "请输入单位：";  cin >> unit;         tcd.card[tcd.i].set_unit(unit);
	cout << endl << "请输入有效期：";cin >> end_date;     tcd.card[tcd.i].set_end_date(end_date);
	tcd.card[tcd.i].set_times(0);//初始化总乘车次数 
	tcd.i++;
	buildpeople();//创建人的信息 
	cout << endl << "创建成功！"<< endl<< endl ;
}//新建教师卡 

void people::buildScard(){
	Scard_data scd;
	int card_number,balance;//辅助变量 
	char end_date[20];//辅助数组 
	cout << "新建一卡通，请录入信息："<< endl << endl;
	cout << "请输入卡号："; 	     cin >> card_number;  scd.card[scd.i].set_num(card_number);//放入对象数组
	cout << endl << "请输入姓名：";  cin >> name;         scd.card[scd.i].set_name(name);
	cout << endl << "请输入工资号/学号："; cin >> ID;     scd.card[scd.i].set_ID(ID);
	cout << endl << "请输入单位：";  cin >> unit;         scd.card[scd.i].set_unit(unit);
	cout << endl << "请输入有效期：";cin >> end_date;     scd.card[scd.i].set_end_date(end_date);
	cout << endl << "请输入充值钱数/元：";cin >> balance; scd.card[scd.i].set_balance(balance);
	scd.card[scd.i].set_times(0);//初始化总乘车次数 
    scd.i++;
	buildpeople();//创建人的信息
	cout << endl << "创建成功！"<< endl<< endl ;
}//新建学生卡 

void people::buildLcard(){
	Lcard_data lcd;
	int card_number,balance;//辅助变量
	char end_date[20];//辅助数组 
	cout << "新建一卡通，请录入信息："<< endl << endl;
	cout << "请输入卡号："; 	     cin >> card_number;  lcd.card[lcd.i].set_num(card_number);//放入对象数组
	cout << endl << "请输入姓名：";  cin >> name;         lcd.card[lcd.i].set_name(name);
	cout << endl << "请输入工资号/学号："; cin >> ID;     lcd.card[lcd.i].set_ID(ID);
	cout << endl << "请输入单位：";  cin >> unit;         lcd.card[lcd.i].set_unit(unit);
	cout << endl << "请输入有效期：";cin >> end_date;     lcd.card[lcd.i].set_end_date(end_date);
	cout << endl << "请输入充值钱数/元：";cin >> balance; lcd.card[lcd.i].set_balance(balance);
	lcd.card[lcd.i].set_times(0);//初始化总乘车次数
	lcd.i++;
	buildpeople();//创建人的信息 
	cout << endl << "创建成功！"<< endl<< endl;
}//新建限制卡 

void people::buildpeople(){
	people_data p;
	int k=p.search_p(ID);//在对象数组中搜索此人 
	if(k==-1){//如果没有此人，信息存入数组 
    p.person[p.i].set_name(name);
	cout << endl << "请输入性别：";  cin >> sex;      p.person[p.i].set_sex(sex);
    p.person[p.i].set_ID(ID);
    p.person[p.i].set_unit(unit);
	cout << endl << "请输入职务：";  cin >> business; p.person[p.i].set_business(business); 
	p.person[p.i].set_alltimes(0);
	p.person[p.i].set_amount(1);
	p.person[p.i].set_getoff(0);
	p.i++;}
	p.person[k].set_amount(p.person[k].card_amount+1); //此人卡的数量加一 
}//添加信息 

void people::deleteTcard(){
	 Tcard_data td; 
	 int j=td.search_card();//根据卡号寻找下标 
	 if(j==-1) return;
	 int a=td.card[j].get_ID();//根据工资号/学号寻找此人 
	 for(int k=j;k<td.i;k++)
	    td.card[k]=td.card[k+1];//数组向前移动一位 
	 td.i--;
	 cout << "注销成功！"<< endl<< endl;
     deletepeople(a);//选择是否删除人的信息 
}//删除数组中的信息  

void people::deleteScard(){
	 Scard_data sd; 
	 int j=sd.search_card();//根据卡号寻找下标
	 if(j==-1) return;
	 int a=sd.card[j].get_ID();//根据工资号/学号寻找此人 
	 for(int k=j;k<sd.i;k++)
	    sd.card[k]=sd.card[k+1];//数组向前移动一位 
	 sd.i--; 
	 cout << "注销成功！"<< endl<< endl;
     deletepeople(a);//选择是否删除人的信息
}//删除数组中的信息 

void people::deleteLcard(){
	 Lcard_data ld; 
	 int j=ld.search_card();//根据卡号寻找下标
	 if(j==-1) return;
	 int a=ld.card[j].get_ID();//根据工资号/学号寻找此人
	 for(int k=j;k<ld.i;k++)
	    ld.card[k]=ld.card[k+1];//数组向前移动一位 
	 ld.i--; 
	 cout << "注销成功！"<< endl<< endl;
     deletepeople(a);//选择是否删除人的信息
}//删除数组中的信息 

void people::deletepeople(int a){//传入工资号/学号 
	 people_data p;
	 int k=p.search_p(a);//寻找数组下标 
	 p.person[k].card_amount-=1;//卡数量减一 
	 if(p.person[k].card_amount==0){//如果卡数量为0 
	   cout << "您当前一卡通数量为0,是否注销个人信息，请选择" << endl << endl;
	   cout <<  "          1 是     2 否                    " << endl; 
	   int x; cin >> x;
       if(x==1){
	     for(int j=k;j<p.i;j++)
	        p.person[j]=p.person[j+1];//数组向前移动一位 
	   p.i--;}
	   else return; }
}//删除人的信息 

void people::alltimes(){
     all_times+=1; 
}//总次数加一 

void people::show(){
	int id;
	cout << endl << "请输入工资号/学号："; cin >> id;
	people_data p;
	int j=p.search_p(id);//选择数组下标 
	if(j==-1) {   cout << "此人不存在！"<<endl; return;}
	cout << endl << "个人信息如下："<<endl;
	cout << endl << "姓名："<<p.person[j].name;
	cout << endl << "性别："<<p.person[j].sex;
	cout << endl << "工资号/学号："<<p.person[j].ID;
	cout << endl << "单位："<< p.person[j].unit;
	cout << endl << "职务："<< p.person[j].business; 
	cout << endl << "总乘车次数："<< p.person[j].all_times;
	cout << endl << "卡数量："<< p.person[j].card_amount;cout<<endl;
}

people_data::people_data(){
	i=0;//初始化为零 
	people p;	
	fstream file("people.txt",ios::in);
	while(1){
        file.read((char*)&p,sizeof(p));//读取文件对象 
        if(!file) break; 
          person[i]=p;i++; }//放入数组 
	file.close();
}//构造函数（读取文件数据）

int people_data::search_p(int id){//传入工资号/学号 
	int j;
	for(j=0;j<i;j++)
	   if(person[j].get_ID()==id)
	      return j;//返回下标 
	if(j==i){
	      return -1;
    }    
}//查找人

int people_data::get_off(int s){//传入站点 
	 int k=0;
	 for(int q=0;q<i;q++)
	 	  if(person[q].get_getoff()==s){
	 	    k++;  //统计此站下车人数 
            person[q].set_getoff(0);}//修改下车的人的下车点信息 ，置零 
    return k;
}//下车人数 

void people_data::set_get_off(int j,int a){//传入持卡人工资号/学号，下车点 
	 int k=search_p(j);//寻找对象数组下标 
	 person[k].set_getoff(a);//修改下车点 
}//产生下车点 

void people_data::update_alltimes(int id){
	 int j=search_p(id);
     person[j].alltimes();//乘车总次数加一 
}//总次数加一 

int people_data::status(int id){
	int j=search_p(id);
	if(person[j].get_getoff()!=0){
		cout<<endl<<"此人在车上！"<<endl;
		return -1; 
	}
	return 0;
}//判断此人是否在车上 

void people_data::setall(){
	for(int j=0;j<i;j++)
	   person[j].set_getoff(0);
} //全部初始化为零 

people_data::~people_data(){
    ofstream file("people.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&person[j],sizeof(person[j])); }//重新写入文件 
	file.close();	
}//析构函数 
