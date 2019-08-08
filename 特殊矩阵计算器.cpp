#include<iostream>
#include<cmath>
#define max 100
using namespace std;
typedef struct{
	int a[max][max];
	int row,col;    //定义矩阵行数、列数 
}SMatrix;        //存储结构
typedef struct{
	int array[max];
	int n;      //定义矩阵的阶 
}M;
SMatrix A,B,C,D;
    M p; 
    
//矩阵的压缩存储
int CompressSMatrix(int m,int i,int j,int n){
	int k;
	if(m==1){
		if(i<=j)
			k=(2*n-i+1)*i/2+(j-i)+1;
		else
			k=0;
		return k;
	}
	if(m==2){
		if(i>=j)
			k=i*(i+1)/2+j+1;
		else
			k=0;
		return k;

	}
	if(m==3)
	{
	    if(i>=j)
			k=i*(i+1)/2+j;
		else
			k=j*(j+1)/2+i;
		return k;
	}
	if(m==4) {
		if(i!=j)
			k=0;
		else
			k=i+1;
		return k;
	}
	if(m==5){
		if(i==j)
		return 1;
		else
		return 0;
	}
}

//创建上三角矩阵 
void CreateSMatrixUppertri(M &a,SMatrix &A)
{
	int i,j,t,n;
	cout<<"请输入上三角矩阵的行数和列数(行数与列数相同)：";
	cin>>A.row>>A.col;    //输入行、列 
	n=A.row; 
	a.n=n; 
	printf("请输入%d个数：",n*(n+1)/2);
	a.array[0]=0;
	for(i=1;i<=n*(n+1)/2;i++)
	cin>>a.array[i];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	t=CompressSMatrix(1,i,j,n);
	A.a[i][j]=a.array[t];
    }
}

//创建下三角矩阵 
void CreateSMatrixLowertri(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"请输入下三角矩阵的行数和列数(行数与列数相同)：";
	cin>>A.row>>A.col;
	n=A.row; 
	a.n=n; 
	printf("请输入%d个数：",n*(n+1)/2);
	a.array[0]=0;
	for(i=1;i<=n*(n+1)/2;i++)
	cin>>a.array[i];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	t=CompressSMatrix(2,i,j,n);
	A.a[i][j]=a.array[t];
    }
}
	
//创建对称矩阵 
void CreateSMatrixSymmetry(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"请输入对称矩阵的行数和列数(行数与列数相同)：";
	cin>>A.row>>A.col;
	n=A.row; 
	a.n=n; 
	printf("请输入%d个数：",n*(n+1)/2);
	for(i=0;i<n*(n+1)/2;i++)
	cin>>a.array[i];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	t=CompressSMatrix(3,i,j,n);
	A.a[i][j]=a.array[t];
    }
}
	
//创建对角矩阵 
void CreateSMatrixDiagonal(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"请输入对角矩阵的行数和列数(行数与列数相同)：";
	cin>>A.row>>A.col;
	n=A.row; 
	a.n=n; 
	printf("请输入%d个数：",n);
	a.array[0]=0;
	for(i=1;i<=n;i++)
	cin>>a.array[i];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	t=CompressSMatrix(4,i,j,n);
	A.a[i][j]=a.array[t];
    }
}
	
//创建单位矩阵 
void CreateSMatrixUnit(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"请输入单位矩阵的行数和列数(行数与列数相同)：";
	cin>>A.row>>A.col; 
	n=A.row; 
	a.n=n; 
	a.array[0]=0;
	a.array[1]=1; 
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	t=CompressSMatrix(5,i,j,n);
	A.a[i][j]=a.array[t];
    }
}


//加法 
int Add(SMatrix A,SMatrix B,SMatrix &C)
{
    int i,j;
	if(A.row!=B.row)
	return 0;
	else
	{
		C.row=A.row;
		C.col=A.col; 
		for(i=0;i<A.row;i++)
		for(j=0;j<A.col;j++)
		C.a[i][j]=A.a[i][j]+B.a[i][j];
	}
	return 1;
}

