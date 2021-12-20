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
	
	
	////置信度 0-1 
	/******************************************* 
	/薛辰宇人工智能作业 
	已知有一下规则 
	R1：动物有毛→ 哺乳类 1-> 21 (0.7)
	R2：动物产奶 → 哺乳类 2->21 (1)
	R3：动物有羽毛 → 鸟类 3->23 (0.6)
	R4：动物会飞 ∧会下蛋 → 鸟类 4,5->23 (0.8)
	R5：哺乳类∧动物吃肉→ 食肉类 21,7->22 (0.9)
	R6：动物有犬齿 ∧有爪 ∧眼盯前方→肉食类 8,9,10->22 (0.7)
	R7：哺乳类 ∧有蹄 →蹄类 21,11->24 (0.6)
	R8：哺乳类 ∧反刍 → 蹄类 21,6->24 (0.7)
	R9：食肉类 ∧ 黄褐色 ∧ 有斑点→ 金钱豹 22,16,17->A (0.6)
	R10：食肉类 ∧ 黄褐色 ∧ 有黑色条纹→虎 22,16,18->B (0.6)
	R11：蹄类 ∧ 长脖 ∧ 长腿 ∧ 有斑点→ 长颈鹿 24,19,20,17->C (0.7)
	R12：蹄类 ∧  有黑色条纹→ 斑马 24,18->D (0.6)
	R13：鸟类 ∧长脖 ∧ 长腿 ∧ 不会飞 →鸵鸟 23,19,20,12->E (0.8)
	R14：鸟类 ∧会游泳 ∧黑白二色 ∧ 不会飞 →企鹅 23,13,14,12->F (0.9)
 	R15：鸟类 ∧善飞 →信天翁 23,15->G (0.6)
	
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
	
	
	
	1:动物有毛
	2：动物产奶
	3：动物有羽毛
	4：动物会飞
	5：会下蛋
	6：反刍
	7：动物吃肉
	8: 动物有犬齿
	9: 有爪
	10: 眼盯前方
	11: 有蹄
	12: 不会飞
	13: 会游泳
	14: 黑白二色
	15: 善飞
	16:黄褐色
	17:有斑点
	18:有黑色条纹
	19:长脖
	20:长腿
	---------------------
	21:哺乳类
	22:食肉类
	23:鸟类
	24:蹄类
	---------------------
	A:金钱豹
	B:虎
	C:长颈鹿
	D:斑马
	E:鸵鸟
	F:企鹅
	G:信天翁 
	
    **************************************/
    public:
    	vector<ruler> R;
    	//vector<ruler>::iterator it;//迭代器
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
    
    	//9--------------------- 最终结论用负数表示 
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
		//薛辰宇人工智能作业 
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
		/薛辰宇人工智能作业 
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




ff isSubset(vector<int> v1, vector<int> v2,double v1value,vector<double> v2value,long long int conlusion) ///判断vector子集  V1规则  V2事实  v2value 事实的置信度  v1value规则的置信度 
{
	double min =100; ///最小置信度
	double minvalue =100; ///所得节论的置信度 
	int  sum=0;
	int x,c,y; 
	int i=0,j=0;
	int m=v1.size();// m是 规则的长度 
	int n=v2.size(); //n 是 事实 的长度 
	/*if(m<n){
		return 0;
	}*///薛辰宇人工智能作业 
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
	* A:金钱豹
	* B:虎
	* C:长颈鹿
	* D:斑马
	* E:鸵鸟
	* F:企鹅
	* G:信天翁
	/薛辰宇人工智能作业 
	**********/
	std::map<int,string> mymap;
	mymap['A'] = "金钱豹";
  	mymap['B'] = "虎";
  	mymap['C'] = "长颈鹿";
  	mymap['D'] = "斑马";
  	mymap['E'] = "鸵鸟";
  	mymap['F'] = "企鹅";
	mymap['G'] = "信天翁";

  	
	RulerBase r;
	Fact fa;
	
	cout<<"1:动物有毛\n2：动物产奶\
	\n3：动物有羽毛\n4：动物会飞\n5：会下蛋\n6：反刍\n7：动物吃肉\n8: 动物有犬齿\n9: 有爪\n10: 眼盯前方\n11: 有蹄\n12: 不会飞\n13: 会游泳\
	\n14: 黑白二色\n15: 善飞\n16:黄褐色\n17:有斑点\n18:有黑色条纹\n19:长脖\n20:长腿\n";
	cout<<"输入 条件 置信度( -1 -1 结束)\n" ;
	
	
	long long int a;
	double b;	
	ff t;
	
	while((cin>>a>>b)&&a>0)
	{

		//薛辰宇人工智能作业 
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
		cout<<it->conlusion<<endl;/薛辰宇人工智能作业 
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
	for(vector<ruler>::iterator it=r.R.begin(); it!=r.R.end(); ++it)//取出一条规则 
	{
		if(it->book==0) 
		{
			
			ff num = isSubset(it->n, fa.data,it->HEvalue,fa.value,it->conlusion);
			///判断vector子集  V1规则  V2事实  v2value 事实的置信度  v1value规则的置信度 
			if(num.value!=0)
			{
				flag=1;
				fa.fact.push_back(num);
				sort(fa.fact.begin(),fa.fact.end(),compare);
	 			fa.rebuild();
	 			it->book=1;
				if(num.n<0)
				{
					cout<<"这个动物是："<<mymap[(char)-num.n]<<"  置信度是："<<num.value<<" \n";
					return 0;
				}
			}

		//薛辰宇人工智能作业 
		}
	}
	}while(flag!=0);
	
	cout<<"系统内不存在该动物！！！";
	return 0;
}
