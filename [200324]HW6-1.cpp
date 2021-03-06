#include <iostream>
#include <vector>
#include<sstream>
#include <algorithm>

using namespace std;

int main() {
	vector<string> data;
	vector<vector<string> > rows;
	int i;	
	string data1, input, tmp;
	int qty;
	stringstream ss;
	
	getline(cin,input);
	ss<<input;
	ss>>i;
	rows.reserve(i);
	data.reserve(3);

	for(int j=0;j<i&&j<1000;j++){
		getline(cin, input);
		tmp.clear();
		int l = 0;
        int is=input.size();
		for (int k=0; k<is; k++){
			if (input[k]==' '){
    			ss.clear();
				ss<<tmp;
				ss>>data1;
				if (l==0){
            		data.clear();		
					data.push_back(data1);
					l++;
				} else if (l==1){
					data.push_back(data1);
					l++;
				} else if (l==2){
					data.push_back(data1);
					l++;
				}
				tmp.clear();
			} else {
                tmp+=input[k];
            }
		}
		if (rows.size()==i-1){
			ss.clear();
			ss<<tmp;
			ss>>data1;
			data.push_back(data1);
		}
		rows.push_back(data);
	}
	//cout<<rows.size()<<endl;

	while(!rows.empty()){
		//cout<<"loop start:"<<rows.size()<<endl;
		bool place_not_found=false;
		bool animal_not_found=false;
		while(!place_not_found){
			vector<vector<string> >::iterator it;
			it=rows.begin();
			data=*it;
			string place=data[2];
			string animal=data[0];
			int count = 0;
			int rs=rows.size();
			if (i>rs){
				cout<<endl;
			}
			cout<<place<<":"<<animal<<" ";
			ss.clear();
			ss<<data[1];
			ss>>qty;
			count+=qty;
			rows.erase(it);
			animal_not_found=false;
			while(!animal_not_found){
				//system("pause");
				for (it=rows.begin(); it!=rows.end(); it++){
					data=*it;
					//cout<<data[0]<<"-"<<data[1]<<"-"<<data[2]<<"|"<<place<<"|"<<animal<<"|"<<count<<"|"<<rows.size()<<endl;
					if (data[2]==place&&data[0]==animal){
						ss.clear();
						ss<<data[1];
						ss>>qty;
						count+=qty;
						rows.erase(it);
						if (rows.size()>0)
							it--;
					}
					if (it==rows.end()){
						break;
					}
				}
				animal_not_found=true;	
				if (count>0){
					cout<<count;
					count=0;
					animal="";
				}
				for (it=rows.begin(); it!=rows.end(); it++){
					data=*it;
					if (place==data[2]&&animal==""){
						cout<<", "<<data[0]<<" ";
						animal=data[0];
						animal_not_found=false;
						ss.clear();
						ss<<data[1];
						ss>>qty;
						count=qty<=100?qty:100;
						rows.erase(it);
						rows.resize(rows.size());
					}
					if (it==rows.end()){
						break;
					}					
				}
			}
			if (rows.empty()){
				place_not_found=true;
			}
		}
	}	
	cout<<endl;
	return 0;
}
