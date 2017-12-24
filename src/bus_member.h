using namespace std;
//班车类成员函数 
void Bus::buildbus(){
	bus_data bs;
	cout << "新增车辆，请录入信息："<< endl << endl; 
	cout << "请输入车牌号："; 	     cin >> bus_number;        bs.bus[bs.i].set_num(bus_number);//同时全部放入对象数组 
	cout << endl <<"请输入车型号："; cin >> model;             bs.bus[bs.i].set_model(model);
	cout << endl << "请输入司机姓名：";  cin >> driver_name;   bs.bus[bs.i].set_name(driver_name);
	cout << endl << "请输入载乘人数：";  cin >> limiters;      bs.bus[bs.i].set_limiters(limiters);
	cout << endl << "请输入运行时间段：";  cin >> time_section;bs.bus[bs.i].set_section(time_section);
	for(int j=0;j<N;j++){ 
	   cout << endl << "请输入第"<<j+1<<"班次预计发车时间：";  cin >> startime[j][0];
	   cout << endl << "请输入第"<<j+1<<"班次预计到达时间：";  cin >> endtime[j][0]; 
	   float x=(float)(endtime[j][0]-startime[j][0])/(N+1);
       for(int q=1;q<N+1;q++){
           endtime[j][q]=startime[j][0]+x*q;//根据输入时间段，初始化每个站点的到达和离开时间 
           startime[j][q]=endtime[j][q];
	   }
	} //计算停车点时间 
	for(int j=0;j<N;j++)
	    for(int q=1;q<N+1;q++){
           startime[j][q]=((int)(startime[j][q]*10+0.5))/10.0;
           endtime[j][q]=((int)(startime[j][q]*10+0.5))/10.0;
       }//保留一位小数 
    //放入对象数组 
	bs.bus[bs.i].set_startime(startime);
	bs.bus[bs.i].set_endtime(endtime);
	for(int j=0;j<N;j++){
        passengers[j]=0;
        now_passengers[j]=0;
        station[j]=0; 
        for(int k=0;k<N+1;k++){
		r_startime[j][k]=0;
		r_endtime[j][k]=0;  }  
	}//初始化乘客数量，站点，实际出发和到达时间 
	//放入对象数组： 
	bs.bus[bs.i].set_station(station);
	bs.bus[bs.i].set_passengers(passengers);
	bs.bus[bs.i].set_r_startime(r_startime);
	bs.bus[bs.i].set_r_endtime(r_endtime); 
	bs.i++;
    cout << endl << "新增班车成功！"<< endl << endl;
}//新增班车 

void Bus::show()
{   bus_data bs;
    int i=bs.search_bus();//寻找班车，返回数组下标 
    if(i==-1) return;
    cout << "班车信息："<< endl; 
	cout << "此班车的预定运行时刻表为："<< endl; 
	for(int j=0;j<N;j++){ 
	cout <<endl<<endl; 
	cout << "—————————————————" <<endl;
	cout << "                班次"<<j+1<<endl;
	cout << "—————————————————" <<endl;
	cout << "运行时间段       |"<<"     "<<bs.bus[i].get_section()<<endl;
	cout << "—————————————————" <<endl;
	cout << "发车时间         |"<<"     "<<bs.bus[i].startime[j][0]<<endl;
	cout << "—————————————————" <<endl;
	for(int k=1;k<N+1;k++){ 
	cout << "停车点"<<k<<"到达时间  |"<<"     "<<setprecision(2)<<bs.bus[i].endtime[j][k]<<endl;
	cout << "—————————————————" <<endl;
	cout << "停车点"<<k<<"离开时间  |"<<"     "<<setprecision(2)<<bs.bus[i].startime[j][k]<<endl;
	cout << "—————————————————" <<endl;
	}
	cout << "收车时间         |"<<"     "<<bs.bus[i].endtime[j][0]<<endl;
	cout << "—————————————————" <<endl;
	cout << "全程运行时间     |"<<"     "<<bs.bus[i].endtime[j][0]-bs.bus[i].startime[j][0]<<endl;
	cout << "—————————————————" <<endl;} 
	cout << "车牌号:  " << bs.bus[i].get_num()   <<endl;
	cout << "车型号:  " << bs.bus[i].get_model() <<endl;
	cout << "司机  :  " << bs.bus[i].get_name()  <<endl;
	int q;
	//输入实际每个站点的时间 
	for(int p=0;p<N;p++){ 
	   cout << endl << "请输入本车第"<<p+1<<"班次实际发车时间：";          cin >> r_startime[p][0];
	   for(q=1;q<N+1;q++){
	       cout << endl << "请输入本班次第"<<q<<"个停车点实际离开时间：";  cin >> r_startime[p][q]; }
	   cout << endl << "请输入本车第"<<p+1<<"班次实际收车时间：";          cin >> r_endtime[p][0]; 
	   for(q=1;q<N+1;q++){
	       cout << endl << "请输入本班次第"<<q<<"个停车点实际到达时间：";  cin >> r_endtime[p][q]; }}
    //放入对象数组 
	bs.bus[i].set_r_startime(r_startime); 
	bs.bus[i].set_r_endtime(r_endtime);
	bs.bus[i].ontime_rate();//计算准时率 
}//显示信息 

