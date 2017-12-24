using namespace std;
//教师类成员函数 ：
int Tcard::usecard(people_data &p){
	 int j=p.status(ID);
	 if(j==0){
	 take_times+=1;//乘车次数加一 
	 p.update_alltimes(ID);//人的总乘车次数加一 
	 return 0;}
	 else return -1;
}//教师卡使用情况 

void Tcard::showcard(bus_data &bus){
	Tcard_data tcd;
	people_data p;
	int j=tcd.search_card();//按卡号寻找，返回对象数组下标 
	if(j==-1) return; //无此卡则跳出 
	int q=bus.search_bus();//按车牌号寻找，返回对象数组下标 
	if(q==-1) return;//无此车则跳出 
	int k;//班次 
	cout << "请输入所乘车班次：";  cin >> k;
	int s=bus.get_bus()[q].get_station()[k-1];//本站 
	s=p.get_off(s);//统计本站下车人数 
	q=bus.select_bus(q,k,s);//显示当前车上人数  
	if(q!=-1 && q!=-2){ //如果未满载且未上车，则刷卡 
	  int s=tcd.card[j].usecard(p);
      if(s==-1) return ;}
	else {
		if(q==-2)//如果到终点站，所有人下车点变为0 
		   p.setall(); 
	    return;}//否则不能刷卡 
	cout << endl << "一卡通最新信息如下： " << endl << endl ; 
	//从对象数组中提取输出 
    cout << "卡主姓名： " <<  tcd.card[j].get_name() << endl;
    cout << "本卡卡号： " <<  tcd.card[j].get_num()  << endl;
    cout << "单    位： " <<  tcd.card[j].get_unit() << endl;
    cout << "卡    种： " << "教师卡" << endl;
    cout << "乘车次数： " <<  tcd.card[j].get_times()<< endl;
    cout << "有效期  ： " <<  tcd.card[j].get_end_date() << endl << endl << endl;
    //随机产生一个下车点 
	srand(time(0));
	int a=rand()%(N+1)+1;
	if(a==N+1) cout << "将在终点下车"<<endl<<endl;
	else cout << "将在停车点"<<a<<"下车"<<endl<<endl;
	p.set_get_off(tcd.card[j].get_ID(),a);//将产生的下车点存入人的信息里 
}//输出 

//学生类成员函数： 
int Scard::usecard(people_data &p){
	 int j=p.status(ID);
	 if(j==0){
      if(balance<2){//若余额小于2，则不允许上车 
        cout << "您的余额不足，请充值后使用！" << endl; 
      return -1; }
      else{
           balance-=2;//余额减二 
           take_times+=1;//次数加一 
           p.update_alltimes(ID);//人的总乘车次数加一
          if (balance<=5){//余额小于5提示充值 
             cout << "您的余额过低，请及时充值!" << endl; }
          return 0;
      }
   }
   else return -1;
}//学生卡使用情况 

void Scard::showcard(bus_data &bus){
	Scard_data scd;
	people_data p;
	int j=scd.search_card();//按卡号寻找，返回对象数组下标 
	if(j==-1) return; //无此卡则跳出
	int q=bus.search_bus();//按车牌号寻找，返回对象数组下标 
	if(q==-1) return;//无此车则跳出 
	int k;//班次 
	cout << "请输入所乘车班次：";  cin >> k;
    int s=bus.get_bus()[q].get_station()[k-1];//本站 
	s=p.get_off(s);//统计本站下车人数 
	q=bus.select_bus(q,k,s);//显示当前车上人数  
	if(q!=-1 && q!=-2){//如果未满载，则刷卡
	  int s=scd.card[j].usecard(p);
	  if(s==-1) return;}
	else {
		if(q==-2)//如果到终点站，所有人下车点变为0
		   p.setall(); 
	    return;}//否则不能刷卡
	cout << endl << "一卡通最新信息如下： " << endl << endl ;
	//从对象数组中提取输出
    cout << "卡主姓名： " <<  scd.card[j].get_name() << endl;
    cout << "本卡卡号： " <<  scd.card[j].get_num()  << endl;
    cout << "单    位： " <<  scd.card[j].get_unit() << endl;
    cout << "卡    种： " << "学生卡" << endl;
    cout << "卡内余额： " <<  scd.card[j].get_balance() << endl;
    cout << "乘车次数： " <<  scd.card[j].get_times()   << endl;
    cout << "有效期  ： " <<  scd.card[j].get_end_date()   << endl << endl << endl;
    //随机产生一个下车点
	srand(time(0));
	int a=rand()%(N+1)+1;
	if(a==N+1) cout << "将在终点下车"<<endl<<endl;
	else cout << "将在停车点"<<a<<"下车"<<endl<<endl;
	p.set_get_off(scd.card[j].get_ID(),a);//将产生的下车点存入人的信息里 
}//输出 