//减法 
int Sub(SMatrix A,SMatrix B,SMatrix &C)
{
    int i,j;
	if(A.row!=B.row)
	return 0;
	else
	{
		C.row=A.row;
		C.col=A.col;
		for(i=0;i<A.row;i++)
		for(j=0;j<A.col;j++)
		C.a[i][j]=A.a[i][j]-B.a[i][j];
	}
	return 1;
}

//乘法
int Mul(SMatrix A,SMatrix B,SMatrix &C)
{
	int i,j,k;
	if(A.row!=B.row)
	return 0;
	else
	{
		C.row=A.row; 
		C.col=A.col;
		for(i=0;i<A.row;i++) 
		for(j=0;j<A.col;j++)
		C.a[i][j]=0; 
		for(i=0;i<A.row;i++)   //A的行数 
		for(j=0;j<A.col;j++)   //A的列数和B的行数 
		for(k=0;k<A.col;k++)   //B的列数 
		C.a[i][j]+=A.a[i][k]*B.a[k][j];
	}
	return 1;
 } 
 
 
 //逆运算
void Inverse(SMatrix A){
	SMatrix C;
	float p,q;
	int k,i,j,n;
	n=A.row;
	for(i=0;i<n ;i++)
	for(j=0;j<(n *2);j++){
	   	if(j<n)
	   	  	C.a [i][j]=A.a [i][j];
	   	else if(j==n+i)
	   	    C.a [i][j]=1.0;
		else
		    C.a [i][j]=0.0;		
	   }
	for(k=0;k<n ;k++){
	for(i=0;i<n ;i++){
	   	if(i!=k){
	   		p=C.a [i][k]/C.a [i][i];
	   		for(j=0;j<(n *2);j++){
	   			q=C.a [i][j]*p;
	   			C.a [i][j]=C.a [i][j]-q;
	   		}
	   	}
	   } 
	} 
	for(i=0;i<n ;i++)
	{
	    p=C.a[i][i];
		for(j=0;j<n*2;j++)
		C.a[i][j]=C.a[i][j]/p;
		float y=1.0;
		for(i=0;i<n;i++)
		y=y*C.a[i][i];
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		A.a[i][j]=C.a[i][j+n];
		cout<<"逆运算结果："<<endl;
		for(i=0;i<n;i++)
		{
		   for(j=0;j<n;j++)
		   cout<<A.a[i][j]<<"  ";
		   cout<<endl;
	    }
	}
}


 //转置 
 void Tans(SMatrix A,SMatrix &C)
 {
 	int i,j;
 		C.row=A.row;
		C.col=A.col;
 	for(i=0;i<A.row;i++) 
	for(j=0;j<A.col;j++)
	C.a[j][i]=A.a[i][j];
 }
 
 //矩阵行列式的值 
 void Determinant(SMatrix A) {   
	int count[100];      
	int sum=0;
	int n;
	n=A.row;   //n为矩阵的阶 
	for (int p = 0; p < n; p++) {
		int k = 0; int j = p%n;
		count[p]= A.a[k][p];
		for (int i = 1; i < n; i++) {
			k++; j++;
			k = k%n;
			j = j%n;
			count[p] *= A.a[k][j];
		}
	}
	for (int p = n-1; p >=0; p--) {
		int k = 0; int j = p%n;
		count[2*n-1-p] = A.a[k][p];
		for (int i = 1; i < n; i++) {
			k++; j--;
			k = (k+n)%n;
			j =(j+n)%n;
			count[2*n-1-p] *= A.a[k][j];
		}
	}
	for (int i = 0; i < n; i++)
		sum+= (count[i]-count[i + n]);
    cout<<"  "<<sum<<endl;         //返回行列式的值sum
}
 
//输出函数
void print(SMatrix A) 
{
	int i,j;
	for(i=0;i<A.row;i++)
	{
		for(j=0;j<A.col;j++)
		cout<<"  "<<A.a[i][j]<<"  ";
		cout<<endl;
	}
}