void Bus::ontime_rate(){
	int j,q,k=0,m=0,n=0;
	for(j=0;j<N;j++){
		for(q=0;q<N+1;q++){
	       if(startime[j][q]==r_startime[j][q])
	       k++;//发车时间相同的车的数量 
	       if(endtime[j][q]==r_endtime[j][q])
	       m++;}//到达时间相同的车的数量
	}
	for(j=0;j<N;j++)
	   n=n+passengers[j];//实际乘客数量 
	float r=N*(N+1);//总共的时间点 
    float start=k/r;
    float end=m/r;
	cout <<endl<< "本辆车的发车准时率为：" << start*100<<"%"<<endl;
	cout <<endl<< "本辆车的按时到达率为：" << end*100<<"%"<<endl;
	cout <<endl<< "本辆车实际乘车人数与载乘人数比为：" <<n<<"/"<<(N*limiters)<<endl;
}//计算 

//班车管理类成员函数： 
bus_data::bus_data(){
	i=0;//初始化为零 
	Bus cd;	
	fstream file("bus.txt",ios::in);
	while(1){
         file.read((char*)&cd,sizeof(cd));//从文件读取对象 
         if(!file) break; 
           bus[i]=cd;i++; }//放入对象数组 
	file.close();
}//构造函数（读取文件数据）

int bus_data::search_bus(){ 
    int bus_number;
    cout << "请输入车牌号："; cin >> bus_number;cout << endl; 
    int j;
	for(j=0;j<i;j++){
	   if(bus[j].get_num()==bus_number)//按车牌号寻找 
    	  return j; }//返回数组下标 
    if(j==i){
	   cout << " 此车不存在！"<<endl; return -1;
    }	  
}//搜索班车 

//车按照从起点站开始的顺序依次刷卡，到终点站不显示，下次刷卡直接显示起点站，
//已经上车还没下车的人不能刷卡 ，等到下车后再输 
int bus_data::select_bus(int j,int k,int s){//传入卡类对象数组下标，车类对象数组下标，以及下车人数 
	 int a[N],b[N],c[N];//三个辅助数组 
	 if(bus[j].get_station()[k-1]==0){//若为起点站 
	 	cout << endl << "此站为起点站,当前车上乘客数  ： 0" << endl;
	 	//刷新乘客信息，站点加一，赋给辅助数组 
	 	for(int t=0;t<N;t++){
           if(t==k-1){
	 	     a[t]=bus[j].get_now_passengers()[k-1]+1;
		     b[t]=bus[j].get_passengers()[k-1]+1;
	         c[t]=bus[j].get_station()[k-1]+1;  }
		else {
	         a[t]=bus[j].get_now_passengers()[t];
	         b[t]=bus[j].get_passengers()[t];
		     c[t]=bus[j].get_station()[t]; }
		}
	 //放入对象数组： 
	 bus[j].set_now_passengers(a);
 	 bus[j].set_passengers(b);
	 bus[j].set_station(c); 
	 return 0;
	 }
	 if(bus[j].get_station()[k-1]==1||bus[j].get_station()[k-1]==2){//如果是其他站点 
	 	   for(int t=0;t<N;t++){
             if(t==k-1){
	 	        a[t]=bus[j].get_now_passengers()[k-1]-=s;}
	 	     else { a[t]=bus[j].get_now_passengers()[t];} 
		   }//刷新当前乘客信息，放入辅助数组 
	 	   //放入对象数组： 
	 	   bus[j].set_now_passengers(a);
	       if(bus[j].get_limiters()<=bus[j].get_now_passengers()[k-1]){//如果乘客已满 
	          cout <<endl<< "此辆车已载满，请下车！"<< endl; 
		   return -1; }
	 	   cout << endl << "此站为第"<<bus[j].get_station()[k-1]<<"站,"<<"当前车上乘客数:" <<bus[j].get_now_passengers()[k-1]<< endl;
	 	   for(int t=0;t<N;t++){
              if(t==k-1){
	 	         a[t]=bus[j].get_now_passengers()[k-1]+1;
		         b[t]=bus[j].get_passengers()[k-1]+1;
		         c[t]=bus[j].get_station()[k-1]+1; }
	          else {
	             a[t]=bus[j].get_now_passengers()[t];
	             b[t]=bus[j].get_passengers()[t];
		         c[t]=bus[j].get_station()[t]; }
		    }//刷新当前乘客信息，放入辅助数组 
		   //放入对象数组：
	       bus[j].set_now_passengers(a);
	       bus[j].set_passengers(b);
	       bus[j].set_station(c);
	 return 0;} 
	 if(bus[j].get_station()[k-1]==3) {//如果是终点站 
		    for(int q=0;q<N;q++){
		   	   if(q==k-1){ 
			     a[q]=0; b[q]=0; }
		   	   else {
		   	     a[q]=bus[j].get_now_passengers()[q];
		   	     b[q]=bus[j].get_station()[q]; }
		   }//所有信息归零 
		   //放入对象数组 
		   bus[j].set_now_passengers(a);
		   bus[j].set_station(b);
		   cout<<endl<<"此站是终点站！"<<endl; 
	 return -2;}
}//上车刷卡之前 

bus_data::~bus_data(){
    ofstream file("bus.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&bus[j],sizeof(bus[j])); }//重新将数组信息写入文件 
	file.close();	
}//析构函数（结束时写入刷新后的数据）
