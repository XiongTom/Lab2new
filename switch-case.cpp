#include<iostream>
#include<cmath>
#include<cstring>
void findswitchcase(){
	string line;
	int f=-1;               
	size_t sfind,cfind;
	int s=0,c[100]={0};             //s is for counting switch; c[100] is for counting case;
	for(int i=0;i<getl.size();i++){
		line=getl[i];
		sfind=line.find("switch");
		cfind=line.find("case");
		if(sfind!=line.npos){
			s=s+1;
			f=f+1;
		}
		if((cfind!=line.npos)&&(f>=0)){    //if there is one "switch" then we count the case number in that "switch"
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