//限制类成员函数 
int Lcard::usecard(people_data &p){
	 int j=p.status(ID);
	 if(j==0){
      if (take_times<20){//乘车次数小于二十，不收费 
          take_times+=1;
          p.update_alltimes(ID);//人的总乘车次数加一
      return 0;}
      if (balance<2){//余额小于2，不允许上车 
            cout << "您的余额不足，请充值后使用！"; 
      return -1;}
      else{
           balance-=2;//余额减二 
           take_times+=1;
           p.update_alltimes(ID);//人的总乘车次数加一
        if (balance<=5){//余额小于5提示充值 
            cout << "余额过低，及时充值!"; 
		return 0;}
      }
  }
  else return -1;
}//限制卡使用情况  

void Lcard::showcard(bus_data &bus){
	Lcard_data lcd;
	people_data p;
	int j=lcd.search_card();//按卡号寻找，返回对象数组下标 
	if(j==-1) return; //无此卡则跳出
	int q=bus.search_bus();//按车牌号寻找，返回对象数组下标
	if(q==-1) return;
	int k;//班次 
	cout << "请输入所乘车班次：";  cin >> k;
	int s=bus.get_bus()[q].get_station()[k-1];//本站 
	s=p.get_off(s);//统计本站下车人数 
	q=bus.select_bus(q,k,s);//显示当前车上人数 
	if(q!=-1 && q!=-2){//如果未满载，则刷卡
	  int s=lcd.card[j].usecard(p);
	  if(s==-1) return ;}
	else {
		if(q==-2)//如果到终点站，所有人下车点变为0
		   p.setall(); 
	    return;}//否则不能刷卡
	cout << endl << "一卡通最新信息如下： " << endl << endl ;
	//从对象数组中提取输出
    cout << "卡主姓名： " <<  lcd.card[j].get_name() << endl;
    cout << "本卡卡号： " <<  lcd.card[j].get_num()  << endl;
    cout << "单    位： " <<  lcd.card[j].get_unit() << endl;
    cout << "卡    种： " << "限制卡" << endl;
    cout << "卡内余额： " <<  lcd.card[j].get_balance() << endl;
    cout << "乘车次数： " <<  lcd.card[j].get_times()   << endl;
    cout << "有效期  ： " <<  lcd.card[j].get_end_date()   << endl << endl << endl;
    if (lcd.card[j].get_times()==20)//第二十次提示下次开始要收费 
	   cout << "这是本月最后一次免费乘车" << endl << endl << endl;
    if (lcd.card[j].get_times()>20) 
	   cout << "这是本月第" << lcd.card[j].get_times() << "次乘车，本次收费2元。" << endl << endl;   
	//随机产生一个下车点
	srand(time(0));
	int a=rand()%(N+1)+1;
	if(a==N+1) cout << "将在终点下车"<<endl<<endl;
	else cout << "将在停车点"<<a<<"下车"<<endl<<endl;  
	p.set_get_off(lcd.card[j].get_ID(),a);//将产生的下车点存入人的信息里 
}//输出 

