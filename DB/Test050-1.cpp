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


typedef struct  //����ṹ��
{
    int *elem;
    int length;
    int listsize;
}SqList;

SqList L;
SqList La;
SqList Lb;
SqList Lc;
Status InitList(SqList &L)//˳���ĳ�ʼ��
{
	L.elem=new int[LIST_INIT_SIZE];   //Ϊ˳������ռ�
    if(!L.elem) exit(OVERFLOW);           //�洢����ʧ��
    L.length = LIST_INIT_SIZE;
    L.listsize = LIST_INIT_SIZE;
    for(int i=0;i<8;i++)
    {
    	cin>>L.elem[i];
	}
    return OK;
}
Status ListLength(SqList &L) //˳���ĳ��ȣ�����cout��printf���
{	
	cout<<"��˳���ĳ���Ϊ:"<<L.length<<endl;
    return OK;
}
Status EmptyList(SqList &L)//�ж�˳����Ƿ�Ϊ�գ�Length�Ƿ�Ϊ0
{
	if(L.length!=0){
		cout<<"��˳���Ϊ��"<<endl;
	}
	else{
		cout<<"��˳���Ϊ��"<<endl;
	}
    return OK;
}
Status ClearList(SqList &L)//˳������գ�length��Ϊ0
{
	if(L.length!= 0)
	{
		L.length=0;
		cout<<"˳�����ճɹ�"<<endl; 
	}
	else
	{
		cout<<"��˳�����Ϊ�գ������³�ʼ����"<<endl; 
		InitList(L); 
	}
    return OK;
}
Status DestroyList(SqList &L)  //�ݻٸ���L������ڴ棬����delete����free��������ڴ汣��һ�� 
{
	if(L.elem)
	{
		delete []L.elem;
		cout<<"���Ա�ݻٳɹ��������³�ʼ��"<<endl;
		return OK;
	}
	else
	{
		cout<<"��˳�����Ϊ�գ��޷����дݻ�"<<endl; 
		return OK;
	}
}
Status LocateList(SqList L, int e, int &pos) //�ҳ���e��ȵĵ�һ��λ�ã���������pos��
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
		cout<<"��һ����e��ȵ�λ��Ϊ:"<<pos<<endl;	
	}
	else
	{
		cout<<"δ�ҵ���e��ȵ�λ��"<<endl;
	}
    return OK;
}
Status PointList(SqList &L, int i, int &e) //��ȡָ��λ�õ�˳���Ԫ�ظ�ֵ��e������cout��printf���
{
	L.elem[i-1]=101;
	cout<<"��ֵ��Ľ��Ϊ��"<<endl;
	cout<<L.elem[i-1];
    return OK;
}
Status BeforPoint(SqList &L,int i)//��˳����ǰ��cout��printf��������ж�λ���Ƿ�Ϸ����Ƿ���ǰ����
{
	if(i==1)
	{
		cout<<"��λ���Ѿ�λ�ڱ�ͷ����ǰ��"<<endl;
	}
	else
	 {
	 	cout<<"��λ�õ�ǰ����:"<<L.elem[i-2]<<endl;
	 }
    return OK;
}
Status AfterPoint(SqList &L,int i)//��˳���ĺ��
{
	if(i==L.length)
	{
		cout<<"��λ���Ѿ�λ�ڱ�β���޺��"<<endl;
	}
	else
	 {
	 	cout<<"��λ�õĺ����:"<<L.elem[i]<<endl;
	} 
    return OK;
}
Status InsertList(SqList &L,int i,int x)//˳���λ��i������Ԫ��x�����ж�λ��i�Ƿ�Ϸ�
{
	if(i<=100)
	{
		int	j=L.length;
		for(;j>=i-1;j--)
		{
			L.elem[j+1]=L.elem[j];
		}
		L.elem[i-1]=x;
		cout<<"����ɹ������������"<<endl; 
	}
	else
	{
		cout<<"�ܱ�Ǹ������λ�ó������鳤�ȣ������³���"<<endl;
	}
    return OK;
}

