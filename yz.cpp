#pragma GCC optimize(3)//���ײ����note.ms/yzerrno note.ms/yzsome(ͷ�ļ�) note.ms/yzhappen(��¼�����¼�)
#include<bits/stdc++.h>//�����˸����˸�����qwq
#include<unistd.h>//https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&srcqid=7583488485642553692&tn=50000021_hao_pg&wd=c%2B%2B%E5%A6%82%E4%BD%95%E5%81%9A%E5%AE%89%E8%A3%85%E5%8C%85&oq=c%252B%252B%25E5%25A6%2582%25E4%25BD%2595%25E5%2581%259A%25E5%25AE%2589%25E8%25A3%2585%25E5%258C%2585&rsv_pq=832f1453000156ce&rsv_t=ba5f%2BGkSbJqh%2BWbLEwO%2F%2BzFdYMa%2FPSFmPKe1tlQtI1BtcCvJo%2FxWvDa%2Fm%2FvcevEdyUXcNk2b&rqlang=cn&rsv_enter=0&rsv_dl=tb&rsv_btype=t
#include<windows.h>
#include<bitset>
#include"some.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define ull unsigned long long
#define D3 300
using namespace std;
double sdx=0,sdy=0,sdz=0;//�ӵ�x���ӵ�y���ӵ�z
ull xsfw=20;//��ʾ��Χ 
ull gs=2;//���� 
double ylcl=0.0000000000667259;//�������� 
ull yzdx=60;//�����С
long double expand=0;
const ull yzs=5000;
double time_speed=0;
double sxpl=0.05;
ull lzs=0;
string cmdpassword="114514hhh";
bool cmdlogin=1;
bool time_=0;//ʱ�䷽��(��0��1)
bool zfwz[yzs+5];//��������(��0��1)
double bj[yzs+5];//����һ�����壬��뾶(��)
double x[yzs+5]={0};//��
double y[yzs+5]={0};//��
double z[yzs+5]={0};//��
double xsd[yzs+5]={0};//��/��
double ysd[yzs+5]={0};//��/��
double zsd[yzs+5];//��/��
double xjsd[yzs+5];//��/��^2
double yjsd[yzs+5];//��/��^2
double zjsd[yzs+5];//��/��^2
double zl[yzs+5];//ǧ��
double nl[yzs+5];
ull times=0;
long double expandadd=0;
//���ܺ���
//�����������ٶ�
double ag(double mass,double distance){
    const double constg = 6.67430e-11;
    return (constg*mass)/(distance*distance);
}
//���淢�����¼�
void save_happen(string a){
	fstream r1;
	r1.open("D:\\yz\\happen.data",ios::app);
	r1<<a<<'\n';
	r1.close();
	r1.clear(); 
	return;
}
//���뻻��
double clocks(){
	return clock()*1.0/CLOCKS_PER_SEC;
}
//cmd��¼(Ĭ�ϵ�¼)
void cmdlogin_(){
	system("cls");
	if(cmdlogin){
		printf("�ѵ�¼");
		Sleep(2000);
		return;
	}
	printf("���������Ա����:");
	string password;
	getline(cin,password);
	if(password==cmdpassword){
		printf("��½�ɹ�");
		Sleep(2000);
		cmdlogin=1;
	}else{
		printf("��¼ʧ��");
		Sleep(2000);
	}
	return;
}
//cmdδ��¼ 
void not_have_cmd(){
	printf("��Ϊ����ԱȨ�ޣ�����û�е�¼\n");
	Sleep(2000);
	return; 
}
void E_to_M(ull yzw1){//����ת��Ϊ���������ݰ���˹̹�Ĺ�ʽ������ԭ��λ
	zl[yzw1]=nl[yzw1]*1.0/pow(gs,2);
}

