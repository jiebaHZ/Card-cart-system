using namespace std;
//����ĳ�Ա������ 
void people::buildTcard(){
	Tcard_data tcd;
	int card_number;//�������� 
	char end_date[20];//�������� 
	cout << "�½�һ��ͨ����¼����Ϣ��"<< endl << endl;
	cout << "�����뿨�ţ�"; 	     cin >> card_number;  tcd.card[tcd.i].set_num(card_number);//����������� 
	cout << endl << "������������";  cin >> name;         tcd.card[tcd.i].set_name(name);
	cout << endl << "�����빤�ʺ�/ѧ�ţ�"; cin >> ID;     tcd.card[tcd.i].set_ID(ID);
	cout << endl << "�����뵥λ��";  cin >> unit;         tcd.card[tcd.i].set_unit(unit);
	cout << endl << "��������Ч�ڣ�";cin >> end_date;     tcd.card[tcd.i].set_end_date(end_date);
	tcd.card[tcd.i].set_times(0);//��ʼ���ܳ˳����� 
	tcd.i++;
	buildpeople();//�����˵���Ϣ 
	cout << endl << "�����ɹ���"<< endl<< endl ;
}//�½���ʦ�� 

void people::buildScard(){
	Scard_data scd;
	int card_number,balance;//�������� 
	char end_date[20];//�������� 
	cout << "�½�һ��ͨ����¼����Ϣ��"<< endl << endl;
	cout << "�����뿨�ţ�"; 	     cin >> card_number;  scd.card[scd.i].set_num(card_number);//�����������
	cout << endl << "������������";  cin >> name;         scd.card[scd.i].set_name(name);
	cout << endl << "�����빤�ʺ�/ѧ�ţ�"; cin >> ID;     scd.card[scd.i].set_ID(ID);
	cout << endl << "�����뵥λ��";  cin >> unit;         scd.card[scd.i].set_unit(unit);
	cout << endl << "��������Ч�ڣ�";cin >> end_date;     scd.card[scd.i].set_end_date(end_date);
	cout << endl << "�������ֵǮ��/Ԫ��";cin >> balance; scd.card[scd.i].set_balance(balance);
	scd.card[scd.i].set_times(0);//��ʼ���ܳ˳����� 
    scd.i++;
	buildpeople();//�����˵���Ϣ
	cout << endl << "�����ɹ���"<< endl<< endl ;
}//�½�ѧ���� 

void people::buildLcard(){
	Lcard_data lcd;
	int card_number,balance;//��������
	char end_date[20];//�������� 
	cout << "�½�һ��ͨ����¼����Ϣ��"<< endl << endl;
	cout << "�����뿨�ţ�"; 	     cin >> card_number;  lcd.card[lcd.i].set_num(card_number);//�����������
	cout << endl << "������������";  cin >> name;         lcd.card[lcd.i].set_name(name);
	cout << endl << "�����빤�ʺ�/ѧ�ţ�"; cin >> ID;     lcd.card[lcd.i].set_ID(ID);
	cout << endl << "�����뵥λ��";  cin >> unit;         lcd.card[lcd.i].set_unit(unit);
	cout << endl << "��������Ч�ڣ�";cin >> end_date;     lcd.card[lcd.i].set_end_date(end_date);
	cout << endl << "�������ֵǮ��/Ԫ��";cin >> balance; lcd.card[lcd.i].set_balance(balance);
	lcd.card[lcd.i].set_times(0);//��ʼ���ܳ˳�����
	lcd.i++;
	buildpeople();//�����˵���Ϣ 
	cout << endl << "�����ɹ���"<< endl<< endl;
}//�½����ƿ� 

void people::buildpeople(){
	people_data p;
	int k=p.search_p(ID);//�ڶ����������������� 
	if(k==-1){//���û�д��ˣ���Ϣ�������� 
    p.person[p.i].set_name(name);
	cout << endl << "�������Ա�";  cin >> sex;      p.person[p.i].set_sex(sex);
    p.person[p.i].set_ID(ID);
    p.person[p.i].set_unit(unit);
	cout << endl << "������ְ��";  cin >> business; p.person[p.i].set_business(business); 
	p.person[p.i].set_alltimes(0);
	p.person[p.i].set_amount(1);
	p.person[p.i].set_getoff(0);
	p.i++;}
	p.person[k].set_amount(p.person[k].card_amount+1); //���˿���������һ 
}//�����Ϣ 

void people::deleteTcard(){
	 Tcard_data td; 
	 int j=td.search_card();//���ݿ���Ѱ���±� 
	 if(j==-1) return;
	 int a=td.card[j].get_ID();//���ݹ��ʺ�/ѧ��Ѱ�Ҵ��� 
	 for(int k=j;k<td.i;k++)
	    td.card[k]=td.card[k+1];//������ǰ�ƶ�һλ 
	 td.i--;
	 cout << "ע���ɹ���"<< endl<< endl;
     deletepeople(a);//ѡ���Ƿ�ɾ���˵���Ϣ 
}//ɾ�������е���Ϣ  

