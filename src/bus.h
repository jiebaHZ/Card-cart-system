#define M 30//车数量 
#define N 2//站点数 
class Bus{
private:
	int bus_number;//车牌号
	char model[20];//车型号
	int limiters;//核载乘人数
	char driver_name[20];//司机姓名
	float startime[N][N+1];//发车时间
	float endtime[N][N+1];//收车时间
	char time_section[20];//运行时间段
	float r_startime[N][N+1];//实际发车时间
	float r_endtime[N][N+1];//实际收车时间
	int passengers[N];//实际载乘人数
	int now_passengers[N];//当前人数 
	int station[N];//当前站 
public:
	Bus(){}
	//set,get函数 
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
	void buildbus();//新增班车 
	void show();//显示班车信息 
	void ontime_rate();//计算准时率 
    ~Bus(){} 
};//班车类 

class bus_data{
private:
	Bus bus[M];//班车类对象数组 
	int i;//数组下标（对象个数） 
public:
	bus_data();//构造函数，读取文件信息，存入数组 
	Bus*get_bus() {return bus;}//返回对象数组地址 
	int search_bus();//寻找班车，返回对象数组下标 
	int select_bus(int j,int k,int s);//上车，传入卡类对象数组下标，车类对象数组下标，以及下车人数 
	friend void Bus::buildbus();
	friend void Bus::show(); 
	~bus_data();//析构函数，作用结束时重新写入文件 
};//班车信息管理类 
