using namespace std;
//�೵���Ա���� 
void Bus::buildbus(){
	bus_data bs;
	cout << "������������¼����Ϣ��"<< endl << endl; 
	cout << "�����복�ƺţ�"; 	     cin >> bus_number;        bs.bus[bs.i].set_num(bus_number);//ͬʱȫ������������� 
	cout << endl <<"�����복�ͺţ�"; cin >> model;             bs.bus[bs.i].set_model(model);
	cout << endl << "������˾��������";  cin >> driver_name;   bs.bus[bs.i].set_name(driver_name);
	cout << endl << "�������س�������";  cin >> limiters;      bs.bus[bs.i].set_limiters(limiters);
	cout << endl << "����������ʱ��Σ�";  cin >> time_section;bs.bus[bs.i].set_section(time_section);
	for(int j=0;j<N;j++){ 
	   cout << endl << "�������"<<j+1<<"���Ԥ�Ʒ���ʱ�䣺";  cin >> startime[j][0];
	   cout << endl << "�������"<<j+1<<"���Ԥ�Ƶ���ʱ�䣺";  cin >> endtime[j][0]; 
	   float x=(float)(endtime[j][0]-startime[j][0])/(N+1);
       for(int q=1;q<N+1;q++){
           endtime[j][q]=startime[j][0]+x*q;//��������ʱ��Σ���ʼ��ÿ��վ��ĵ�����뿪ʱ�� 
           startime[j][q]=endtime[j][q];
	   }
	} //����ͣ����ʱ�� 
	for(int j=0;j<N;j++)
	    for(int q=1;q<N+1;q++){
           startime[j][q]=((int)(startime[j][q]*10+0.5))/10.0;
           endtime[j][q]=((int)(startime[j][q]*10+0.5))/10.0;
       }//����һλС�� 
    //����������� 
	bs.bus[bs.i].set_startime(startime);
	bs.bus[bs.i].set_endtime(endtime);
	for(int j=0;j<N;j++){
        passengers[j]=0;
        now_passengers[j]=0;
        station[j]=0; 
        for(int k=0;k<N+1;k++){
		r_startime[j][k]=0;
		r_endtime[j][k]=0;  }  
	}//��ʼ���˿�������վ�㣬ʵ�ʳ����͵���ʱ�� 
	//����������飺 
	bs.bus[bs.i].set_station(station);
	bs.bus[bs.i].set_passengers(passengers);
	bs.bus[bs.i].set_r_startime(r_startime);
	bs.bus[bs.i].set_r_endtime(r_endtime); 
	bs.i++;
    cout << endl << "�����೵�ɹ���"<< endl << endl;
}//�����೵ 

void Bus::show()
{   bus_data bs;
    int i=bs.search_bus();//Ѱ�Ұ೵�����������±� 
    if(i==-1) return;
    cout << "�೵��Ϣ��"<< endl; 
	cout << "�˰೵��Ԥ������ʱ�̱�Ϊ��"<< endl; 
	for(int j=0;j<N;j++){ 
	cout <<endl<<endl; 
	cout << "����������������������������������" <<endl;
	cout << "                ���"<<j+1<<endl;
	cout << "����������������������������������" <<endl;
	cout << "����ʱ���       |"<<"     "<<bs.bus[i].get_section()<<endl;
	cout << "����������������������������������" <<endl;
	cout << "����ʱ��         |"<<"     "<<bs.bus[i].startime[j][0]<<endl;
	cout << "����������������������������������" <<endl;
	for(int k=1;k<N+1;k++){ 
	cout << "ͣ����"<<k<<"����ʱ��  |"<<"     "<<setprecision(2)<<bs.bus[i].endtime[j][k]<<endl;
	cout << "����������������������������������" <<endl;
	cout << "ͣ����"<<k<<"�뿪ʱ��  |"<<"     "<<setprecision(2)<<bs.bus[i].startime[j][k]<<endl;
	cout << "����������������������������������" <<endl;
	}
	cout << "�ճ�ʱ��         |"<<"     "<<bs.bus[i].endtime[j][0]<<endl;
	cout << "����������������������������������" <<endl;
	cout << "ȫ������ʱ��     |"<<"     "<<bs.bus[i].endtime[j][0]-bs.bus[i].startime[j][0]<<endl;
	cout << "����������������������������������" <<endl;} 
	cout << "���ƺ�:  " << bs.bus[i].get_num()   <<endl;
	cout << "���ͺ�:  " << bs.bus[i].get_model() <<endl;
	cout << "˾��  :  " << bs.bus[i].get_name()  <<endl;
	int q;
	//����ʵ��ÿ��վ���ʱ�� 
	for(int p=0;p<N;p++){ 
	   cout << endl << "�����뱾����"<<p+1<<"���ʵ�ʷ���ʱ�䣺";          cin >> r_startime[p][0];
	   for(q=1;q<N+1;q++){
	       cout << endl << "�����뱾��ε�"<<q<<"��ͣ����ʵ���뿪ʱ�䣺";  cin >> r_startime[p][q]; }
	   cout << endl << "�����뱾����"<<p+1<<"���ʵ���ճ�ʱ�䣺";          cin >> r_endtime[p][0]; 
	   for(q=1;q<N+1;q++){
	       cout << endl << "�����뱾��ε�"<<q<<"��ͣ����ʵ�ʵ���ʱ�䣺";  cin >> r_endtime[p][q]; }}
    //����������� 
	bs.bus[i].set_r_startime(r_startime); 
	bs.bus[i].set_r_endtime(r_endtime);
	bs.bus[i].ontime_rate();//����׼ʱ�� 
}//��ʾ��Ϣ 

