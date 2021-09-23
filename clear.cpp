#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void clear(){
	string line,c;    
	int i=0;
	size_t a=0,k=0;    
	for(i=0;i<getl.size();i++){
		line=getl[i];              //each row is stored in line
		if(line.find("//")!=line.npos){
			a=line.find("//");      
			if(a==0){              //if the // annotation is at the beginning, delete the entire line of comments 
				getl.erase(getl.begin()+i);
				i-=1;
			}else{
				getl[i]=line.substr(0,a);      //if not, save everything before the // symbol 
			}
		}else if(line.find("/*")!=line.npos){
			a=line.find("/*");
			k=line.find("*/");
			if(k!= line.npos){                //if the annotation is on a line, save the content up to /*
				getl[i]=line.substr(0,a);
			}else{
				getl[i]=line.substr(0,a);     //if it is a multi-line comment, delete it line by line
				a=i+1;
				line=getl[a];
				while(line.find("*/"==line)){
					getl.erase(getl.begin()+a);
					line=getl[a];
				}
				i=a; 
			}
		}else if(line.find("\"")!=line.npos){
			size_t s[100];                    //store the location where "appears
			int x=0,y=0;
			while((a=line.find("\"",x))!=line.npos){
				s[y]=a;
				y=y+1;
				x=a+1;
			}
			getl[i]=line.substr(0,s[0]);      
			for(int j=0;s[j]!=0;j+=2){
				getl[i]=getl[i]+line.substr(s[j],s[j+1]-s[j]);   //Delete the text between two "symbols
			}
		} 
	}
}

