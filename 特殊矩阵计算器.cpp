#include<iostream>
#include<cmath>
#define max 100
using namespace std;
typedef struct{
	int a[max][max];
	int row,col;    //����������������� 
}SMatrix;        //�洢�ṹ
typedef struct{
	int array[max];
	int n;      //�������Ľ� 
}M;
SMatrix A,B,C,D;
    M p; 
    
//�����ѹ���洢
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

//���������Ǿ��� 
void CreateSMatrixUppertri(M &a,SMatrix &A)
{
	int i,j,t,n;
	cout<<"�����������Ǿ��������������(������������ͬ)��";
	cin>>A.row>>A.col;    //�����С��� 
	n=A.row; 
	a.n=n; 
	printf("������%d������",n*(n+1)/2);
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

//���������Ǿ��� 
void CreateSMatrixLowertri(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"�����������Ǿ��������������(������������ͬ)��";
	cin>>A.row>>A.col;
	n=A.row; 
	a.n=n; 
	printf("������%d������",n*(n+1)/2);
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
	
//�����Գƾ��� 
void CreateSMatrixSymmetry(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"������Գƾ��������������(������������ͬ)��";
	cin>>A.row>>A.col;
	n=A.row; 
	a.n=n; 
	printf("������%d������",n*(n+1)/2);
	for(i=0;i<n*(n+1)/2;i++)
	cin>>a.array[i];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	t=CompressSMatrix(3,i,j,n);
	A.a[i][j]=a.array[t];
    }
}
	
//�����ԽǾ��� 
void CreateSMatrixDiagonal(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"������ԽǾ��������������(������������ͬ)��";
	cin>>A.row>>A.col;
	n=A.row; 
	a.n=n; 
	printf("������%d������",n);
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
	
//������λ���� 
void CreateSMatrixUnit(M &a,SMatrix &A){
	int i,j,t,n;
	cout<<"�����뵥λ���������������(������������ͬ)��";
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


//�ӷ� 
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

//���� 
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

//�˷�
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
		for(i=0;i<A.row;i++)   //A������ 
		for(j=0;j<A.col;j++)   //A��������B������ 
		for(k=0;k<A.col;k++)   //B������ 
		C.a[i][j]+=A.a[i][k]*B.a[k][j];
	}
	return 1;
 } 
 
 
 //������
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
		cout<<"����������"<<endl;
		for(i=0;i<n;i++)
		{
		   for(j=0;j<n;j++)
		   cout<<A.a[i][j]<<"  ";
		   cout<<endl;
	    }
	}
}


 //ת�� 
 void Tans(SMatrix A,SMatrix &C)
 {
 	int i,j;
 		C.row=A.row;
		C.col=A.col;
 	for(i=0;i<A.row;i++) 
	for(j=0;j<A.col;j++)
	C.a[j][i]=A.a[i][j];
 }
 
 //��������ʽ��ֵ 
 void Determinant(SMatrix A) {   
	int count[100];      
	int sum=0;
	int n;
	n=A.row;   //nΪ����Ľ� 
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
    cout<<"  "<<sum<<endl;         //��������ʽ��ֵsum
}
 
//�������
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
	cout<<"********��ӭʹ�þ��������********"<<endl;
	cout<<"**********************************"<<endl;
    cout<<"*****   1-�����Ǿ���"<<endl;
    cout<<"*****   2-�����Ǿ���"<<endl;
    cout<<"*****   3-�Գƾ���"<<endl;
	cout<<"*****   4-�ԽǾ���"<<endl;
	cout<<"*****   5-��λ����"<<endl;
    cout<<"��ѡ��A��������:";
   //ѡ�����A���� 
    cin>>x;
    if(x==1)
    {
    	CreateSMatrixUppertri(p,A);
    	cout<<"��������Ǿ���A��"<<endl; 
    	print(A);
	}
	if(x==2)
	{
    	CreateSMatrixLowertri(p,A);
    	cout<<"��������Ǿ���A��"<<endl; 
    	print(A);
	}
	if(x==3)
	{
    	CreateSMatrixSymmetry(p,A);
    	cout<<"����Գƾ���A��"<<endl; 
    	print(A);
	}
	if(x==4)
	{
    	CreateSMatrixDiagonal(p,A);
    	cout<<"����ԽǾ���A��"<<endl; 
    	print(A);
	}
	if(x==5)
	{
    	CreateSMatrixUnit(p,A);
    	cout<<"�����λ����A��"<<endl; 
    	print(A);
	}
	//ѡ�����B���� 
	cout<<"��ѡ��B��������:";
	cin>>x;
	  if(x==1)
    {
    	CreateSMatrixUppertri(p,B);
    	cout<<"��������Ǿ���B��"<<endl; 
    	print(B);
	}
	if(x==2)
	{
    	CreateSMatrixLowertri(p,B);
    	cout<<"��������Ǿ���B��"<<endl; 
    	print(B);
	}
	if(x==3)
	{
    	CreateSMatrixSymmetry(p,B);
    	cout<<"����Գƾ���B��"<<endl; 
    	print(B);
	}
	if(x==4)
	{
    	CreateSMatrixDiagonal(p,B);
    	cout<<"����ԽǾ���B��"<<endl; 
    	print(B);
	}
	if(x==5)
	{
    	CreateSMatrixUnit(p,B);
    	cout<<"�����λ����B��"<<endl; 
    	print(B);
	}
//ѡ���������	
	cout<<"**********************************"<<endl;
    cout<<"*****   1-�������"<<endl;
    cout<<"*****   2-�������"<<endl;
    cout<<"*****   3-�������"<<endl;
    cout<<"*****   4-���������"<<endl; 
    cout<<"*****   5-����ת��"<<endl;
	cout<<"*****   6-��������ʽ"<<endl; 
    cout<<"*****   ��ѡ����������:";
    int y;
	while(cin>>y)
	{
		if(y==1)
		{
			if(Add(A,B,C))
			print(C);
			else
			cout<<"�������"<<endl; 
			cout<<"**********************************"<<endl;
		}
		else if(y==2)
			{
			if(Sub(A,B,C))
			print(C);
			else
			cout<<"�������"<<endl;
			cout<<"**********************************"<<endl;
		}
		else if(y==3)
		{
			if(Mul(A,B,C))
			print(C);
			else
			cout<<"�������"<<endl; 
			cout<<"----------------------------------"<<endl; 
			if(Mul(B,A,C))
			print(C);
			else
			cout<<"�������"<<endl; 
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




