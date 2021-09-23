#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void findifelse(int level){
    int sum1=0,sum2=0;
    string line;
    stack<int> stk;                    //Use stacks for different situations
    for(int i=0;i<getl.size();i++){
    	line=getl[i];
    	if((line.find("if")!=line.npos)&&(line.find("else")==line.npos)){             //when the line only have "if" then in the stack
    		stk.push(0);                                                              //"if else" case
		}else if((line.find("if")==line.npos)&&(line.find("else")!=line.npos)&&(stk.empty()==false)){     //when only have "else" and there is a num in the stack
			if(stk.top()==0){                                                                  
				sum1++;                                                                        //if the num of the top of stack is 0,it is the if-else condition 
			}else if(stk.top()==1){
				sum2++;                                                                        //if the num of the top of stack is 1,it is the if-else if-else condition
			}
			stk.pop();                                                                //Out of the stack
		}else if((line.find("if")!=line.npos)&&(line.find("else")!=line.npos)){        // if  "if" and "else" are both in a line then stack in "if-else if-else" condition
			stk.push(1);
		}
	}
	if(level==3){                       //different level output different thing
	    cout<<"if else :"<<sum1<<endl;
    }else if(level==4){
     	cout<<"if else : "<<sum1<<endl;
    	cout<<"if else if else : "<<sum2<<endl;
}
}


