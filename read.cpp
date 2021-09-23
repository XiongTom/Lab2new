#include<iostream>
#include<cmath>
#include<cstring>
#include <fstream>
#include <vector>
#include <stack>>
using namespace std;
int main()
{
	//read each line from the file and store it in the vector
	cout<<"please enter the file name:"<<endl;           
	string file_name;                                    
	cin>>file_name;    //get the file name
	int level;
	cout<<"please enter the level:"<<endl;
	cin>>level;       //get the level
	ifstream file;    //open the file
    file.open(file_name);	
    string line;
    if(!file){
    	cout<<"wrong"<<endl;
	}else{
		while(getline(file,line)){
			getl.push_back(line);     //line by line, the contents of the file are stored in the getL (Vector) memory
		}
		file.close();
	}
	 //the main function:
	 clear();
	  countwords();
	  findswitchcase();
	  findifelse(level);
	return 0;
}
