#define T 40//��ʦ������ 
#define S 60//ѧ�������� 
#define L 20//���ƿ����� 
class people;//���� 
class Card{
protected:
	int card_number;//���� 
	char name[20];//����  
	char unit[20];//������λ
	int take_times;//�˳�����
	char end_date[20];//��Ч�� 
	int ID;//���ʺ�/ѧ�� 
public:
	Card(){}
	//set,get����:
    int get_num()                  {return card_number;}
    char* get_name()               {return name;}
    int get_times()                {return take_times;}
    char* get_end_date()           {return end_date;}
    char* get_unit()               {return unit;}
    int get_ID()                   {return ID;}
    void set_num(int n)            {card_number=n;}
    void set_name(char a[])        {strcpy(name,a);}
    void set_times(int n)          {take_times=n;}
    void set_end_date(char a[])    {strcpy(end_date,a);} 
    void set_unit(char a[])        {strcpy(unit,a);}
    void set_ID(int n)             {ID=n;}
    ~Card(){}
};//���� 

class Tcard:public Card{
private:
public:
	Tcard(){} 
    int usecard(people_data &p);//ˢ�� 
    void showcard(bus_data &bus);//ˢ������ʾ��Ϣ��ͬʱ���ϳ˿���Ϣ�ı� 
    ~Tcard(){}
}; //��ʦ�� 

class Scard:public Card{
private:
	int balance;//���
public:
	Scard(){}
	int get_balance(){ return balance;}//��� 
    void set_balance(int n){ balance=n;}      
    int usecard(people_data &p);//ˢ�� 
    void showcard(bus_data &bus);//ˢ������ʾ��Ϣ��ͬʱ���ϳ˿���Ϣ�ı�
    ~Scard(){}
};//ѧ���� 

class Lcard:public Card{
private:
	int balance;//��� 
public:
	Lcard(){}
	int get_balance(){ return balance;}//��� 
    void set_balance(int n){ balance=n;}     
    int usecard(people_data &p);//ˢ�� 
    void showcard(bus_data &bus);//ˢ������ʾ��Ϣ��ͬʱ���ϳ˿���Ϣ�ı�
    ~Lcard(){}
};//������

class Tcard_data{
private:
	Tcard card[T];//��ʦ����������� 
	int i;//�����±꣨��������� 
public:
	Tcard_data();//���ļ���ȡ���� 
	int search_card();//��������Ѱ�ҿ��������±� 
	friend void Tcard::showcard(bus_data &bus); 
	friend void people::buildTcard();
	friend void people::deleteTcard(); 
	~Tcard_data();//���ý���д���ļ� 
};//��ʦ����Ϣ������ 

class Scard_data{
private:
	Scard card[S];//ѧ����������� 
	int i;//�����±꣨��������� 
public:
	Scard_data();//���ļ���ȡ���� 
	int search_card();//��������Ѱ�ҿ��������±� 
	void rechange();//��ֵ 
	friend void Scard::showcard(bus_data &bus);
	friend void people::buildScard();
	friend void people::deleteScard(); 
	~Scard_data();//���ý���д���ļ� 
};//ѧ������Ϣ������ 

class Lcard_data{
private:
	Lcard card[L];//������������� 
	int i;//�����±꣨���������
public:
	Lcard_data();//���ļ���ȡ���� 
    int search_card();//��������Ѱ�ҿ��������±� 
    void rechange();//��ֵ 
    friend void Lcard::showcard(bus_data &bus);
	friend void people::buildLcard();
	friend void people::deleteLcard();
	~Lcard_data();//���ý���д���ļ�
};//���ƿ���Ϣ������
