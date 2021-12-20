#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>
#include <map>

using namespace std;



struct ruler{
	vector<int> n;
	long long int conlusion; 
	double Hvalue;
	double Evalue;
	double HEvalue;
	int book=0;
};
struct ff{
	int n;
	double value;
	int book=0;
};

class RulerBase{
	
	
	////���Ŷ� 0-1 
	/******************************************* 
	/Ѧ�����˹�������ҵ 
	��֪��һ�¹��� 
	R1��������ë�� ������ 1-> 21 (0.7)
	R2��������� �� ������ 2->21 (1)
	R3����������ë �� ���� 3->23 (0.6)
	R4�������� �Ļ��µ� �� ���� 4,5->23 (0.8)
	R5��������Ķ������� ʳ���� 21,7->22 (0.9)
	R6��������Ȯ�� ����צ ���۶�ǰ������ʳ�� 8,9,10->22 (0.7)
	R7�������� ������ ������ 21,11->24 (0.6)
	R8�������� �ķ�ۻ �� ���� 21,6->24 (0.7)
	R9��ʳ���� �� �ƺ�ɫ �� �аߵ�� ��Ǯ�� 22,16,17->A (0.6)
	R10��ʳ���� �� �ƺ�ɫ �� �к�ɫ���ơ��� 22,16,18->B (0.6)
	R11������ �� ���� �� ���� �� �аߵ�� ����¹ 24,19,20,17->C (0.7)
	R12������ ��  �к�ɫ���ơ� ���� 24,18->D (0.6)
	R13������ �ĳ��� �� ���� �� ����� ������ 23,19,20,12->E (0.8)
	R14������ �Ļ���Ӿ �ĺڰ׶�ɫ �� ����� ����� 23,13,14,12->F (0.9)
 	R15������ ���Ʒ� �������� 23,15->G (0.6)
	
	1-> 21 (0.7)
	2->21 (1)
	3->23 (0.6)
	4,5->23 (0.8)
	21,7->22 (0.9)
	8,9,10->22 (0.7)
	21,11->24 (0.6)
	21,6->24 (0.7)
	
	22,16,17->A (0.6)
	22,16,18->B (0.6)
	24,19,20,17->C (0.7)
	24,18->D (0.6)
	23,19,20,12->E (0.8)
	23,13,14,12->F (0.9)
	23,15->G (0.6)
	
	
	
	1:������ë
	2���������
	3����������ë
	4��������
	5�����µ�
	6����ۻ
	7���������
	8: ������Ȯ��
	9: ��צ
	10: �۶�ǰ��
	11: ����
	12: �����
	13: ����Ӿ
	14: �ڰ׶�ɫ
	15: �Ʒ�
	16:�ƺ�ɫ
	17:�аߵ�
	18:�к�ɫ����
	19:����
	20:����
	---------------------
	21:������
	22:ʳ����
	23:����
	24:����
	---------------------
	A:��Ǯ��
	B:��
	C:����¹
	D:����
	E:����
	F:���
	G:������ 
	
    **************************************/
    public:
    	vector<ruler> R;
    	//vector<ruler>::iterator it;//������
		RulerBase();
    	//int search(long long int temp);
    

}; 
RulerBase::RulerBase()
{
	
    ruler t;
    
    	//1---------------------
    t.n.push_back(1);
    t.conlusion=21;
    t.HEvalue=0.7;
    this->R.push_back(t);
    t.n.clear();
		//2---------------------
    t.n.push_back(2);
    t.conlusion=21;
    t.HEvalue=1;
    this->R.push_back(t);
    t.n.clear();
    	//3---------------------
    t.n.push_back(3);
    t.conlusion=23;
    t.HEvalue=0.6;
    this->R.push_back(t);
    t.n.clear();
		//4---------------------
    t.n.push_back(4);
	t.n.push_back(5);
    t.conlusion=23;
    t.HEvalue=0.8;
    this->R.push_back(t);
    t.n.clear();
    	//5---------------------
    t.n.push_back(7);
	t.n.push_back(21);
    t.conlusion=22;
    t.HEvalue=0.9;
    this->R.push_back(t);
    t.n.clear();
    	//6---------------------
    t.n.push_back(8);
	t.n.push_back(9);
	t.n.push_back(10);
    t.conlusion=22;
    t.HEvalue=0.7;
    this->R.push_back(t);
    t.n.clear();
    	//7---------------------
    t.n.push_back(11);
	t.n.push_back(21);
    t.conlusion=24;
    t.HEvalue=0.6;
    this->R.push_back(t);
    t.n.clear();
    	//8---------------------
    t.n.push_back(6);
	t.n.push_back(21);
    t.conlusion=24;
    t.HEvalue=0.7;
    this->R.push_back(t);
    t.n.clear();
    
    	//9--------------------- ���ս����ø�����ʾ 
	t.n.push_back(16);
	t.n.push_back(17);
	t.n.push_back(22);

    t.conlusion=0-'A';
    t.HEvalue=0.6;
    this->R.push_back(t);
    t.n.clear();
    	//---------------------
	t.n.push_back(16);
	t.n.push_back(18);
	t.n.push_back(22);

    t.conlusion=0-'B';
    t.HEvalue=0.6;
    this->R.push_back(t);
    t.n.clear();
    	//---------------------
		//Ѧ�����˹�������ҵ 
    t.n.push_back(17);
    t.n.push_back(19);
    t.n.push_back(20);
    t.n.push_back(24);
    t.conlusion=0-'C';
    t.HEvalue=0.7;
    this->R.push_back(t);
    t.n.clear();
    	//---------------------
    t.n.push_back(18);
    t.n.push_back(24);
    t.conlusion=0-'D';
    t.HEvalue=0.6;
    this->R.push_back(t);
    t.n.clear();
    	//---------------------
    
    t.n.push_back(12);
    t.n.push_back(19);
    t.n.push_back(20);
    t.n.push_back(23);
    t.conlusion=0-'E';
    t.HEvalue=0.8;
    this->R.push_back(t);
    t.n.clear();
    	//---------------------
    t.n.push_back(12);
    t.n.push_back(13);
    t.n.push_back(14);
    t.n.push_back(23);
    
    t.conlusion=0-'F';
    t.HEvalue=0.9;
    this->R.push_back(t);
    t.n.clear();
    	//---------------------
    t.n.push_back(15);
    t.n.push_back(23);
    t.conlusion=0-'G';
    t.HEvalue=0.6;
    this->R.push_back(t);
    t.n.clear();
};

/*
RulerBase::search(long long int temp)
{
	for(vector<ruler>::iterator it=this->R.begin(); it!= this->R.end(); ++it)
	{
		/Ѧ�����˹�������ҵ 
	}
	return 0;
}
*/

class Fact{
	public: 
		vector<ff> fact;
		//Fact();
		vector<int> data;
		vector<double> value;
		void rebuild(void);
	
};

/*Fact::Fact(){
	return;
}*/
void Fact::rebuild(void)
{
	data.clear();
	value.clear();
	for(vector<ff>::iterator it=this->fact.begin(); it!=this->fact.end(); ++it)
	{
		data.push_back(it->n);
		value.push_back(it->value);
	}	
}

bool compare(ff a,ff b)
{
 return a.n < b.n ;
}




ff isSubset(vector<int> v1, vector<int> v2,double v1value,vector<double> v2value,long long int conlusion) ///�ж�vector�Ӽ�  V1����  V2��ʵ  v2value ��ʵ�����Ŷ�  v1value��������Ŷ� 
{
	double min =100; ///��С���Ŷ�
	double minvalue =100; ///���ý��۵����Ŷ� 
	int  sum=0;
	int x,c,y; 
	int i=0,j=0;
	int m=v1.size();// m�� ����ĳ��� 
	int n=v2.size(); //n �� ��ʵ �ĳ��� 
	/*if(m<n){
		return 0;
	}*///Ѧ�����˹�������ҵ 
	//sort(v1.begin(),v1.end());
	//sort(v2.begin(),v2.end());
	while(j<m&&i<n){
		if(v1[j]<v2[i]){
			j++;
		}
		else if(v1[j]==v2[i]){
		
			if(min>=v2[i])
			{
				min = v2value[i];
			}
			j++;
			i++;
			
			sum++;
		}
		else if(v1[j]>v2[i]){
			i++; 
		}
	}
	ff t;
	if(sum==m){
		
		t.n=conlusion;
		t.value=min*v1value;
		return t;
	}
	else{
		t.n=conlusion;
		t.value=0;
		return t;
	}
}



