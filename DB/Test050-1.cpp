#include<iostream>
#include<stdlib.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;


typedef struct  //定义结构体
{
    int *elem;
    int length;
    int listsize;
}SqList;

SqList L;
SqList La;
SqList Lb;
SqList Lc;
Status InitList(SqList &L)//顺序表的初始化
{
	L.elem=new int[LIST_INIT_SIZE];   //为顺序表分配空间
    if(!L.elem) exit(OVERFLOW);           //存储分配失败
    L.length = LIST_INIT_SIZE;
    L.listsize = LIST_INIT_SIZE;
    for(int i=0;i<8;i++)
    {
    	cin>>L.elem[i];
	}
    return OK;
}
Status ListLength(SqList &L) //顺序表的长度，采用cout或printf输出
{	
	cout<<"该顺序表的长度为:"<<L.length<<endl;
    return OK;
}
Status EmptyList(SqList &L)//判断顺序表是否为空，Length是否为0
{
	if(L.length!=0){
		cout<<"该顺序表不为空"<<endl;
	}
	else{
		cout<<"该顺序表为空"<<endl;
	}
    return OK;
}
Status ClearList(SqList &L)//顺序表的清空，length设为0
{
	if(L.length!= 0)
	{
		L.length=0;
		cout<<"顺序表清空成功"<<endl; 
	}
	else
	{
		cout<<"该顺序表已为空，请重新初始化！"<<endl; 
		InitList(L); 
	}
    return OK;
}
Status DestroyList(SqList &L)  //摧毁给表L分配的内存，可用delete或者free，与分配内存保持一致 
{
	if(L.elem)
	{
		delete []L.elem;
		cout<<"线性表摧毁成功，请重新初始化"<<endl;
		return OK;
	}
	else
	{
		cout<<"该顺序表已为空，无法进行摧毁"<<endl; 
		return OK;
	}
}
Status LocateList(SqList L, int e, int &pos) //找出与e相等的第一个位置，并保存在pos中
{
	if(L.elem)
	{
		for(int i=0;i<L.length;i++)
		{
			if(L.elem[i]==101)
			{
				pos=i+1;
				break;
			}
		}
		cout<<"第一个与e相等的位置为:"<<pos<<endl;	
	}
	else
	{
		cout<<"未找到与e相等的位置"<<endl;
	}
    return OK;
}
Status PointList(SqList &L, int i, int &e) //获取指定位置的顺序表元素赋值给e，并用cout或printf输出
{
	L.elem[i-1]=101;
	cout<<"赋值后的结果为："<<endl;
	cout<<L.elem[i-1];
    return OK;
}
Status BeforPoint(SqList &L,int i)//求顺序表的前驱cout或printf输出，需判断位置是否合法，是否有前驱，
{
	if(i==1)
	{
		cout<<"该位置已经位于表头，无前驱"<<endl;
	}
	else
	 {
	 	cout<<"该位置的前驱是:"<<L.elem[i-2]<<endl;
	 }
    return OK;
}
Status AfterPoint(SqList &L,int i)//求顺序表的后继
{
	if(i==L.length)
	{
		cout<<"该位置已经位于表尾，无后继"<<endl;
	}
	else
	 {
	 	cout<<"该位置的后继是:"<<L.elem[i]<<endl;
	} 
    return OK;
}
Status InsertList(SqList &L,int i,int x)//顺序表位置i处插入元素x，需判断位置i是否合法
{
	if(i<=100)
	{
		int	j=L.length;
		for(;j>=i-1;j--)
		{
			L.elem[j+1]=L.elem[j];
		}
		L.elem[i-1]=x;
		cout<<"插入成功，请继续操作"<<endl; 
	}
	else
	{
		cout<<"很抱歉，插入位置超出数组长度，请重新尝试"<<endl;
	}
    return OK;
}

