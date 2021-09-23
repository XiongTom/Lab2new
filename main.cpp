#include<iostream>
#include<cmath>
#include<cstring>
#include <fstream>
#include <vector>
#include <stack>>
using namespace std;
vector<string> getl;
void clear(){
	string line,c;
	int i=0;
	size_t a=0,k=0;
	for(i=0;i<getl.size();i++){
		line=getl[i];
		if(line.find("//")!=line.npos){
			a=line.find("//");
			if(a==0){
				getl.erase(getl.begin()+i);
				i-=1;
			}else{
				getl[i]=line.substr(0,a);
			}
		}else if(line.find("/*")!=line.npos){
			a=line.find("/*");
			k=line.find("*/");
			if(k!= line.npos){
				getl[i]=line.substr(0,a);
			}else{
				getl[i]=line.substr(0,a);
				a=i+1;
				line=getl[a];
				while(line.find("*/"==line)){
					getl.erase(getl.begin()+a);
					line=getl[a];
				}
				i=a; 
			}
		}else if(line.find("\"")!=line.npos){
			
		}
	}
}
string keyword[32]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if",
	"int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volarile","while"};
void countwords(){
	string line;
	int sum=0;
	for(int i=0;i<getl.size();i++){
		line=getl[i];
		for(int j=0;j<32;j++){
			size_t a=line.find(keyword[j],0);
			if(a!=line.npos){
				sum++;
			}
		}
	}
	cout<<sum<<endl;
}
void findswitchcase(){
	string line;
	int f=-1;
	size_t sfind,cfind;
	int s=0,c[100]={0};
	for(int i=0;i<getl.size();i++){
		line=getl[i];
		sfind=line.find("switch");
		cfind=line.find("case");
		if(sfind!=line.npos){
			s=s+1;
			f=f+1;
		}
		if((cfind!=line.npos)&&(f>=0)){
			c[f]+=1; 
		}
	}
	cout<<"switch num:"<<s<<endl;
	cout<<"case num:";
	for(int i=0;i<=f;i++){
		cout<<" "<<c[i];
		cout<<endl;
	}
}
void findifelse(int level){
    int sum1=0,sum2=0;
    string line;
    stack<int> stk;
    for(int i=0;i<getl.size();i++){
    	line=getl[i];
    	if((line.find("if")!=line.npos)&&(line.find("else")==line.npos)){
    		stk.push(0);
		}else if((line.find("if")==line.npos)&&(line.find("else")!=line.npos)&&(stk.empty()==false)){
			if(stk.top()==0){
				sum1++;
			}else if(stk.top()==1){
				sum2++;
			}
			stk.pop();
		}else if((line.find("if")!=line.npos)&&(line.find("else")!=line.npos)){
			stk.push(1);
		}
	}
	if(level==3){
	    cout<<"if else :"<<sum1<<endl;
    }else if(level==4){
     	cout<<"if else : "<<sum1<<endl;
    	cout<<"if else if else : "<<sum2<<endl;
}
}

int main()
{
	//从文件中读取每一行并且存入vector中 
	cout<<"please enter the file name:"<<endl;           
	string file_name;                                    
	cin>>file_name;
	int level;
	cout<<"please enter the level:"<<endl;
	cin>>level;
	ifstream file; 
    file.open(file_name);	
    string line;
    if(!file){
    	cout<<"wrong"<<endl;
	}else{
		while(getline(file,line)){
			getl.push_back(line);
		}
		file.close();
	}
	//处理符号和备注
	 clear();
	  countwords();
	  findswitchcase();
	  findifelse(level);
	return 0;
}