int main(void)
{
	/********
	* A:��Ǯ��
	* B:��
	* C:����¹
	* D:����
	* E:����
	* F:���
	* G:������
	/Ѧ�����˹�������ҵ 
	**********/
	std::map<int,string> mymap;
	mymap['A'] = "��Ǯ��";
  	mymap['B'] = "��";
  	mymap['C'] = "����¹";
  	mymap['D'] = "����";
  	mymap['E'] = "����";
  	mymap['F'] = "���";
	mymap['G'] = "������";

  	
	RulerBase r;
	Fact fa;
	
	cout<<"1:������ë\n2���������\
	\n3����������ë\n4��������\n5�����µ�\n6����ۻ\n7���������\n8: ������Ȯ��\n9: ��צ\n10: �۶�ǰ��\n11: ����\n12: �����\n13: ����Ӿ\
	\n14: �ڰ׶�ɫ\n15: �Ʒ�\n16:�ƺ�ɫ\n17:�аߵ�\n18:�к�ɫ����\n19:����\n20:����\n";
	cout<<"���� ���� ���Ŷ�( -1 -1 ����)\n" ;
	
	
	long long int a;
	double b;	
	ff t;
	
	while((cin>>a>>b)&&a>0)
	{

		//Ѧ�����˹�������ҵ 
		t.n=a;
		t.value=b;
		fa.fact.push_back(t);
		
	 }
	 sort(fa.fact.begin(),fa.fact.end(),compare);
	 fa.rebuild();
	
	/*
	cout<<"-----------------------"<<endl;
	for(vector<ruler>::iterator it=r.R.begin(); it!=r.R.end(); ++it)
	{
		cout<<it->conlusion<<endl;/Ѧ�����˹�������ҵ 
	}
	cout<<"--------------------------"<<endl;
	for(vector<ff>::iterator it=fa.fact.begin(); it!=fa.fact.end(); ++it)
	{
		cout<<it->n<<endl;
	}
	*/
	int flag =0; 
	do
	{
		flag=0;
	for(vector<ruler>::iterator it=r.R.begin(); it!=r.R.end(); ++it)//ȡ��һ������ 
	{
		if(it->book==0) 
		{
			
			ff num = isSubset(it->n, fa.data,it->HEvalue,fa.value,it->conlusion);
			///�ж�vector�Ӽ�  V1����  V2��ʵ  v2value ��ʵ�����Ŷ�  v1value��������Ŷ� 
			if(num.value!=0)
			{
				flag=1;
				fa.fact.push_back(num);
				sort(fa.fact.begin(),fa.fact.end(),compare);
	 			fa.rebuild();
	 			it->book=1;
				if(num.n<0)
				{
					cout<<"��������ǣ�"<<mymap[(char)-num.n]<<"  ���Ŷ��ǣ�"<<num.value<<" \n";
					return 0;
				}
			}

		//Ѧ�����˹�������ҵ 
		}
	}
	}while(flag!=0);
	
	cout<<"ϵͳ�ڲ����ڸö������";
	return 0;
}
