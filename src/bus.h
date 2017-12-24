#define M 30//������ 
#define N 2//վ���� 
class Bus{
private:
	int bus_number;//���ƺ�
	char model[20];//���ͺ�
	int limiters;//���س�����
	char driver_name[20];//˾������
	float startime[N][N+1];//����ʱ��
	float endtime[N][N+1];//�ճ�ʱ��
	char time_section[20];//����ʱ���
	float r_startime[N][N+1];//ʵ�ʷ���ʱ��
	float r_endtime[N][N+1];//ʵ���ճ�ʱ��
	int passengers[N];//ʵ���س�����
	int now_passengers[N];//��ǰ���� 
	int station[N];//��ǰվ 
public:
	Bus(){}
	//set,get���� 
	int* get_station()                   {return station;}
	int get_num()                        {return bus_number;}
	char* get_model()                    {return model;}
	int get_limiters()                   {return limiters;}
	char* get_name()                     {return driver_name;}
	char* get_section()                  {return time_section;}
	int* get_passengers()                {return passengers;}
	int* get_now_passengers()            {return now_passengers;}
	void* set_station(int a[])           {for(int j=0;j<N;j++)station[j]=a[j];}
	void set_num(int a)                  {bus_number=a;}
	void set_model(char a[])             {strcpy(model,a);}
	void set_limiters(int a)             {limiters=a;}
	void set_name(char a[])              {strcpy(driver_name,a);}
	void set_startime(float a[][N+1])    {for(int j=0;j<N;j++) for(int k=0;k<N+1;k++) startime[j][k]=a[j][k];}
	void set_endtime(float a[][N+1])     {for(int j=0;j<N;j++) for(int k=0;k<N+1;k++) endtime[j][k]=a[j][k];}
	void set_section(char a[])           {strcpy(time_section,a);}
	void set_passengers(int a[])         {for(int j=0;j<N;j++) passengers[j]=a[j];}
	void set_now_passengers(int a[])     {for(int j=0;j<N;j++) now_passengers[j]=a[j];}
	void set_r_startime(float a[][N+1])  {for(int j=0;j<N;j++) for(int k=0;k<N+1;k++) r_startime[j][k]=a[j][k];}
	void set_r_endtime(float a[][N+1])   {for(int j=0;j<N;j++) for(int k=0;k<N+1;k++) r_endtime[j][k]=a[j][k];}
	void buildbus();//�����೵ 
	void show();//��ʾ�೵��Ϣ 
	void ontime_rate();//����׼ʱ�� 
    ~Bus(){} 
};//�೵�� 

class bus_data{
private:
	Bus bus[M];//�೵��������� 
	int i;//�����±꣨��������� 
public:
	bus_data();//���캯������ȡ�ļ���Ϣ���������� 
	Bus*get_bus() {return bus;}//���ض��������ַ 
	int search_bus();//Ѱ�Ұ೵�����ض��������±� 
	int select_bus(int j,int k,int s);//�ϳ������뿨����������±꣬������������±꣬�Լ��³����� 
	friend void Bus::buildbus();
	friend void Bus::show(); 
	~bus_data();//�������������ý���ʱ����д���ļ� 
};//�೵��Ϣ������ 