void M_to_E(ull yzw1){//����ת��Ϊ���������ݰ���˹̹�Ĺ�ʽ 
	nl[yzw1]=zl[yzw1]*pow(gs,2);
}
//over
void add(ull i){//���룬��������λ 
	double add;
	if(i<=lzs&&i!=0){
		printf("������x(0~%d%s",yzdx,"):");
		cin>>x[i];
		printf("������y(0~%d%s",yzdx,"):");
		cin>>y[i];
		printf("������z(0~%d%s",yzdx,"):");
		cin>>z[i];
		printf("������x�ٶ�(0~%d%s",gs,"):");
		cin>>xsd[i];
		printf("������y�ٶ�(0~%d%s",gs,"):");
		cin>>ysd[i];
		printf("������z�ٶ�(0~%d%s",gs,"):");
		cin>>zsd[i];
		printf("������x���ٶ�(0~%d%s",gs,"):");
		cin>>xjsd[i];
		printf("������y���ٶ�(0~%d%s",gs,"):");;
		cin>>yjsd[i];
		printf("������z���ٶ�(0~%d%s",gs,"):");
		cin>>zjsd[i];
		printf("����������(kg)");
		cin>>zl[i];
		M_to_E(i);
		printf("������������������(��0��1):");
		int x;
		cin>>x;
		if(x!=0&&x!=1){
			cout<<char(7);
			MessageBox(NULL,"���������������ݴ���","error message",MB_OK);
			exit(9);
		}
		zfwz[i]=x;
		printf("���������Ӱ뾶(��):");
		cin>>bj[i];
		return;
		}else
			printf("�����ڴ�����\n");
}

void savedata(){//�������ݣ�һ������׼���رճ���ʱʹ�� 
	system("cls");
	printf("׼������\n");
	fstream save;
	save.open("D:\\yz\\save.data",ios::out);
	save<<" ";
	save.close();
	save.clear();
	save.open("D:\\yz\\save.data");
	save<<lzs<<endl<<yzdx<<endl<<gs<<endl<<expand<<endl<<expandadd<<endl;
	for(int i=1;i<=lzs;i++){
		if(zl[i]==-1)
		continue;
		save<<x[i]<<" "<<y[i]<<" "<<z[i]<<" "<<xsd[i]<<" "<<ysd[i]<<" "<<zsd[i]<<" "<<xjsd[i]<<" "<<yjsd[i]<<" "<<zjsd[i]<<" "<<zl[i]<<" "<<zfwz[i]<<" "<<bj[i]<<endl;//x-y-z-x�ٶ�-y�ٶ�-z�ٶ�-x���ٶ�-y���ٶ�-z���ٶ�-����-��������-�뾶 
		cout<<"�����"<<i*1.0/lzs*100<<"%"<<endl;
	}
	save.close();
	save.clear();
	cout<<"���"<<endl;
	Sleep(2000);
	system("cls");
	return;
}