Status DeleteList(SqList &L,int i)//删除指定位置的元素
{
	int j=L.length;
	if(i<=100)
	{
		for(;i<=j;i++)
		{
			L.elem[i-1]=L.elem[i];
		}
		cout<<"删除成功，请继续操作"<<endl; 
	}
	else
	{
		cout<<"很抱歉，删除位置超出数组长度，请重新尝试"<<endl;
	}
    return OK;

}
Status Display(SqList &L)//显示顺序表的数据，空表提示不能显示数据
{
	cout<<"当前线性表的内容为："<<endl;
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<"   ";
	}
	cout<<endl;
	return OK;
}
Status Merge(SqList La, SqList Lb, SqList &Lc)//合并线性表 
{
	int i=0,j=0;
	int k=0;
	for(k;k<16;)
	{
			for(i,j;j<=7;j++,i++)
			{	
				if(j<=4)
				{
					Lc.elem[k]=La.elem[i];
					k++;
					Lc.elem[k]=Lb.elem[j];
					k++;
				}
				else
				{
					Lc.elem[k]=Lb.elem[i];
					k++;
					Lc.elem[k]=La.elem[j];
					k++;
				}	
			}	
	}

} 
void Tips();//文字提示信息

int main()
{
    Tips();//文字提示信息
    InitList(La);//初始化线性表
    InitList(Lb);
    // int condition; //获取函数返回的类型
    int h,k;//分别用来获取输入的指定位置和插入数据的元素
    int i;//输入的数字
    cout<<"输入你要进行操作的相应数字:";
    cin>>i;

    while(true)
    {
        switch(i)//判断输入的i值
        {
        case 1:
            ClearList(L);//清空顺序表
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 2:
            EmptyList(L);//判断顺序表是否为空
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 3:
            ListLength(L);//求顺序表的长度
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 4:
            DestroyList(L);//摧毁顺序表 
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 5:
            int pos;
            LocateList(L,h,pos);//获取顺序表指定位置的元素
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;

        case 6:
            cout<<"输入指定位置:";
            cin>>h;
            int e;
            PointList(L,h,e);//获取顺序表指定位置的元素
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 7:
            cout<<"输入指定位置:";
            cin>>h;
            BeforPoint(L,h);//求前驱
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 8:
            cout<<"输入指定位置:";
            cin>>h;
            AfterPoint(L,h);//求后继
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 9:
            cout<<"输入指定位置:";
            cin>>h;
            cout<<"输入插入的数值:";
            cin>>k;
            InsertList(L,h,k);//在顺序表指定位置插入数据
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 10:
            cout<<"输入指定位置:";
            cin>>h;
            DeleteList(L,h);//在顺序表的指定位置删除数据
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 11:
            Display(La);//显示顺序表的元素
            Display(Lb);
            Display(Lc);
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 12:
            Tips();//提示信息
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        case 13:
            Lc.elem=new int[LIST_INIT_SIZE];
            Lc.length = LIST_INIT_SIZE;
   			Lc.listsize = LIST_INIT_SIZE;
            Merge(La,Lb,Lc);//提示信息
            cout<<"输入你要进行操作的相应数字:";
            cin>>i;
            break;
        default:
            if(i <0)
                return 0;
            else
            {
                cout<<"输入数字非法，请重新输入：";
                cin>>i;
            }
            break;
        }
    }

    return 0;
}

void Tips()
{
    cout << "1-----清空线性表" << endl;
    cout << "2-----判断线性表是否为空" << endl;
    cout << "3-----求线性表长度" << endl;
    cout << "4-----销毁线性表" << endl;
    cout << "5-----获取线性表中与所对比数据相同的位置" << endl;
    cout << "6-----以e代替线性表指定位置元素" << endl;
    cout << "7-----求前驱" << endl;
    cout << "8-----求后继" << endl;
    cout << "9-----在线性表指定位置插入元素 "<< endl;
    cout << "10-----删除空线性表指定位置元素" << endl;
    cout << "11-----显示线性表" << endl;
    cout << "12----显示提示信息"<< endl;
    cout << "13----合并线性表"<< endl;
    cout << "   退出,输入一个负数！" << endl;

}
