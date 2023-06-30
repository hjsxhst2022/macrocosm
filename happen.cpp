#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main(){
	system("title happen");
	while(1){
		fstream r1;
		r1.open("D:\\yz\\happen.data");
		if(!r1.is_open()){
			printf("文件不存在\n");
			system("pause");
			exit(-1);
		}
		while(!r1.eof()){
			string a;
			r1>>a;
			printf("%s\n",&a[0]);
		}
		r1.clear();
		sleep(1);
		system("cls");
	}
}
