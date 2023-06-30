#pragma GCC optimize(3)//配套插件：note.ms/yzerrno note.ms/yzsome(头文件) note.ms/yzhappen(记录发生事件)
#include<bits/stdc++.h>//更新了更新了更新了qwq
#include<unistd.h>//https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&srcqid=7583488485642553692&tn=50000021_hao_pg&wd=c%2B%2B%E5%A6%82%E4%BD%95%E5%81%9A%E5%AE%89%E8%A3%85%E5%8C%85&oq=c%252B%252B%25E5%25A6%2582%25E4%25BD%2595%25E5%2581%259A%25E5%25AE%2589%25E8%25A3%2585%25E5%258C%2585&rsv_pq=832f1453000156ce&rsv_t=ba5f%2BGkSbJqh%2BWbLEwO%2F%2BzFdYMa%2FPSFmPKe1tlQtI1BtcCvJo%2FxWvDa%2Fm%2FvcevEdyUXcNk2b&rqlang=cn&rsv_enter=0&rsv_dl=tb&rsv_btype=t
#include<windows.h>
#include<bitset>
#include"some.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define ull unsigned long long
#define D3 300
using namespace std;
double sdx=0,sdy=0,sdz=0;//视点x，视点y，视点z
ull xsfw=20;//显示范围 
ull gs=2;//光速 
double ylcl=0.0000000000667259;//引力常数 
ull yzdx=60;//宇宙大小
long double expand=0;
const ull yzs=5000;
double time_speed=0;
double sxpl=0.05;
ull lzs=0;
string cmdpassword="114514hhh";
bool cmdlogin=1;
bool time_=0;//时间方向(正0负1)
bool zfwz[yzs+5];//正反物质(正0反1)
double bj[yzs+5];//看做一个球体，存半径(米)
double x[yzs+5]={0};//米
double y[yzs+5]={0};//米
double z[yzs+5]={0};//米
double xsd[yzs+5]={0};//米/秒
double ysd[yzs+5]={0};//米/秒
double zsd[yzs+5];//米/秒
double xjsd[yzs+5];//米/秒^2
double yjsd[yzs+5];//米/秒^2
double zjsd[yzs+5];//米/秒^2
double zl[yzs+5];//千克
double nl[yzs+5];
ull times=0;
long double expandadd=0;
//功能函数
//计算引力加速度
double ag(double mass,double distance){
    const double constg = 6.67430e-11;
    return (constg*mass)/(distance*distance);
}
//保存发生的事件
void save_happen(string a){
	fstream r1;
	r1.open("D:\\yz\\happen.data",ios::app);
	r1<<a<<'\n';
	r1.close();
	r1.clear(); 
	return;
}
//毫秒换秒
double clocks(){
	return clock()*1.0/CLOCKS_PER_SEC;
}
//cmd登录(默认登录)
void cmdlogin_(){
	system("cls");
	if(cmdlogin){
		printf("已登录");
		Sleep(2000);
		return;
	}
	printf("请输入管理员密码:");
	string password;
	getline(cin,password);
	if(password==cmdpassword){
		printf("登陆成功");
		Sleep(2000);
		cmdlogin=1;
	}else{
		printf("登录失败");
		Sleep(2000);
	}
	return;
}
//cmd未登录 
void not_have_cmd(){
	printf("此为管理员权限，您还没有登录\n");
	Sleep(2000);
	return; 
}
void E_to_M(ull yzw1){//能量转换为质量，根据爱因斯坦的公式，传参原子位
	zl[yzw1]=nl[yzw1]*1.0/pow(gs,2);
}

void M_to_E(ull yzw1){//质量转换为能量，根据爱因斯坦的公式 
	nl[yzw1]=zl[yzw1]*pow(gs,2);
}
//over
void add(ull i){//输入，传参粒子位 
	double add;
	if(i<=lzs&&i!=0){
		printf("请输入x(0~%d%s",yzdx,"):");
		cin>>x[i];
		printf("请输入y(0~%d%s",yzdx,"):");
		cin>>y[i];
		printf("请输入z(0~%d%s",yzdx,"):");
		cin>>z[i];
		printf("请输入x速度(0~%d%s",gs,"):");
		cin>>xsd[i];
		printf("请输入y速度(0~%d%s",gs,"):");
		cin>>ysd[i];
		printf("请输入z速度(0~%d%s",gs,"):");
		cin>>zsd[i];
		printf("请输入x加速度(0~%d%s",gs,"):");
		cin>>xjsd[i];
		printf("请输入y加速度(0~%d%s",gs,"):");;
		cin>>yjsd[i];
		printf("请输入z加速度(0~%d%s",gs,"):");
		cin>>zjsd[i];
		printf("请输入质量(kg)");
		cin>>zl[i];
		M_to_E(i);
		printf("请输入正反物质类型(正0反1):");
		int x;
		cin>>x;
		if(x!=0&&x!=1){
			cout<<char(7);
			MessageBox(NULL,"正反物质类型数据错误","error message",MB_OK);
			exit(9);
		}
		zfwz[i]=x;
		printf("请输入粒子半径(米):");
		cin>>bj[i];
		return;
		}else
			printf("不存在此粒子\n");
}

void savedata(){//保存数据，一般用于准备关闭程序时使用 
	system("cls");
	printf("准备保存\n");
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
		save<<x[i]<<" "<<y[i]<<" "<<z[i]<<" "<<xsd[i]<<" "<<ysd[i]<<" "<<zsd[i]<<" "<<xjsd[i]<<" "<<yjsd[i]<<" "<<zjsd[i]<<" "<<zl[i]<<" "<<zfwz[i]<<" "<<bj[i]<<endl;//x-y-z-x速度-y速度-z速度-x加速度-y加速度-z加速度-质量-正反物质-半径 
		cout<<"已完成"<<i*1.0/lzs*100<<"%"<<endl;
	}
	save.close();
	save.clear();
	cout<<"完成"<<endl;
	Sleep(2000);
	system("cls");
	return;
}

void cmd(void){//管理员 
	system("cls");
	cout<<"进入命令模式"<<endl;
	printf("done:退出命令模式\nclean:清理缓存\nxdd+数字:所有粒子在x方向移动\nydd+数字:所有粒子在y方向移动\nzdd+数字:所有粒子在z方向移动\nspeed:改变刷新速度\ntime speed:改变计算速度\ntime:调整时间流逝方向\ndata:查看可使用粒子数和已使用粒子数和宇宙大小和膨胀速度（已消失的不算）\nlook:查看粒子数据\nrange add:移动区域中的粒子\nalter:修改粒子参数\nlook all:显示所有存在的正反物质的数量\nall:显示所有存在的粒子数据\nmove eye:移动视点位置（未完成）\nexpand:改变膨胀率\ndisplay change:显示范围更改(未完成)\nexit:正常退出\nexpand add:改变膨胀速度加速度\nchange size:改变宇宙大小\nadd:添加粒子\ndel+数字:删除输入编号的粒子\n");
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
			cout<<"命令完成"<<endl;
		}else if(n[0]=='y'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				y[i]+=add;
			}
			cout<<"命令完成"<<endl;
		}else if(n[0]=='z'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				z[i]+=add;
			}
			cout<<"命令完成"<<endl;
		}else if(n=="speed"){
			printf("请输入每帧刷新速度(秒):");
			cin>>sxpl;
			cout<<"命令完成"<<endl;
		}else if(n=="time"){
			printf("请输入正（0）负（1）:");
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
				cout<<"命令完成"<<endl;
			}
		}else if(n=="data"){
			ull a=0;
			for(ull i=1;i<=yzs;i++){
				if(zl[i]!=-1)
				a++;
			}
			printf("可使用粒子数:%lld\n使用粒子数:%lld\n宇宙大小:%lld\n膨胀速度:%lf\n光速:%ld\n",yzs,a,yzdx,expand,gs);
		}else if(n=="look"){
			if(cmdlogin){
				printf("请输入查看的粒子编号：");
				ull a;
				cin>>a;
				if(a<=lzs&&a!=0){
					printf("x:%lf\ny:%lf\nz:%lf\nx速度:%lf\ny速度:%lf\nz速度:%lf\nx加速度:%lf\ny加速度:%lf\nz加速度:%lf\n质量:%lf\n能量:%lf\n半径:%lf\n正反物质类型:%s\n",x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"反物质":"正物质");
				}else
				printf("不存在此粒子\n");
			}else{
				not_have_cmd();
			}
		}else if(n=="time speed"){
			printf("请输入每次计算速度(秒):");
			cin>>time_speed;
			time_speed*=1000;
			cout<<"命令完成"<<endl;
		}else if(n=="alter"){
			printf("请输入修改粒子:");
			ull i;
			cin>>i;
			add(i);
		}else if(n=="range add"){
			double x1,x2,y1,y2,z1,z2;
			printf("请按x1,x2,y1,y2,z1,z2的顺序输入:");
			cin>>x1>>x2>>y1>>y2>>z1>>z2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			if(z1>z2)
				swap(z1,z2);
			double xadd,yadd,zadd;
			printf("请输入x方向移动距离:");
			cin>>xadd;
			printf("请输入y方向移动距离:");
			cin>>yadd;
			printf("请输入z方向移动距离:");
			cin>>zadd; 
			cout<<"正在执行......"<<endl;
			for(ull i=1;i<=yzs;i++){
				if(zl[i]==-1)
				continue;
				if(x[i]>=x1&&x[i]<=x2&&y[i]>=y1&&y[i]<=y2&&z[i]>=z1&&z[i]<=z2)
				x[i]+=xadd;
				y[i]+=yadd;
				z[i]+=zadd;
			}
			cout<<"命令完成"<<endl;
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
			printf("正物质%lld个，反物质%lld个，存在%lld个\n",zheng,fan,have);
			cout<<"命令完成"<<endl;
		}else if(n=="all"){
			for(ull a=1;a<=yzs;a++){
				if(zl[a]==-1)
				continue;
				printf("编号:%lld\nx:%lf\ny:%lf\nz:%lf\nx速度:%lf\ny速度:%lf\nz速度:%lf\nx加速度:%lf\ny加速度:%lf\nz加速度:%lf\n质量:%lf\n能量:%lf\n半径:%lf\n正反物质类型:%s\n\n",a,x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"反物质":"正物质");
			}
			cout<<"命令完成"<<endl; 
		}else if(n=="move eye"){
			printf("请输入视点x所在位置:");
			cin>>sdx;
			printf("请输入视点y所在位置:");
			cin>>sdy;
			cout<<"命令完成"<<endl;
		}else if(n=="expand"){
			printf("请输入膨胀速度:");
			cin>>expand;
			cout<<"命令完成"<<endl;
		}else if(n=="display change"){
			printf("请输入显示范围:");
			cin>>xsfw;
			cout<<"命令完成"<<endl;
		}else if(n=="exit"){
			savedata();
			exit(0);
		}else if(n=="expand add"){
			printf("请输入膨胀速度加速度:");
			cin>>expandadd;
			cout<<"命令完成"<<endl;
		}else if(n=="change size"){
			printf("请输入宇宙大小:");
			cin>>yzdx;
			cout<<"命令完成"<<endl;
		}
		else if(n=="add"){
			lzs++;
			add(lzs);
		}else if(n[0]=='d'&&n[1]=='e'&&n[2]=='l'){
			int yzw=string_to_longlong(n);
			zl[yzw]=-1;
			cout<<"命令完成"<<endl;
		}else if(n=="clean"){
			if(MessageBox(NULL,"您确定要删除缓存数据吗？删除后不可恢复。","message",MB_YESNO|MB_ICONQUESTION)==IDYES){
				if(MessageBox(NULL,"您确定要删除缓存数据吗？删除后不可恢复。","message",MB_YESNO|MB_ICONQUESTION)==IDYES){
					if(MessageBox(NULL,"您确定要删除缓存数据吗？这是最后一次询问。删除后不可恢复。","message",MB_YESNO|MB_ICONQUESTION)==IDYES){
						system("rd /S /Q D:\\yz");
						cout<<"命令完成"<<endl;
					}
				}
			}
		}
		else if(n!=""){ 
			printf("\"%s\"不是可执行的命令\n",&n[0]);
		} 
		printf("\n");
	}
	system("cls");
}

void savedatas(){
	printf("准备数据库\n");
	fstream r1;
	r1.open("D:\\yz\\data1.data",ios::out);
	r1<<"3\n10\n2\n0\n0\n5 5 0 1 0 0 0 0 0 50 0 1\n5 0 0 0 1 0 0 0 0 50 0 1\n0 5 0 0 1 0 0 0 0 50 0 1\n";
	r1.close();
	r1.clear();
	r1.open("D:\\yz\\data2.data",ios::out);
	r1<<"2\n20\n5\n0\n0\n5 10 0 2 1 0 0 0 0 50 0 1\n15 10 0 1 2 0 0 0 0 50 0 1";
	r1.close();
	r1.clear();
	printf("数据准备完毕\n");
	Sleep(1000);
	return;
}
bool scandata(){//读取数据，一般用于程序开始 
	system("cls");
	fstream scan;
	scan.open("D:\\yz\\save.data");
	if(scan.is_open()){
		scan>>lzs>>yzdx>>gs>>expand>>expandadd;
		for(ull i=1;!scan.eof()&&i<=lzs;i++){
			scan>>x[i]>>y[i]>>z[i]>>xsd[i]>>ysd[i]>>zsd[i]>>xjsd[i]>>yjsd[i]>>zjsd[i]>>zl[i]>>zfwz[i]>>bj[i];
			lzs++;
			M_to_E(i);
			cout<<"已完成"<<i*1.0/lzs*100<<"%"<<endl;
		}
		scan.close();
		scan.clear();
		system("cls");
		return 1;
	}else{
		cout<<char(7);
		printf("没有找到数据\n");
		Sleep(2000);
		system("cls");
		return 0;
	}
}

