//reject member project
//by ���ٵ���
//20180125
//����� 
//1��setw()������ʾ�ַ����� ��Ч
//2����������

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
	char name[MAX_NUM][3]; // ����ĸ��д
	int  QQ[MAX_NUM];     
	int entry_year[MAX_NUM];
	int entry_month[MAX_NUM];
	int useful_data[MAX_NUM];
public:
	int *get_useful_data(){return useful_data;}
	char *getdieoutpeople(int num){return name[num];}//ָ������ ���ִ�ӡ  �����˵��ʱ������ 
	void fast_sort(int *arr,int low,int hight) //��С����
	{
		
		  int pos;
		  if(low<hight){
			  pos=findPos(arr,low,hight);  //�ȶ��������һ�ο������򣬽���ֳ�����
			  fast_sort(arr,low,pos-1);  //Ȼ��ֱ��posλ����ߵĲ����ڽ��п�������λ���ұߵĲ��ֽ��п������� 
			  fast_sort(arr,pos+1,hight); 
     }    
	}

int findPos(int *arr,int low,int hight){
    int val=arr[low];
	int QQ_TEMP = QQ[low];
	char name_temp[3];
	memcpy(name_temp,name[low],3);


     while(low<hight){  //��һ�ο���������ֻҪlow��ֵ��hightС�����Ǿ�Ӧ��ȥ�ƶ�����Ϊ��ǰ�������û����� 
         while(low<hight&&arr[hight]>=val){  //��ʾֻ�е�ǰָ��û���غϲ��ҵ�ǰ�ұ�hightָ���ֵ����valʱ���Ż������ƶ�hight
             hight=hight-1;            
         }
         arr[low] =arr[hight];  //����valС��ֵ����low 
		 QQ[low]  =QQ[hight];
		 memcpy(name[low],name[hight],3);
         while(low<hight&&arr[low]<=val){
             low=low+1;  
         }
         arr[hight]=arr[low];  //����val���ֵ����hight�� 
		 memcpy(name[hight],name[low],3);
		 QQ[hight] =QQ[low];
     }

     arr[low]=val;  //�ҵ���������λ�ã����ҽ�����ѡ����ֵval�������λ����ȥ 
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
	 *  ��������
	 */
	

	int max = 2; // ������ٸ��˵����ݼ�һ
	man.cal();
	man.fast_sort(man.get_useful_data(),0,max);

	int n = 2;// ��ӡ������
	for(int i = 0;i<n;i++)
	cout <<"����Դ�����"<<n-i<<"���ٵĸ���Ϊ��"<<setw(-3)<<man.getdieoutpeople(max-i)<<endl;

    return 0;
}