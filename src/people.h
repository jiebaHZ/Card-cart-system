#define P 100//������ 
class Tcard;
class Scard;
class Lcard;
using namespace std;
class people{
private:
	char name[20];//���� 
	char sex[20];//�Ա� 
	int ID;//���ʺ�/ѧ�� 
	char unit[20];//������λ
	char business[20];//ְ��
	int all_times;//���п��˳��ܴ��� 
	int card_amount;//�������� 
	int getoff;//�³��� 
public:
	people(){}
	//set,get���� 
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
    void buildTcard();//�½���ʦ�� 
    void buildScard();//�½�ѧ���� 
    void buildLcard();//�½����ƿ� 
    void buildpeople();//�½��� 
    void deleteTcard();//ɾ����ʦ�� 
    void deleteScard();//ɾ��ѧ���� 
    void deleteLcard();//ɾ�����ƿ� 
    void deletepeople(int a);//ɾ���ˣ����빤�ʺ�/ѧ�� 
    void alltimes();//�˳��ܴ��� 
    void show();//��ʾ��Ϣ 
    ~people(){}	
};//�� 

class people_data{
private:
	people person[P];//����������� 
	int i;//�����±꣨��������� 
public:
	people_data();//���캯������ȡ�ļ����� 
	int get_off(int j);//����վ�㣬ͳ���³����� 
	void set_get_off(int j,int a);//����ֿ��˹��ʺ�/ѧ�ţ��³��� �������³��� 
	int search_p(int id);//�����ʺ�/ѧ�ţ�Ѱ�Ҵ��ˣ������±� 
	void update_alltimes(int j);//���¶����������˵��ܳ˳����� 
	int status(int id);//�жϴ����Ƿ��ڳ��� 
	void setall();//������վ��ȫ����ʼ��Ϊ0 
	friend class people;
	~people_data();	//�������������ý���д���ļ� 
};//����Ϣ������
