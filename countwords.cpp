#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
string keyword[32]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if",
	"int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volarile","while"};
	//list all the key words in keyword
void countwords(){
	string line;
	int sum=0;        
	for(int i=0;i<getl.size();i++){
		line=getl[i];   
		for(int j=0;j<32;j++){      
			size_t a=line.find(keyword[j],0);     //Iterate over all the words in the keyword, incrementing the count if they exist
			if(a!=line.npos){
				sum++;                            
			}
		}
	}
	cout<<sum<<endl;
}
