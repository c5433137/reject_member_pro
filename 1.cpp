//reject member project
//by 不再单纯
//20180125
//待解决 
//1、setw()设置显示字符个数 无效
//2、输入数据

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
 

#define MAX_NUM 200
class MAN
{
public:
	MAN()
	{
		memset(name,NULL,MAX_NUM * 3);
		memset(QQ,0,200);
		memset(entry_year,-1,MAX_NUM);
		memset(entry_month,-1,MAX_NUM);
		memset(useful_data,-1,MAX_NUM);

		/******test data*******/
		memcpy(name[0],"cz0",3);
		memcpy(name[1],"cz1",3);
		memcpy(name[2],"cz2",3);
		entry_year[0] = 2017;
		entry_year[2] = 2017;
		entry_year[3] = 2017;
		entry_month[0] = 1;
		entry_month[1] = 2;
		entry_month[2] = 3;
	}

private:
	char name[MAX_NUM][3]; // 首字母简写
	int  QQ[MAX_NUM];     
	int entry_year[MAX_NUM];
	int entry_month[MAX_NUM];
	int useful_data[MAX_NUM];
public:
	int *get_useful_data(){return useful_data;}
	char *getdieoutpeople(int num){return name[num];}//指定人数 名字打印  按最近说话时间增加 
	void fast_sort(int *arr,int low,int hight) //从小到大
	{
		
		  int pos;
		  if(low<hight){
			  pos=findPos(arr,low,hight);  //先对整体进行一次快速排序，将其分成两半
			  fast_sort(arr,low,pos-1);  //然后分别对pos位置左边的部分在进行快速排序，位置右边的部分进行快速排序 
			  fast_sort(arr,pos+1,hight); 
     }    
	}

int findPos(int *arr,int low,int hight){
    int val=arr[low];
	int QQ_TEMP = QQ[low];
	char name_temp[3];
	memcpy(name_temp,name[low],3);


     while(low<hight){  //再一次快速排序中只要low的值比hight小，我们就应该去移动，因为当前这次排序还没有完成 
         while(low<hight&&arr[hight]>=val){  //表示只有当前指针没有重合并且当前右边hight指向的值大于val时，才会向左移动hight
             hight=hight-1;            
         }
         arr[low] =arr[hight];  //将比val小的值赋到low 
		 QQ[low]  =QQ[hight];
		 memcpy(name[low],name[hight],3);
         while(low<hight&&arr[low]<=val){
             low=low+1;  
         }
         arr[hight]=arr[low];  //将比val大的值赋到hight上 
		 memcpy(name[hight],name[low],3);
		 QQ[hight] =QQ[low];
     }

     arr[low]=val;  //找到了所属的位置，并且将我们选定的值val赋到这个位置上去 
	 QQ[low] =QQ_TEMP;
	 memcpy(name[low],name_temp,3);
     return hight; 
 }


	void cal()
	{
		int *year  = entry_year;
		int *month = entry_month;
		int *data  = useful_data;
		while(*data == -1)
		{
			*data = (*year) * 365 + (*month);
		}
	}

	~MAN()
	{

	}
};
int main()
{
	MAN man;

	/*
	 *  插入数据
	 */
	

	int max = 2; // 输入多少个人的数据减一
	man.cal();
	man.fast_sort(man.get_useful_data(),0,max);

	int n = 2;// 打印几个人
	for(int i = 0;i<n;i++)
	cout <<"最后发言次数第"<<n-i<<"最少的个人为："<<setw(-3)<<man.getdieoutpeople(max-i)<<endl;

    return 0;
}