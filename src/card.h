#define T 40//教师卡数量 
#define S 60//学生卡数量 
#define L 20//限制卡数量 
class people;//声明 
class Card{
protected:
	int card_number;//卡号 
	char name[20];//姓名  
	char unit[20];//所属单位
	int take_times;//乘车次数
	char end_date[20];//有效期 
	int ID;//工资号/学号 
public:
	Card(){}
	//set,get函数:
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
};//基类 

class Tcard:public Card{
private:
public:
	Tcard(){} 
    int usecard(people_data &p);//刷卡 
    void showcard(bus_data &bus);//刷卡后显示信息，同时车上乘客信息改变 
    ~Tcard(){}
}; //教师类 

class Scard:public Card{
private:
	int balance;//余额
public:
	Scard(){}
	int get_balance(){ return balance;}//余额 
    void set_balance(int n){ balance=n;}      
    int usecard(people_data &p);//刷卡 
    void showcard(bus_data &bus);//刷卡后显示信息，同时车上乘客信息改变
    ~Scard(){}
};//学生类 

class Lcard:public Card{
private:
	int balance;//余额 
public:
	Lcard(){}
	int get_balance(){ return balance;}//余额 
    void set_balance(int n){ balance=n;}     
    int usecard(people_data &p);//刷卡 
    void showcard(bus_data &bus);//刷卡后显示信息，同时车上乘客信息改变
    ~Lcard(){}
};//限制类

class Tcard_data{
private:
	Tcard card[T];//教师卡类对象数组 
	int i;//数组下标（对象个数） 
public:
	Tcard_data();//从文件读取对象 
	int search_card();//在数组中寻找卡，返回下标 
	friend void Tcard::showcard(bus_data &bus); 
	friend void people::buildTcard();
	friend void people::deleteTcard(); 
	~Tcard_data();//作用结束写入文件 
};//教师卡信息管理类 

class Scard_data{
private:
	Scard card[S];//学生类对象数组 
	int i;//数组下标（对象个数） 
public:
	Scard_data();//从文件读取对象 
	int search_card();//在数组中寻找卡，返回下标 
	void rechange();//充值 
	friend void Scard::showcard(bus_data &bus);
	friend void people::buildScard();
	friend void people::deleteScard(); 
	~Scard_data();//作用结束写入文件 
};//学生卡信息管理类 

class Lcard_data{
private:
	Lcard card[L];//限制类对象数组 
	int i;//数组下标（对象个数）
public:
	Lcard_data();//从文件读取对象 
    int search_card();//在数组中寻找卡，返回下标 
    void rechange();//充值 
    friend void Lcard::showcard(bus_data &bus);
	friend void people::buildLcard();
	friend void people::deleteLcard();
	~Lcard_data();//作用结束写入文件
};//限制卡信息管理类
