#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
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