void cmd(void){//����Ա 
	system("cls");
	cout<<"��������ģʽ"<<endl;
	printf("done:�˳�����ģʽ\nclean:������\nxdd+����:����������x�����ƶ�\nydd+����:����������y�����ƶ�\nzdd+����:����������z�����ƶ�\nspeed:�ı�ˢ���ٶ�\ntime speed:�ı�����ٶ�\ntime:����ʱ�����ŷ���\ndata:�鿴��ʹ������������ʹ���������������С�������ٶȣ�����ʧ�Ĳ��㣩\nlook:�鿴��������\nrange add:�ƶ������е�����\nalter:�޸����Ӳ���\nlook all:��ʾ���д��ڵ��������ʵ�����\nall:��ʾ���д��ڵ���������\nmove eye:�ƶ��ӵ�λ�ã�δ��ɣ�\nexpand:�ı�������\ndisplay change:��ʾ��Χ����(δ���)\nexit:�����˳�\nexpand add:�ı������ٶȼ��ٶ�\nchange size:�ı������С\nadd:�������\ndel+����:ɾ�������ŵ�����\n");
	while(1){
		printf("operator<<");
		string n;
		getline(cin,n);
		if(n=="done"){
			system("cls");
			return;
		}else if(n[0]=='x'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				x[i]+=add;
			}
			cout<<"�������"<<endl;
		}else if(n[0]=='y'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				y[i]+=add;
			}
			cout<<"�������"<<endl;
		}else if(n[0]=='z'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				z[i]+=add;
			}
			cout<<"�������"<<endl;
		}else if(n=="speed"){
			printf("������ÿ֡ˢ���ٶ�(��):");
			cin>>sxpl;
			cout<<"�������"<<endl;
		}else if(n=="time"){
			printf("����������0������1��:");
			short a;
			cin>>a;
			if(a!=0&&a!=1)
			printf("error\n");
			else{
				time_=a;
				for(int i=1;i<=yzs;i++){
					xsd[i]=0-xsd[i];
					ysd[i]=0-ysd[i];
					zsd[i]=0-zsd[i];
					xjsd[i]=0-xjsd[i];
					yjsd[i]=0-yjsd[i];
					zjsd[i]=0-zjsd[i];
				}
				cout<<"�������"<<endl;
			}
		}else if(n=="data"){
			ull a=0;
			for(ull i=1;i<=yzs;i++){
				if(zl[i]!=-1)
				a++;
			}
			printf("��ʹ��������:%lld\nʹ��������:%lld\n�����С:%lld\n�����ٶ�:%lf\n����:%ld\n",yzs,a,yzdx,expand,gs);
		}else if(n=="look"){
			if(cmdlogin){
				printf("������鿴�����ӱ�ţ�");
				ull a;
				cin>>a;
				if(a<=lzs&&a!=0){
					printf("x:%lf\ny:%lf\nz:%lf\nx�ٶ�:%lf\ny�ٶ�:%lf\nz�ٶ�:%lf\nx���ٶ�:%lf\ny���ٶ�:%lf\nz���ٶ�:%lf\n����:%lf\n����:%lf\n�뾶:%lf\n������������:%s\n",x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"������":"������");
				}else
				printf("�����ڴ�����\n");
			}else{
				not_have_cmd();
			}
		}else if(n=="time speed"){
			printf("������ÿ�μ����ٶ�(��):");
			cin>>time_speed;
			time_speed*=1000;
			cout<<"�������"<<endl;
		}else if(n=="alter"){
			printf("�������޸�����:");
			ull i;
			cin>>i;
			add(i);
		}else if(n=="range add"){
			double x1,x2,y1,y2,z1,z2;
			printf("�밴x1,x2,y1,y2,z1,z2��˳������:");
			cin>>x1>>x2>>y1>>y2>>z1>>z2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			if(z1>z2)
				swap(z1,z2);
			double xadd,yadd,zadd;
			printf("������x�����ƶ�����:");
			cin>>xadd;
			printf("������y�����ƶ�����:");
			cin>>yadd;
			printf("������z�����ƶ�����:");
			cin>>zadd; 
			cout<<"����ִ��......"<<endl;
			for(ull i=1;i<=yzs;i++){
				if(zl[i]==-1)
				continue;
				if(x[i]>=x1&&x[i]<=x2&&y[i]>=y1&&y[i]<=y2&&z[i]>=z1&&z[i]<=z2)
				x[i]+=xadd;
				y[i]+=yadd;
				z[i]+=zadd;
			}
			cout<<"�������"<<endl;
		}else if(n=="look all"){
			ull zheng=0,fan=0,have=0;
			for(ull i=1;i<=yzs;i++){
				if(zfwz[i]==0&&zl[i]!=-1)
				zheng++;
				else if(zfwz[i]==1&&zl[i]!=-1)
				fan++;
				if(zl[i]!=-1)
				have++;
			}
			printf("������%lld����������%lld��������%lld��\n",zheng,fan,have);
			cout<<"�������"<<endl;
		}else if(n=="all"){
			for(ull a=1;a<=yzs;a++){
				if(zl[a]==-1)
				continue;
				printf("���:%lld\nx:%lf\ny:%lf\nz:%lf\nx�ٶ�:%lf\ny�ٶ�:%lf\nz�ٶ�:%lf\nx���ٶ�:%lf\ny���ٶ�:%lf\nz���ٶ�:%lf\n����:%lf\n����:%lf\n�뾶:%lf\n������������:%s\n\n",a,x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"������":"������");
			}
			cout<<"�������"<<endl; 
		}else if(n=="move eye"){
			printf("�������ӵ�x����λ��:");
			cin>>sdx;
			printf("�������ӵ�y����λ��:");
			cin>>sdy;
			cout<<"�������"<<endl;
		}else if(n=="expand"){
			printf("�����������ٶ�:");
			cin>>expand;
			cout<<"�������"<<endl;
		}else if(n=="display change"){
			printf("��������ʾ��Χ:");
			cin>>xsfw;
			cout<<"�������"<<endl;
		}else if(n=="exit"){
			savedata();
			exit(0);
		}else if(n=="expand add"){
			printf("�����������ٶȼ��ٶ�:");
			cin>>expandadd;
			cout<<"�������"<<endl;
		}else if(n=="change size"){
			printf("�����������С:");
			cin>>yzdx;
			cout<<"�������"<<endl;
		}
		else if(n=="add"){
			lzs++;
			add(lzs);
		}else if(n[0]=='d'&&n[1]=='e'&&n[2]=='l'){
			int yzw=string_to_longlong(n);
			zl[yzw]=-1;
			cout<<"�������"<<endl;
		}else if(n=="clean"){
			if(MessageBox(NULL,"��ȷ��Ҫɾ������������ɾ���󲻿ɻָ���","message",MB_YESNO|MB_ICONQUESTION)==IDYES){
				if(MessageBox(NULL,"��ȷ��Ҫɾ������������ɾ���󲻿ɻָ���","message",MB_YESNO|MB_ICONQUESTION)==IDYES){
					if(MessageBox(NULL,"��ȷ��Ҫɾ�������������������һ��ѯ�ʡ�ɾ���󲻿ɻָ���","message",MB_YESNO|MB_ICONQUESTION)==IDYES){
						system("rd /S /Q D:\\yz");
						cout<<"�������"<<endl;
					}
				}
			}
		}
		else if(n!=""){ 
			printf("\"%s\"���ǿ�ִ�е�����\n",&n[0]);
		} 
		printf("\n");
	}
	system("cls");
}

