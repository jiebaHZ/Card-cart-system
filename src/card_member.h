using namespace std;
//��ʦ���Ա���� ��
int Tcard::usecard(people_data &p){
	 int j=p.status(ID);
	 if(j==0){
	 take_times+=1;//�˳�������һ 
	 p.update_alltimes(ID);//�˵��ܳ˳�������һ 
	 return 0;}
	 else return -1;
}//��ʦ��ʹ����� 

void Tcard::showcard(bus_data &bus){
	Tcard_data tcd;
	people_data p;
	int j=tcd.search_card();//������Ѱ�ң����ض��������±� 
	if(j==-1) return; //�޴˿������� 
	int q=bus.search_bus();//�����ƺ�Ѱ�ң����ض��������±� 
	if(q==-1) return;//�޴˳������� 
	int k;//��� 
	cout << "���������˳���Σ�";  cin >> k;
	int s=bus.get_bus()[q].get_station()[k-1];//��վ 
	s=p.get_off(s);//ͳ�Ʊ�վ�³����� 
	q=bus.select_bus(q,k,s);//��ʾ��ǰ��������  
	if(q!=-1 && q!=-2){ //���δ������δ�ϳ�����ˢ�� 
	  int s=tcd.card[j].usecard(p);
      if(s==-1) return ;}
	else {
		if(q==-2)//������յ�վ���������³����Ϊ0 
		   p.setall(); 
	    return;}//������ˢ�� 
	cout << endl << "һ��ͨ������Ϣ���£� " << endl << endl ; 
	//�Ӷ�����������ȡ��� 
    cout << "���������� " <<  tcd.card[j].get_name() << endl;
    cout << "�������ţ� " <<  tcd.card[j].get_num()  << endl;
    cout << "��    λ�� " <<  tcd.card[j].get_unit() << endl;
    cout << "��    �֣� " << "��ʦ��" << endl;
    cout << "�˳������� " <<  tcd.card[j].get_times()<< endl;
    cout << "��Ч��  �� " <<  tcd.card[j].get_end_date() << endl << endl << endl;
    //�������һ���³��� 
	srand(time(0));
	int a=rand()%(N+1)+1;
	if(a==N+1) cout << "�����յ��³�"<<endl<<endl;
	else cout << "����ͣ����"<<a<<"�³�"<<endl<<endl;
	p.set_get_off(tcd.card[j].get_ID(),a);//���������³�������˵���Ϣ�� 
}//��� 

//ѧ�����Ա������ 
int Scard::usecard(people_data &p){
	 int j=p.status(ID);
	 if(j==0){
      if(balance<2){//�����С��2���������ϳ� 
        cout << "�������㣬���ֵ��ʹ�ã�" << endl; 
      return -1; }
      else{
           balance-=2;//������ 
           take_times+=1;//������һ 
           p.update_alltimes(ID);//�˵��ܳ˳�������һ
          if (balance<=5){//���С��5��ʾ��ֵ 
             cout << "���������ͣ��뼰ʱ��ֵ!" << endl; }
          return 0;
      }
   }
   else return -1;
}//ѧ����ʹ����� 

void Scard::showcard(bus_data &bus){
	Scard_data scd;
	people_data p;
	int j=scd.search_card();//������Ѱ�ң����ض��������±� 
	if(j==-1) return; //�޴˿�������
	int q=bus.search_bus();//�����ƺ�Ѱ�ң����ض��������±� 
	if(q==-1) return;//�޴˳������� 
	int k;//��� 
	cout << "���������˳���Σ�";  cin >> k;
    int s=bus.get_bus()[q].get_station()[k-1];//��վ 
	s=p.get_off(s);//ͳ�Ʊ�վ�³����� 
	q=bus.select_bus(q,k,s);//��ʾ��ǰ��������  
	if(q!=-1 && q!=-2){//���δ���أ���ˢ��
	  int s=scd.card[j].usecard(p);
	  if(s==-1) return;}
	else {
		if(q==-2)//������յ�վ���������³����Ϊ0
		   p.setall(); 
	    return;}//������ˢ��
	cout << endl << "һ��ͨ������Ϣ���£� " << endl << endl ;
	//�Ӷ�����������ȡ���
    cout << "���������� " <<  scd.card[j].get_name() << endl;
    cout << "�������ţ� " <<  scd.card[j].get_num()  << endl;
    cout << "��    λ�� " <<  scd.card[j].get_unit() << endl;
    cout << "��    �֣� " << "ѧ����" << endl;
    cout << "������ " <<  scd.card[j].get_balance() << endl;
    cout << "�˳������� " <<  scd.card[j].get_times()   << endl;
    cout << "��Ч��  �� " <<  scd.card[j].get_end_date()   << endl << endl << endl;
    //�������һ���³���
	srand(time(0));
	int a=rand()%(N+1)+1;
	if(a==N+1) cout << "�����յ��³�"<<endl<<endl;
	else cout << "����ͣ����"<<a<<"�³�"<<endl<<endl;
	p.set_get_off(scd.card[j].get_ID(),a);//���������³�������˵���Ϣ�� 
}//��� 