Status DeleteList(SqList &L,int i)//ɾ��ָ��λ�õ�Ԫ��
{
	int j=L.length;
	if(i<=100)
	{
		for(;i<=j;i++)
		{
			L.elem[i-1]=L.elem[i];
		}
		cout<<"ɾ���ɹ������������"<<endl; 
	}
	else
	{
		cout<<"�ܱ�Ǹ��ɾ��λ�ó������鳤�ȣ������³���"<<endl;
	}
    return OK;

}
Status Display(SqList &L)//��ʾ˳�������ݣ��ձ���ʾ������ʾ����
{
	cout<<"��ǰ���Ա������Ϊ��"<<endl;
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<"   ";
	}
	cout<<endl;
	return OK;
}
Status Merge(SqList La, SqList Lb, SqList &Lc)//�ϲ����Ա� 
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
void Tips();//������ʾ��Ϣ

int main()
{
    Tips();//������ʾ��Ϣ
    InitList(La);//��ʼ�����Ա�
    InitList(Lb);
    // int condition; //��ȡ�������ص�����
    int h,k;//�ֱ�������ȡ�����ָ��λ�úͲ������ݵ�Ԫ��
    int i;//���������
    cout<<"������Ҫ���в�������Ӧ����:";
    cin>>i;

    while(true)
    {
        switch(i)//�ж������iֵ
        {
        case 1:
            ClearList(L);//���˳���
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 2:
            EmptyList(L);//�ж�˳����Ƿ�Ϊ��
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 3:
            ListLength(L);//��˳���ĳ���
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 4:
            DestroyList(L);//�ݻ�˳��� 
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 5:
            int pos;
            LocateList(L,h,pos);//��ȡ˳���ָ��λ�õ�Ԫ��
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;

        case 6:
            cout<<"����ָ��λ��:";
            cin>>h;
            int e;
            PointList(L,h,e);//��ȡ˳���ָ��λ�õ�Ԫ��
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 7:
            cout<<"����ָ��λ��:";
            cin>>h;
            BeforPoint(L,h);//��ǰ��
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 8:
            cout<<"����ָ��λ��:";
            cin>>h;
            AfterPoint(L,h);//����
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 9:
            cout<<"����ָ��λ��:";
            cin>>h;
            cout<<"����������ֵ:";
            cin>>k;
            InsertList(L,h,k);//��˳���ָ��λ�ò�������
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 10:
            cout<<"����ָ��λ��:";
            cin>>h;
            DeleteList(L,h);//��˳����ָ��λ��ɾ������
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 11:
            Display(La);//��ʾ˳����Ԫ��
            Display(Lb);
            Display(Lc);
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 12:
            Tips();//��ʾ��Ϣ
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        case 13:
            Lc.elem=new int[LIST_INIT_SIZE];
            Lc.length = LIST_INIT_SIZE;
   			Lc.listsize = LIST_INIT_SIZE;
            Merge(La,Lb,Lc);//��ʾ��Ϣ
            cout<<"������Ҫ���в�������Ӧ����:";
            cin>>i;
            break;
        default:
            if(i <0)
                return 0;
            else
            {
                cout<<"�������ַǷ������������룺";
                cin>>i;
            }
            break;
        }
    }

    return 0;
}

void Tips()
{
    cout << "1-----������Ա�" << endl;
    cout << "2-----�ж����Ա��Ƿ�Ϊ��" << endl;
    cout << "3-----�����Ա���" << endl;
    cout << "4-----�������Ա�" << endl;
    cout << "5-----��ȡ���Ա��������Ա�������ͬ��λ��" << endl;
    cout << "6-----��e�������Ա�ָ��λ��Ԫ��" << endl;
    cout << "7-----��ǰ��" << endl;
    cout << "8-----����" << endl;
    cout << "9-----�����Ա�ָ��λ�ò���Ԫ�� "<< endl;
    cout << "10-----ɾ�������Ա�ָ��λ��Ԫ��" << endl;
    cout << "11-----��ʾ���Ա�" << endl;
    cout << "12----��ʾ��ʾ��Ϣ"<< endl;
    cout << "13----�ϲ����Ա�"<< endl;
    cout << "   �˳�,����һ��������" << endl;

}
