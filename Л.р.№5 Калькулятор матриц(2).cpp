#include <iostream>
#include <math.h>
using namespace std;
int i,j;
class MatrixCalculator{
private:
  float **X;
	int n;
	
public:
	MatrixCalculator(int);
	~MatrixCalculator(){}
	void Out();
	void AddMatrix(MatrixCalculator A,MatrixCalculator B);
	void TakeOutMatrix(MatrixCalculator A,MatrixCalculator B);
	double GetOpr();
};

void MatrixCalculator::Out(){
	for (i=0;i<n;i++)
	{{for (j=0;j<n;j++)
	cout<<X[i][j]<<"   ";
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

void MatrixCalculator:: AddMatrix(MatrixCalculator A,MatrixCalculator B){
	for (i=0;i<n;i++)
	{for (j=0;j<n;j++)
	this->X[i][j]=A.X[i][j]+B.X[i][j];}
	}

void MatrixCalculator::TakeOutMatrix(MatrixCalculator A,MatrixCalculator B){
	for (i=0;i<n;i++)
	{for (j=0;j<n;j++)
	this->X[i][j]=A.X[i][j]-B.X[i][j];}
	}

double MatrixCalculator::GetOpr(){
	if (n==2)
		return (this->X[0][0]*this->X[1][1]-this->X[1][0]*this->X[0][1]);
	int x;
	double y;
	double sum11=1,sum12=0,sum21=1,sum22=0;
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
	A3.AddMatrix(A1,A2);
	cout<<endl;
	cout<<"A1+A2="<<endl;
	A3.Out();
	A4.TakeOutMatrix(A2,A1);
	cout<<endl;
	cout<<"A2-A1="<<endl;
	A4.Out();
	float opred;
	opred=A1.GetOpr();
	cout<<"Det A1 = "<<opred<<endl;
	cin.get();
	cin.get();
}