//�������Ա���� 
int Lcard::usecard(people_data &p){
	 int j=p.status(ID);
	 if(j==0){
      if (take_times<20){//�˳�����С�ڶ�ʮ�����շ� 
          take_times+=1;
          p.update_alltimes(ID);//�˵��ܳ˳�������һ
      return 0;}
      if (balance<2){//���С��2���������ϳ� 
            cout << "�������㣬���ֵ��ʹ�ã�"; 
      return -1;}
      else{
           balance-=2;//������ 
           take_times+=1;
           p.update_alltimes(ID);//�˵��ܳ˳�������һ
        if (balance<=5){//���С��5��ʾ��ֵ 
            cout << "�����ͣ���ʱ��ֵ!"; 
		return 0;}
      }
  }
  else return -1;
}//���ƿ�ʹ�����  

void Lcard::showcard(bus_data &bus){
	Lcard_data lcd;
	people_data p;
	int j=lcd.search_card();//������Ѱ�ң����ض��������±� 
	if(j==-1) return; //�޴˿�������
	int q=bus.search_bus();//�����ƺ�Ѱ�ң����ض��������±�
	if(q==-1) return;
	int k;//��� 
	cout << "���������˳���Σ�";  cin >> k;
	int s=bus.get_bus()[q].get_station()[k-1];//��վ 
	s=p.get_off(s);//ͳ�Ʊ�վ�³����� 
	q=bus.select_bus(q,k,s);//��ʾ��ǰ�������� 
	if(q!=-1 && q!=-2){//���δ���أ���ˢ��
	  int s=lcd.card[j].usecard(p);
	  if(s==-1) return ;}
	else {
		if(q==-2)//������յ�վ���������³����Ϊ0
		   p.setall(); 
	    return;}//������ˢ��
	cout << endl << "һ��ͨ������Ϣ���£� " << endl << endl ;
	//�Ӷ�����������ȡ���
    cout << "���������� " <<  lcd.card[j].get_name() << endl;
    cout << "�������ţ� " <<  lcd.card[j].get_num()  << endl;
    cout << "��    λ�� " <<  lcd.card[j].get_unit() << endl;
    cout << "��    �֣� " << "���ƿ�" << endl;
    cout << "������ " <<  lcd.card[j].get_balance() << endl;
    cout << "�˳������� " <<  lcd.card[j].get_times()   << endl;
    cout << "��Ч��  �� " <<  lcd.card[j].get_end_date()   << endl << endl << endl;
    if (lcd.card[j].get_times()==20)//�ڶ�ʮ����ʾ�´ο�ʼҪ�շ� 
	   cout << "���Ǳ������һ����ѳ˳�" << endl << endl << endl;
    if (lcd.card[j].get_times()>20) 
	   cout << "���Ǳ��µ�" << lcd.card[j].get_times() << "�γ˳��������շ�2Ԫ��" << endl << endl;   
	//�������һ���³���
	srand(time(0));
	int a=rand()%(N+1)+1;
	if(a==N+1) cout << "�����յ��³�"<<endl<<endl;
	else cout << "����ͣ����"<<a<<"�³�"<<endl<<endl;  
	p.set_get_off(lcd.card[j].get_ID(),a);//���������³�������˵���Ϣ�� 
}//��� 