bool zdsj(){
	cout<<char(7);
	int a=MessageBox(NULL,TEXT("是否自定义数据？"),"",MB_YESNO);//自定义数据 
	if(a==IDYES){
		system("cls");
		printf("认真输入，不然很麻烦哦\n");
		printf("请输入宇宙大小:");
		cin>>yzdx;
		printf("请输入原子数(1~");
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
		printf("请输入光速:");
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
			printf("已完成%lf%\n",i*1.0/lzs*100);
		}
		cout<<"over"<<endl;
		system("cls");
		return 1;
	}
	return 0;
}

void qidong(){
	system("cls");
	printf("请输入粒子数(0~%lld):",yzs);
	cin>>lzs;
	if(lzs>yzs){
		cout<<char(7);
		MessageBox(NULL,TEXT("Excessive particle count(0x1)"),TEXT("error message"),MB_OK);
		exit(1);
	}
	printf("请输入光速:");
	cin>>gs;
	if(gs<=1){
		cout<<char(7);
		MessageBox(NULL,TEXT("The speed of light is too small(0x3)"),TEXT("error message"),MB_OK);
		exit(3);
	}
	printf("请输入宇宙大小:");
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
		cout<<"已完成"<<i*1.0/lzs*100<<"%"<<endl;
	}
	cout<<"over"<<endl;
	Sleep(1000);
	system("cls");
	return;
}

bool scandatas(){
	cout<<char(7);
	int a=MessageBox(NULL,TEXT("是否使用数据库?"),"",MB_YESNO);
	if(a==IDYES){
		string a;
		system("cls");
		printf("请输入数据库编号：");
		getline(cin,a);
		fstream r1;
		r1.open(&("D:\\yz\\data"+a+".data")[0]);
		if(!r1.is_open()){
			printf("数据库信息不存在\n");
			system("pause");
			return 0; 
		}
		r1>>lzs>>yzdx>>gs>>expand>>expandadd;
		for(ull i=1;i<=lzs||!r1.eof();i++){
			r1>>x[i]>>y[i]>>z[i]>>xsd[i]>>ysd[i]>>zsd[i]>>xjsd[i]>>yjsd[i]>>zjsd[i]>>zl[i]>>zfwz[i]>>bj[i];
			M_to_E(i);
			cout<<"已完成"<<i*1.0/yzs*100<<"%"<<endl;
		}
		system("cls");
		return 1;
	}else
	return 0;
}

void chushihua(){//初始化随机 
if(scandatas());
else
	if(zdsj());
	else qidong();
	return; 
}

void weizhigengxin(){//位置更新与禁止超光速与无缝世界 
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
				happen<<"发生正反物质湮灭 "<<i<<"号&"<<j<<"号粒子，在第"<<times<<"次更新时湮灭\n"; 
				/*
				don't over
				*/
				break;
			}
		}
	}
}
signed main(){
	system("title 模拟宇宙");
	system("md \"D:\\yz\"");
	system("del D:\\yz\\happen.data");
	system("cls");
	system("attrib +s +a +h +r D:\\yz");//https://jingyan.baidu.com/article/ab0b563098d7bd805bfa7d68.html
	printf("loading......\n");
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	{fstream r1;
	r1.open("D:\\yz\\关于此文件夹的说明.txt",ios::out);
	r1<<"这是一个软件的存储数据，无任何危害性，请不要删除。";
	r1.close();
	r1.clear();}
	if(system(NULL)==0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The operating system cannot call the cmd program\n(0x11)"),TEXT("error message"),MB_OK);
		exit(8);
	}
	size_t i=get_memory_usage();
	if(i<100){
		printf("内存不足，剩余%dMB，须保持至少100MB的内存保持运行。\n",i);
		system("pause");
		exit(10);
	}else if(i==-1)
		printf("内存无法查看，可能会导致错误"); 
	cout<<endl;
	printf("不要乱输!不要乱输!!不要乱输!!!乱输后果很严重!");
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
			if(MessageBox(NULL,TEXT("发现保存数据，是否使用?"),TEXT(""),MB_YESNO|MB_ICONQUESTION)==IDYES)
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
	while(1){//计算
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
			printf("时间:%lld",times);
		}
		over2=clock();
	}
}
