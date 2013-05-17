#include <iostream>
#include <math.h>
using namespace std;
int i,j;
class MatrixCalculator{  
public:
	float **X;
	int n;
	MatrixCalculator(int);
	~MatrixCalculator(){
	/*	for(i=0;i<n;i++)
	delete [] X[i];
	delete []X;*/}
	void Out();
	MatrixCalculator operator +(const MatrixCalculator &);
	MatrixCalculator operator -(const MatrixCalculator &);
	MatrixCalculator operator *(const MatrixCalculator &);
	MatrixCalculator operator =(const MatrixCalculator &);
	MatrixCalculator operator /( MatrixCalculator &);
	float GetOpr();
};

void MatrixCalculator::Out(){
	for (i=0;i<n;i++)
	{{for (j=0;j<n;j++)
	{
	cout<<X[i][j]<<" ";
	}
}
	cout<<endl;}
}
MatrixCalculator::MatrixCalculator(int k){
	int a;
	n=k;
	X=new float*[n];
	for (i=0;i<n;i++)
	X[i]=new float[n];
cout<<"Vv s klaviaturi?(1-da,0-net)";
	cin>>a;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{if (a==0) X[i][j]=(rand()%1000)/10.;
		else cin>>X[i][j];
	}
}

MatrixCalculator MatrixCalculator:: operator +(const MatrixCalculator &a){
	MatrixCalculator p(n);
	for (i=0;i<n;i++)
	{for (j=0;j<n;j++)
	p.X[i][j]=this->X[i][j]+a.X[i][j];}
	return p;
	}

MatrixCalculator MatrixCalculator:: operator -(const MatrixCalculator &a){
	MatrixCalculator p(n);
	for (i=0;i<n;i++)
	{for (j=0;j<n;j++)
	p.X[i][j]=this->X[i][j]-a.X[i][j];}
	return p;
	}


MatrixCalculator MatrixCalculator:: operator *(const MatrixCalculator &a){
	MatrixCalculator p(n);
	int k;
for (i=0;i<n;i++)
for (j=0;j<n;j++)
{p.X[i][j]=0;
for (k=0;k<n;k++)
	p.X[i][j]+=this->X[i][k]*a.X[k][j];}
return p;
}

MatrixCalculator MatrixCalculator:: operator /( MatrixCalculator &a){
MatrixCalculator M(n-1);
MatrixCalculator K(n);	
if (a.GetOpr()==0){
	cout<<"Delenie nevozmozhno!"<<endl;
	return a;
}
else{
int c,d;
		for (c=0;c<n;c++)
			for (d=0;d<n;d++)
		{
			for (i=0;i<n;i++)
				for (j=0;j<n;j++)
		{
			if ((i!=c)&&(j!=d)){
			if ((i>c)&&(j>d))
				M.X[i-1][j-1]=a.X[i][j];
			if	((i>c)&&(j<d))
				M.X[i-1][j]=a.X[i][j];
			if	((i<c)&&(j>d))
				M.X[i][j-1]=a.X[i][j];
			if ((i<c)&&(j<d)) M.X[i][j]=a.X[i][j];	 
			}
				}
				//M.Out();
				
				K.X[d][c]=M.GetOpr()*pow(-1.,(c+d))*(1./(a.GetOpr()));
				

}			cout<<"A1^(-1)"<<endl;
			K.Out();
			cout<<endl;
			MatrixCalculator V(n);
			V=(*this)*K;
			return V;}
	}



MatrixCalculator MatrixCalculator:: operator =(const MatrixCalculator &a){
if (this!=&a)
{
	X=new float*[n];
	for (i=0;i<n;i++)
	X[i]=new float[n];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			this->X[i][j]=a.X[i][j];
}
return *this;
}

float MatrixCalculator::GetOpr(){
	if (n==1) return this->X[0][0];
	if (n==2)
		return (this->X[0][0]*this->X[1][1]-this->X[1][0]*this->X[0][1]);
	float y;
	int x;
	float sum11=1,sum12=0,sum21=1,sum22=0;
	for (i=0;i<n;i++)
	{
		sum11=1;
		x=2*n-1-i;
		sum21=1;
		for	(j=0;j<n;j++)
		{
			sum21*=this->X[j][x%n];
			x--;
			sum11*=this->X[j][(j+i)%n];
		}
		sum22+=sum21;
		sum12+=sum11;
	}
	y=sum12-sum22;
	return y;

}

void main(){
	int n;
	cout<<"Vv razmernost' matrici"<<endl;
	cin>>n;
	MatrixCalculator A1(n),A2(n),A3(n),A4(n);
	cout<<"Matrica A1:"<<endl;
	A1.Out();
	cout<<endl;
	cout<<"Matrica A2:"<<endl;
	A2.Out();
	A3=A1+A2;
	cout<<endl;
	cout<<"A1+A2="<<endl;
	A3.Out();
	A4=A2-A1;
	cout<<endl;
	cout<<"A2-A1="<<endl;
	A4.Out();
	int opred;
	opred=A1.GetOpr();
	cout<<"Det A1 = "<<opred<<endl;
	A4=A1*A2;
	cout<<"A1*A2="<<endl;
	A4.Out();
	A4=A2/A1;
	cout<<"A2/A1="<<endl;
	A4.Out();
	cout<<endl;
	cin.get();
	cin.get();
}