//��ʦ����Ϣ�������Ա������
Tcard_data::Tcard_data(){
	i=0;//��ʼ��Ϊ�� 
	Tcard cd;	
	fstream file("teacher.txt",ios::in);
	while(1){
         file.read((char*)&cd,sizeof(cd));
         if(!file) break; 
           card[i]=cd;i++; }//���ļ��аѶ����ȡ�������� 
	file.close();
}//���캯������ȡ�ļ����ݣ�

int Tcard_data::search_card(){ 
    int card_num;
    cout << endl << "�����뿨�ţ�"; cin >> card_num; cout << endl;
    int j;
	for(j=0;j<i;j++)
	   if(card[j].get_num()==card_num)//�ڶ���������Ѱ���±� 
    	  return j;//�����±� 
    if(j==i){
	   cout << " �˿������ڣ�"<<endl; return -1;
    }	  
}//���ļ�������Ҫ��ѯ�Ŀ��� 

Tcard_data::~Tcard_data(){
    ofstream file("teacher.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&card[j],sizeof(card[j])); }//���°��������Ϣд���ļ� 
	file.close();	
}//��������������ʱд��ˢ�º�����ݣ� 

//ѧ������Ϣ�������Ա������
Scard_data::Scard_data(){
	i=0;//��ʼ��Ϊ��
	Scard cd;	
	fstream file("student.txt",ios::in);
	while(1){
        file.read((char*)&cd,sizeof(cd));
        if(!file) break; 
          card[i]=cd;i++; }//���ļ��аѶ����ȡ��������
	file.close();
}//���캯������ȡ�ļ����ݣ�

int Scard_data::search_card(){
	int card_num;
	cout << endl << "�����뿨�ţ�"; cin >> card_num;cout << endl;
	int j;
	for(j=0;j<i;j++)
	   if(card[j].get_num()==card_num)//�ڶ���������Ѱ���±�
	      return j;//�����±� 
	if(j==i){
	   cout << " �˿������ڣ�"<<endl; return -1;
    }
}//���ļ�������Ҫ��ѯ�Ŀ��� 

void Scard_data::rechange(){
    int j=search_card();//Ѱ�������±� 
    if(j==-1) return;
	cout << endl << "�������ֵǮ��/Ԫ��"; int a; cin >> a;
    card[j].set_balance(card[j].get_balance()+a);//�ı������Ϣ 
    cout << endl << "��ֵ�ɹ���"<< endl;
}//��ֵ

Scard_data::~Scard_data(){
    ofstream file("student.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&card[j],sizeof(card[j])); }//���°��������Ϣд���ļ�
	file.close();	
}//��������������ʱд��ˢ�º�����ݣ�

//���ƿ���Ϣ�������Ա������
Lcard_data::Lcard_data(){
	i=0;//��ʼ��Ϊ�� 
	Lcard cd;	
	fstream file("limit.txt",ios::in);
	while(1){
        file.read((char*)&cd,sizeof(cd));
        if(!file) break; 
          card[i]=cd;i++; }//���ļ��аѶ����ȡ��������
	file.close();
}//���캯������ȡ�ļ����ݣ�

int Lcard_data::search_card(){
	int card_num;
	cout << endl << "�����뿨�ţ�"; cin >> card_num;cout << endl;
	int j;
	for(j=0;j<i;j++)
	   if(card[j].get_num()==card_num)//�ڶ���������Ѱ���±�
	      return j;//�����±�
	if(j==i){
	   cout <<" �˿������ڣ�"<<endl; return -1;
    }    
}//���ļ�������Ҫ��ѯ�Ŀ��� 

void Lcard_data::rechange(){
    int j=search_card();//Ѱ�������±�
    if(j==-1) return;
	cout << endl << "�������ֵǮ��/Ԫ��";
	int a; cin >> a;
    card[j].set_balance(card[j].get_balance()+a);//�ı������Ϣ 
	cout << endl << "��ֵ�ɹ���"<< endl;
}//��ֵ

Lcard_data::~Lcard_data(){
    ofstream file("limit.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&card[j],sizeof(card[j])); }//���°��������Ϣд���ļ�
	file.close();	
}//��������������ʱд��ˢ�º�����ݣ�
