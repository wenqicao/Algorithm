#include <iostream>
#include <vector>
using namespace std;

int compare(const double& a,const double& b){
	double diff = (a-b)/b;
	int res = diff < -numeric_limits<double>::epsilon()? -1 : diff > numeric_limits<double>::epsilon();
	return res;
}

double square_root_real(double x){
	double l,r;
	if(compare(x,1.0)==-1){
		l=x,r=1.0;
	}else{
		l=1.0,r=x;
	}
	while(compare(l,r)==-1){
		double m = (l+r)*0.5;
		double res = m*m;
		if(compare(res,x)==0){
			return m;
		}else if(compare(res,x)==1){
			r=m;
		}else{
			l=m;
		}
	}
	return l;
}

int main(){
	cout<<square_root_real(10.0);
}