void savedatas(){
	printf("׼�����ݿ�\n");
	fstream r1;
	r1.open("D:\\yz\\data1.data",ios::out);
	r1<<"3\n10\n2\n0\n0\n5 5 0 1 0 0 0 0 0 50 0 1\n5 0 0 0 1 0 0 0 0 50 0 1\n0 5 0 0 1 0 0 0 0 50 0 1\n";
	r1.close();
	r1.clear();
	r1.open("D:\\yz\\data2.data",ios::out);
	r1<<"2\n20\n5\n0\n0\n5 10 0 2 1 0 0 0 0 50 0 1\n15 10 0 1 2 0 0 0 0 50 0 1";
	r1.close();
	r1.clear();
	printf("����׼�����\n");
	Sleep(1000);
	return;
}
bool scandata(){//��ȡ���ݣ�һ�����ڳ���ʼ 
	system("cls");
	fstream scan;
	scan.open("D:\\yz\\save.data");
	if(scan.is_open()){
		scan>>lzs>>yzdx>>gs>>expand>>expandadd;
		for(ull i=1;!scan.eof()&&i<=lzs;i++){
			scan>>x[i]>>y[i]>>z[i]>>xsd[i]>>ysd[i]>>zsd[i]>>xjsd[i]>>yjsd[i]>>zjsd[i]>>zl[i]>>zfwz[i]>>bj[i];
			lzs++;
			M_to_E(i);
			cout<<"�����"<<i*1.0/lzs*100<<"%"<<endl;
		}
		scan.close();
		scan.clear();
		system("cls");
		return 1;
	}else{
		cout<<char(7);
		printf("û���ҵ�����\n");
		Sleep(2000);
		system("cls");
		return 0;
	}
}