void people::deleteScard(){
	 Scard_data sd; 
	 int j=sd.search_card();//���ݿ���Ѱ���±�
	 if(j==-1) return;
	 int a=sd.card[j].get_ID();//���ݹ��ʺ�/ѧ��Ѱ�Ҵ��� 
	 for(int k=j;k<sd.i;k++)
	    sd.card[k]=sd.card[k+1];//������ǰ�ƶ�һλ 
	 sd.i--; 
	 cout << "ע���ɹ���"<< endl<< endl;
     deletepeople(a);//ѡ���Ƿ�ɾ���˵���Ϣ
}//ɾ�������е���Ϣ 

void people::deleteLcard(){
	 Lcard_data ld; 
	 int j=ld.search_card();//���ݿ���Ѱ���±�
	 if(j==-1) return;
	 int a=ld.card[j].get_ID();//���ݹ��ʺ�/ѧ��Ѱ�Ҵ���
	 for(int k=j;k<ld.i;k++)
	    ld.card[k]=ld.card[k+1];//������ǰ�ƶ�һλ 
	 ld.i--; 
	 cout << "ע���ɹ���"<< endl<< endl;
     deletepeople(a);//ѡ���Ƿ�ɾ���˵���Ϣ
}//ɾ�������е���Ϣ 

void people::deletepeople(int a){//���빤�ʺ�/ѧ�� 
	 people_data p;
	 int k=p.search_p(a);//Ѱ�������±� 
	 p.person[k].card_amount-=1;//��������һ 
	 if(p.person[k].card_amount==0){//���������Ϊ0 
	   cout << "����ǰһ��ͨ����Ϊ0,�Ƿ�ע��������Ϣ����ѡ��" << endl << endl;
	   cout <<  "          1 ��     2 ��                    " << endl; 
	   int x; cin >> x;
       if(x==1){
	     for(int j=k;j<p.i;j++)
	        p.person[j]=p.person[j+1];//������ǰ�ƶ�һλ 
	   p.i--;}
	   else return; }
}//ɾ���˵���Ϣ 

void people::alltimes(){
     all_times+=1; 
}//�ܴ�����һ 

void people::show(){
	int id;
	cout << endl << "�����빤�ʺ�/ѧ�ţ�"; cin >> id;
	people_data p;
	int j=p.search_p(id);//ѡ�������±� 
	if(j==-1) {   cout << "���˲����ڣ�"<<endl; return;}
	cout << endl << "������Ϣ���£�"<<endl;
	cout << endl << "������"<<p.person[j].name;
	cout << endl << "�Ա�"<<p.person[j].sex;
	cout << endl << "���ʺ�/ѧ�ţ�"<<p.person[j].ID;
	cout << endl << "��λ��"<< p.person[j].unit;
	cout << endl << "ְ��"<< p.person[j].business; 
	cout << endl << "�ܳ˳�������"<< p.person[j].all_times;
	cout << endl << "��������"<< p.person[j].card_amount;cout<<endl;
}

people_data::people_data(){
	i=0;//��ʼ��Ϊ�� 
	people p;	
	fstream file("people.txt",ios::in);
	while(1){
        file.read((char*)&p,sizeof(p));//��ȡ�ļ����� 
        if(!file) break; 
          person[i]=p;i++; }//�������� 
	file.close();
}//���캯������ȡ�ļ����ݣ�

int people_data::search_p(int id){//���빤�ʺ�/ѧ�� 
	int j;
	for(j=0;j<i;j++)
	   if(person[j].get_ID()==id)
	      return j;//�����±� 
	if(j==i){
	      return -1;
    }    
}//������

int people_data::get_off(int s){//����վ�� 
	 int k=0;
	 for(int q=0;q<i;q++)
	 	  if(person[q].get_getoff()==s){
	 	    k++;  //ͳ�ƴ�վ�³����� 
            person[q].set_getoff(0);}//�޸��³����˵��³�����Ϣ ������ 
    return k;
}//�³����� 

void people_data::set_get_off(int j,int a){//����ֿ��˹��ʺ�/ѧ�ţ��³��� 
	 int k=search_p(j);//Ѱ�Ҷ��������±� 
	 person[k].set_getoff(a);//�޸��³��� 
}//�����³��� 

void people_data::update_alltimes(int id){
	 int j=search_p(id);
     person[j].alltimes();//�˳��ܴ�����һ 
}//�ܴ�����һ 

int people_data::status(int id){
	int j=search_p(id);
	if(person[j].get_getoff()!=0){
		cout<<endl<<"�����ڳ��ϣ�"<<endl;
		return -1; 
	}
	return 0;
}//�жϴ����Ƿ��ڳ��� 

void people_data::setall(){
	for(int j=0;j<i;j++)
	   person[j].set_getoff(0);
} //ȫ����ʼ��Ϊ�� 

people_data::~people_data(){
    ofstream file("people.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&person[j],sizeof(person[j])); }//����д���ļ� 
	file.close();	
}//�������� 
