#include<iostream>
#include<string.h>
#include<stdio.h> 
#include<stdlib.h>
 
using namespace std;

//int *inputscore(){
//	int arr[100];
//	int a,index = 0;
//	while(cin>>a){
//    	arr[index++] = a;
//    	char ch = getchar();
//    	if(ch == '\n')
//    		break;
//    }
//    
//    for(int i=0;i<index;i++)
//    	cout<<arr[i]<<" ";
//    cout<<endl;
// 
//	return arr;
//}
 
int main(){
	int count = 0;
	char strScore[100];
	int score[50];
	int n = 0;
	char ss[2];
	
	cout<<"�п�J���Z�ռ�:";
	cin>>count;
	 
	for (int k=0; k<count; k++){
		n = 0;
		cout<<"�п�J��"<<(k+1)<<"�զ��Z,���Ϊťչj�}"<<endl;
		do
		{
			cin>>ss;
			if (getchar()!='\n')
				score[n] = atoi(ss);
			n++;		
			cout<<k<<"|"<<n<<":"<<score[n]<<"|"<<ss<<endl;
		} while (getchar()!='\n'); 
	}
		 

    for(int j=0;j<count;j++)
    	cout<<score[j]<<" ";
    cout<<endl;
 
	return 0;
}