bool zdsj(){
	cout<<char(7);
	int a=MessageBox(NULL,TEXT("�Ƿ��Զ������ݣ�"),"",MB_YESNO);//�Զ������� 
	if(a==IDYES){
		system("cls");
		printf("�������룬��Ȼ���鷳Ŷ\n");
		printf("�����������С:");
		cin>>yzdx;
		printf("������ԭ����(1~");
		printf("%d%s",yzs,"):");
		cin>>lzs;
		if(lzs>yzs){
			cout<<char(7);
			MessageBox(NULL,TEXT("Excessive particle count(0x1)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(1); 
		}else if(lzs<1){
			cout<<char(7);
			MessageBox(NULL,TEXT("The particle number is too small(0x2)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(2);
		}
		printf("���������:");
		cin>>gs;
		if(gs<=1){
			cout<<char(7);
			MessageBox(NULL,TEXT("The speed of light is too small(0x3)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(3);
		}
		if(yzdx<=0){
			cout<<char(7);
			MessageBox(NULL,TEXT("The universe is too small(0x5)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(5);
		}
		for(int i=1;i<=lzs;i++){
			add(i);
			printf("�����%lf%\n",i*1.0/lzs*100);
		}
		cout<<"over"<<endl;
		system("cls");
		return 1;
	}
	return 0;
}

void qidong(){
	system("cls");
	printf("������������(0~%lld):",yzs);
	cin>>lzs;
	if(lzs>yzs){
		cout<<char(7);
		MessageBox(NULL,TEXT("Excessive particle count(0x1)"),TEXT("error message"),MB_OK);
		exit(1);
	}
	printf("���������:");
	cin>>gs;
	if(gs<=1){
		cout<<char(7);
		MessageBox(NULL,TEXT("The speed of light is too small(0x3)"),TEXT("error message"),MB_OK);
		exit(3);
	}
	printf("�����������С:");
	cin>>yzdx;
	if(yzdx<=0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The universe is too small(0x5)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
		exit(5);
	}
	srand(time(0));
	for(int i=1;i<=lzs;i++){
			x[i]=rand()%yzdx;
			y[i]=rand()%yzdx;
			z[i]=rand()%yzdx;
			bool zf=rand()%2;
		if(zf==0)
			xsd[i]=rand()%(gs-1)+1;
		else
			xsd[i]=0-(rand()%(gs-1)+1);
		zf=rand()%2;
		if(zf==0)
			ysd[i]=rand()%(gs-1)+1;
		else
			ysd[i]=0-(rand()%(gs-1)+1);
		zf=rand()%2;
		if(zf==0)
			zsd[i]=rand()%(gs-1)+1;
		else
			zsd[i]=0-(rand()%(gs-1)+1);
		zf=rand()%2;
		if(zf==0)
			xjsd[i]=rand()%(gs-1)+1;
		else
			xjsd[i]=0-(rand()%(gs-1)+1);
		zf=rand()%2;
		if(zf==0)
			yjsd[i]=rand()%(gs-1)+1;
		else
			yjsd[i]=0-(rand()%(gs-1)+1);
		zf=rand()%2;
		if(zf==0)
			zjsd[i]=rand()%(gs-1)+1;
		else
			zjsd[i]=0-(rand()%(gs-1)+1);
			zfwz[i]=rand()%2;
		do{
			zl[i]=rand()%10000;
		}while(zl[i]<0);
		M_to_E(i);
		while(bj[i]<=0)
			bj[i]=rand()%10;
		cout<<"�����"<<i*1.0/lzs*100<<"%"<<endl;
	}
	cout<<"over"<<endl;
	Sleep(1000);
	system("cls");
	return;
}

bool scandatas(){
	cout<<char(7);
	int a=MessageBox(NULL,TEXT("�Ƿ�ʹ�����ݿ�?"),"",MB_YESNO);
	if(a==IDYES){
		string a;
		system("cls");
		printf("���������ݿ��ţ�");
		getline(cin,a);
		fstream r1;
		r1.open(&("D:\\yz\\data"+a+".data")[0]);
		if(!r1.is_open()){
			printf("���ݿ���Ϣ������\n");
			system("pause");
			return 0; 
		}
		r1>>lzs>>yzdx>>gs>>expand>>expandadd;
		for(ull i=1;i<=lzs||!r1.eof();i++){
			r1>>x[i]>>y[i]>>z[i]>>xsd[i]>>ysd[i]>>zsd[i]>>xjsd[i]>>yjsd[i]>>zjsd[i]>>zl[i]>>zfwz[i]>>bj[i];
			M_to_E(i);
			cout<<"�����"<<i*1.0/yzs*100<<"%"<<endl;
		}
		system("cls");
		return 1;
	}else
	return 0;
}

void chushihua(){//��ʼ����� 
if(scandatas());
else
	if(zdsj());
	else qidong();
	return; 
}

void weizhigengxin(){//λ�ø������ֹ���������޷����� 
	for(int i=1;i<=lzs;i++){
		/*xsd[i]+=xjsd[i];
		ysd[i]+=yjsd[i];
		zsd[i]+=zjsd[i];
		*/
		x[i]+=xsd[i];
		y[i]+=ysd[i];
		z[i]+=zsd[i];
		if(x[i]>yzdx)
			x[i]=0;
		else if(x[i]<0)
			x[i]=yzdx;
		if(y[i]>yzdx)
			y[i]=0;
		else if(y[i]<0)
			y[i]=yzdx;
		if(z[i]>yzdx)
			z[i]=0;
		else if(z[i]<0)
			z[i]=yzdx;
		/*if(xsd[i]>=gs)
			xsd[i]=gs-0.0001;
		if(ysd[i]>=gs)
			ysd[i]=gs-0.0001;
		if(zsd[i]>=gs)
			zsd[i]=gs-0.0001;
		if(xsd[i]<=0-gs)
			xsd[i]=0-gs+0.0001;
		if(ysd[i]<=0-gs)
			ysd[i]=0-gs+0.0001;
		if(zsd[i]<=0-gs)
			zsd[i]=0-gs+0.0001;
		*/
}
}
double z_x(double x,double z){
	return x;//return x*D3*1.0/z;
}
double z_y(double y,double z){
	return y;//return y*D3*1.0/z; 
}
void output(){
	for(ull i=sdx;i<=yzdx;i++){
		for(ull j=sdy;j<=yzdx;j++){
			bool a=0;
			for(int w=1;w<=yzs;w++){	
				if(zl[w]==-1)
				continue;
				if(abs(z_x(x[w],z[w])-i)<0.5&&abs(z_y(y[w],z[w])-j)<0.5){
					printf("*");
					a=1;
					break;
				}
			}
			if(a==0)
				printf(" ");
		}
		cout<<endl;
	}
}
void jiasudugengxin(){
	for(ull i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		for(ull j=1;j<=lzs;j++){
			if(i==j)
				continue;
			xjsd[i]+=ag(zl[j],abs(x[i]-x[j]))/zl[i];
			yjsd[i]+=ag(zl[j],abs(y[i]-y[j]))/zl[i];
			zjsd[i]+=ag(zl[j],abs(z[i]-z[j]))/zl[i];
		}
	}
}
void zhengfanyanmie(){
	for(ull i=1;i<=yzs;i++){
		if(zl[i]==-1)
		continue;
		for(ull j=1;j<=yzs;j++){
			if(i==j||zl[j]==-1)
				continue;
			if(zfwz[i]==zfwz[j])
			continue;
			double jl=sqrt(pow(abs(x[i]-x[j]),2)+pow(abs(y[i]-y[j]),2)+pow(abs(z[i]-z[j]),2));
			if(jl<=bj[i]+bj[j]){
				zl[i]=-1;
				zl[j]=-1;
				fstream happen;
				happen.open("D:\\yz\\happen.data",ios::app);
				happen<<"���������������� "<<i<<"��&"<<j<<"�����ӣ��ڵ�"<<times<<"�θ���ʱ����\n"; 
				/*
				don't over
				*/
				break;
			}
		}
	}
}
signed main(){
	system("title ģ������");
	system("md \"D:\\yz\"");
	system("del D:\\yz\\happen.data");
	system("cls");
	system("attrib +s +a +h +r D:\\yz");//https://jingyan.baidu.com/article/ab0b563098d7bd805bfa7d68.html
	printf("loading......\n");
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	{fstream r1;
	r1.open("D:\\yz\\���ڴ��ļ��е�˵��.txt",ios::out);
	r1<<"����һ������Ĵ洢���ݣ����κ�Σ���ԣ��벻Ҫɾ����";
	r1.close();
	r1.clear();}
	if(system(NULL)==0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The operating system cannot call the cmd program\n(0x11)"),TEXT("error message"),MB_OK);
		exit(8);
	}
	size_t i=get_memory_usage();
	if(i<100){
		printf("�ڴ治�㣬ʣ��%dMB���뱣������100MB���ڴ汣�����С�\n",i);
		system("pause");
		exit(10);
	}else if(i==-1)
		printf("�ڴ��޷��鿴�����ܻᵼ�´���"); 
	cout<<endl;
	printf("��Ҫ����!��Ҫ����!!��Ҫ����!!!������������!");
	cout<<endl;
	for(ull i=1;i<=yzs;i++){
		zl[i]=-1;
	}
	savedatas();

	{	fstream a;
		a.open("D:\\yz\\happen.data",ios::out);
		a.close();
		a.clear();
		a.open("D:\\yz\\save.data");
		if(a.is_open()){
			cout<<char(7);
			if(MessageBox(NULL,TEXT("���ֱ������ݣ��Ƿ�ʹ��?"),TEXT(""),MB_YESNO|MB_ICONQUESTION)==IDYES)
				scandata();
			else
				chushihua();
		}else
		chushihua();
		a.close();
		a.clear();
	}
	double begin=clocks();
	double over=clocks();
	double begin2=clock();
	double over2=clock();
	while(1){//����
		if(KEY_DOWN('Q'))
			cmd();
		if(KEY_DOWN('S'))
			savedata();
		if(KEY_DOWN('C'))
			cmdlogin_();
		if((over2-begin2)>=time_speed){
			expand+=expandadd;
			yzdx+=expand;
			jiasudugengxin();
			zhengfanyanmie();
			weizhigengxin();
			if(time_)
			times--;
			else
			times++;
			begin2=clock();
		}
		over=clocks();
		if((over-begin)>=sxpl){
			system("cls");
			output();
			printf("fps:");
			over=clocks();
			if(over-begin==0)
			printf(">1000");
			else
			cout<<setprecision(5)<<1.0/(over-begin)<<endl;
			begin=clocks();
			over=begin;
			printf("ʱ��:%lld",times);
		}
		over2=clock();
	}
}