void Bus::ontime_rate(){
	int j,q,k=0,m=0,n=0;
	for(j=0;j<N;j++){
		for(q=0;q<N+1;q++){
	       if(startime[j][q]==r_startime[j][q])
	       k++;//����ʱ����ͬ�ĳ������� 
	       if(endtime[j][q]==r_endtime[j][q])
	       m++;}//����ʱ����ͬ�ĳ�������
	}
	for(j=0;j<N;j++)
	   n=n+passengers[j];//ʵ�ʳ˿����� 
	float r=N*(N+1);//�ܹ���ʱ��� 
    float start=k/r;
    float end=m/r;
	cout <<endl<< "�������ķ���׼ʱ��Ϊ��" << start*100<<"%"<<endl;
	cout <<endl<< "�������İ�ʱ������Ϊ��" << end*100<<"%"<<endl;
	cout <<endl<< "������ʵ�ʳ˳��������س�������Ϊ��" <<n<<"/"<<(N*limiters)<<endl;
}//���� 

//�೵�������Ա������ 
bus_data::bus_data(){
	i=0;//��ʼ��Ϊ�� 
	Bus cd;	
	fstream file("bus.txt",ios::in);
	while(1){
         file.read((char*)&cd,sizeof(cd));//���ļ���ȡ���� 
         if(!file) break; 
           bus[i]=cd;i++; }//����������� 
	file.close();
}//���캯������ȡ�ļ����ݣ�

int bus_data::search_bus(){ 
    int bus_number;
    cout << "�����복�ƺţ�"; cin >> bus_number;cout << endl; 
    int j;
	for(j=0;j<i;j++){
	   if(bus[j].get_num()==bus_number)//�����ƺ�Ѱ�� 
    	  return j; }//���������±� 
    if(j==i){
	   cout << " �˳������ڣ�"<<endl; return -1;
    }	  
}//�����೵ 

//�����մ����վ��ʼ��˳������ˢ�������յ�վ����ʾ���´�ˢ��ֱ����ʾ���վ��
//�Ѿ��ϳ���û�³����˲���ˢ�� ���ȵ��³������� 
int bus_data::select_bus(int j,int k,int s){//���뿨����������±꣬������������±꣬�Լ��³����� 
	 int a[N],b[N],c[N];//������������ 
	 if(bus[j].get_station()[k-1]==0){//��Ϊ���վ 
	 	cout << endl << "��վΪ���վ,��ǰ���ϳ˿���  �� 0" << endl;
	 	//ˢ�³˿���Ϣ��վ���һ�������������� 
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
	 //����������飺 
	 bus[j].set_now_passengers(a);
 	 bus[j].set_passengers(b);
	 bus[j].set_station(c); 
	 return 0;
	 }
	 if(bus[j].get_station()[k-1]==1||bus[j].get_station()[k-1]==2){//���������վ�� 
	 	   for(int t=0;t<N;t++){
             if(t==k-1){
	 	        a[t]=bus[j].get_now_passengers()[k-1]-=s;}
	 	     else { a[t]=bus[j].get_now_passengers()[t];} 
		   }//ˢ�µ�ǰ�˿���Ϣ�����븨������ 
	 	   //����������飺 
	 	   bus[j].set_now_passengers(a);
	       if(bus[j].get_limiters()<=bus[j].get_now_passengers()[k-1]){//����˿����� 
	          cout <<endl<< "�����������������³���"<< endl; 
		   return -1; }
	 	   cout << endl << "��վΪ��"<<bus[j].get_station()[k-1]<<"վ,"<<"��ǰ���ϳ˿���:" <<bus[j].get_now_passengers()[k-1]<< endl;
	 	   for(int t=0;t<N;t++){
              if(t==k-1){
	 	         a[t]=bus[j].get_now_passengers()[k-1]+1;
		         b[t]=bus[j].get_passengers()[k-1]+1;
		         c[t]=bus[j].get_station()[k-1]+1; }
	          else {
	             a[t]=bus[j].get_now_passengers()[t];
	             b[t]=bus[j].get_passengers()[t];
		         c[t]=bus[j].get_station()[t]; }
		    }//ˢ�µ�ǰ�˿���Ϣ�����븨������ 
		   //����������飺
	       bus[j].set_now_passengers(a);
	       bus[j].set_passengers(b);
	       bus[j].set_station(c);
	 return 0;} 
	 if(bus[j].get_station()[k-1]==3) {//������յ�վ 
		    for(int q=0;q<N;q++){
		   	   if(q==k-1){ 
			     a[q]=0; b[q]=0; }
		   	   else {
		   	     a[q]=bus[j].get_now_passengers()[q];
		   	     b[q]=bus[j].get_station()[q]; }
		   }//������Ϣ���� 
		   //����������� 
		   bus[j].set_now_passengers(a);
		   bus[j].set_station(b);
		   cout<<endl<<"��վ���յ�վ��"<<endl; 
	 return -2;}
}//�ϳ�ˢ��֮ǰ 

bus_data::~bus_data(){
    ofstream file("bus.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&bus[j],sizeof(bus[j])); }//���½�������Ϣд���ļ� 
	file.close();	
}//��������������ʱд��ˢ�º�����ݣ�
