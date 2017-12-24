#define P 100//人数量 
class Tcard;
class Scard;
class Lcard;
using namespace std;
class people{
private:
	char name[20];//姓名 
	char sex[20];//性别 
	int ID;//工资号/学号 
	char unit[20];//所属单位
	char business[20];//职务
	int all_times;//所有卡乘车总次数 
	int card_amount;//卡的数量 
	int getoff;//下车点 
public:
	people(){}
	//set,get函数 
	char* get_name()               {return name;}
	char* get_sex()                {return sex;}
    int get_ID()                   {return ID;}
    char* get_unit()               {return unit;}
    char* get_business()           {return business;}
    int get_alltimes()             {return all_times;}
    int get_amount()               {return card_amount;}
    int get_getoff()               {return getoff;}
    void set_name(char a[])        {strcpy(name,a);}
    void set_sex(char a[])         {strcpy(sex,a);}
    void set_ID(int n)             {ID=n;}
    void set_unit(char a[])        {strcpy(unit,a);}
    void set_business(char a[])    {strcpy(business,a);}
    void set_alltimes(int n)       {all_times=n;}
    void set_amount(int n)         {card_amount=n;}
    void set_getoff(int n)         {getoff=n;}
    void buildTcard();//新建教师卡 
    void buildScard();//新建学生卡 
    void buildLcard();//新建限制卡 
    void buildpeople();//新建人 
    void deleteTcard();//删除教师卡 
    void deleteScard();//删除学生卡 
    void deleteLcard();//删除限制卡 
    void deletepeople(int a);//删除人，传入工资号/学号 
    void alltimes();//乘车总次数 
    void show();//显示信息 
    ~people(){}	
};//人 

class people_data{
private:
	people person[P];//人类对象数组 
	int i;//数组下标（对象个数） 
public:
	people_data();//构造函数，读取文件对象 
	int get_off(int j);//传入站点，统计下车人数 
	void set_get_off(int j,int a);//传入持卡人工资号/学号，下车点 ，设置下车点 
	int search_p(int id);//传入资号/学号，寻找此人，返回下标 
	void update_alltimes(int j);//更新对象数组中人的总乘车次数 
	int status(int id);//判断此人是否在车上 
	void setall();//所有人站点全部初始化为0 
	friend class people;
	~people_data();	//析构函数，作用结束写入文件 
};//人信息管理类
