#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
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