//教师卡信息管理类成员函数：
Tcard_data::Tcard_data(){
	i=0;//初始化为零 
	Tcard cd;	
	fstream file("teacher.txt",ios::in);
	while(1){
         file.read((char*)&cd,sizeof(cd));
         if(!file) break; 
           card[i]=cd;i++; }//从文件中把对象读取到数组中 
	file.close();
}//构造函数（读取文件数据）

int Tcard_data::search_card(){ 
    int card_num;
    cout << endl << "请输入卡号："; cin >> card_num; cout << endl;
    int j;
	for(j=0;j<i;j++)
	   if(card[j].get_num()==card_num)//在对象数组中寻找下标 
    	  return j;//返回下标 
    if(j==i){
	   cout << " 此卡不存在！"<<endl; return -1;
    }	  
}//在文件中搜索要查询的卡号 

Tcard_data::~Tcard_data(){
    ofstream file("teacher.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&card[j],sizeof(card[j])); }//重新把数组的信息写回文件 
	file.close();	
}//析构函数（结束时写入刷新后的数据） 

//学生卡信息管理类成员函数：
Scard_data::Scard_data(){
	i=0;//初始化为零
	Scard cd;	
	fstream file("student.txt",ios::in);
	while(1){
        file.read((char*)&cd,sizeof(cd));
        if(!file) break; 
          card[i]=cd;i++; }//从文件中把对象读取到数组中
	file.close();
}//构造函数（读取文件数据）

int Scard_data::search_card(){
	int card_num;
	cout << endl << "请输入卡号："; cin >> card_num;cout << endl;
	int j;
	for(j=0;j<i;j++)
	   if(card[j].get_num()==card_num)//在对象数组中寻找下标
	      return j;//返回下标 
	if(j==i){
	   cout << " 此卡不存在！"<<endl; return -1;
    }
}//在文件中搜索要查询的卡号 

void Scard_data::rechange(){
    int j=search_card();//寻找数组下标 
    if(j==-1) return;
	cout << endl << "请输入充值钱数/元："; int a; cin >> a;
    card[j].set_balance(card[j].get_balance()+a);//改变余额信息 
    cout << endl << "充值成功！"<< endl;
}//充值

Scard_data::~Scard_data(){
    ofstream file("student.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&card[j],sizeof(card[j])); }//重新把数组的信息写回文件
	file.close();	
}//析构函数（结束时写入刷新后的数据）

//限制卡信息管理类成员函数：
Lcard_data::Lcard_data(){
	i=0;//初始化为零 
	Lcard cd;	
	fstream file("limit.txt",ios::in);
	while(1){
        file.read((char*)&cd,sizeof(cd));
        if(!file) break; 
          card[i]=cd;i++; }//从文件中把对象读取到数组中
	file.close();
}//构造函数（读取文件数据）

int Lcard_data::search_card(){
	int card_num;
	cout << endl << "请输入卡号："; cin >> card_num;cout << endl;
	int j;
	for(j=0;j<i;j++)
	   if(card[j].get_num()==card_num)//在对象数组中寻找下标
	      return j;//返回下标
	if(j==i){
	   cout <<" 此卡不存在！"<<endl; return -1;
    }    
}//在文件中搜索要查询的卡号 

void Lcard_data::rechange(){
    int j=search_card();//寻找数组下标
    if(j==-1) return;
	cout << endl << "请输入充值钱数/元：";
	int a; cin >> a;
    card[j].set_balance(card[j].get_balance()+a);//改变余额信息 
	cout << endl << "充值成功！"<< endl;
}//充值

Lcard_data::~Lcard_data(){
    ofstream file("limit.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&card[j],sizeof(card[j])); }//重新把数组的信息写回文件
	file.close();	
}//析构函数（结束时写入刷新后的数据）