int main()
{
	int x;
	cout<<"**********************************"<<endl;
	cout<<"********欢迎使用矩阵计算器********"<<endl;
	cout<<"**********************************"<<endl;
    cout<<"*****   1-上三角矩阵"<<endl;
    cout<<"*****   2-下三角矩阵"<<endl;
    cout<<"*****   3-对称矩阵"<<endl;
	cout<<"*****   4-对角矩阵"<<endl;
	cout<<"*****   5-单位矩阵"<<endl;
    cout<<"请选择A矩阵类型:";
   //选择输出A矩阵 
    cin>>x;
    if(x==1)
    {
    	CreateSMatrixUppertri(p,A);
    	cout<<"输出上三角矩阵A："<<endl; 
    	print(A);
	}
	if(x==2)
	{
    	CreateSMatrixLowertri(p,A);
    	cout<<"输出下三角矩阵A："<<endl; 
    	print(A);
	}
	if(x==3)
	{
    	CreateSMatrixSymmetry(p,A);
    	cout<<"输出对称矩阵A："<<endl; 
    	print(A);
	}
	if(x==4)
	{
    	CreateSMatrixDiagonal(p,A);
    	cout<<"输出对角矩阵A："<<endl; 
    	print(A);
	}
	if(x==5)
	{
    	CreateSMatrixUnit(p,A);
    	cout<<"输出单位矩阵A："<<endl; 
    	print(A);
	}
	//选择输出B矩阵 
	cout<<"请选择B矩阵类型:";
	cin>>x;
	  if(x==1)
    {
    	CreateSMatrixUppertri(p,B);
    	cout<<"输出上三角矩阵B："<<endl; 
    	print(B);
	}
	if(x==2)
	{
    	CreateSMatrixLowertri(p,B);
    	cout<<"输出下三角矩阵B："<<endl; 
    	print(B);
	}
	if(x==3)
	{
    	CreateSMatrixSymmetry(p,B);
    	cout<<"输出对称矩阵B："<<endl; 
    	print(B);
	}
	if(x==4)
	{
    	CreateSMatrixDiagonal(p,B);
    	cout<<"输出对角矩阵B："<<endl; 
    	print(B);
	}
	if(x==5)
	{
    	CreateSMatrixUnit(p,B);
    	cout<<"输出单位矩阵B："<<endl; 
    	print(B);
	}
//选择矩阵运算	
	cout<<"**********************************"<<endl;
    cout<<"*****   1-矩阵相加"<<endl;
    cout<<"*****   2-矩阵相减"<<endl;
    cout<<"*****   3-矩阵相乘"<<endl;
    cout<<"*****   4-矩阵逆矩阵"<<endl; 
    cout<<"*****   5-矩阵转置"<<endl;
	cout<<"*****   6-矩阵行列式"<<endl; 
    cout<<"*****   请选择运算类型:";
    int y;
	while(cin>>y)
	{
		if(y==1)
		{
			if(Add(A,B,C))
			print(C);
			else
			cout<<"运算错误"<<endl; 
			cout<<"**********************************"<<endl;
		}
		else if(y==2)
			{
			if(Sub(A,B,C))
			print(C);
			else
			cout<<"运算错误"<<endl;
			cout<<"**********************************"<<endl;
		}
		else if(y==3)
		{
			if(Mul(A,B,C))
			print(C);
			else
			cout<<"运算错误"<<endl; 
			cout<<"----------------------------------"<<endl; 
			if(Mul(B,A,C))
			print(C);
			else
			cout<<"运算错误"<<endl; 
			cout<<"**********************************"<<endl;
		}
			else if(y==4)
		{
			Inverse(A);
			cout<<"----------------------------------"<<endl;
			Inverse(B);
			cout<<"**********************************"<<endl;
		}
		
		else if(y==5)
		{
			Tans(A,C);
			print(C);
			cout<<"----------------------------------"<<endl;
			Tans(B,C);
			print(C);
			cout<<"**********************************"<<endl;
		}
		else if(y == 6)
		{
		   int n;
	       Determinant(A);
	       cout<<"----------------------------------"<<endl;
	       Determinant(B);
	   	   cout<<"**********************************"<<endl;
		}
	}
}




