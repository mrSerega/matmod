#include "calculating.h"

using namespace std;

int main(int argc, char *argv[])
{
	vector<double> t_vector;
	vector<double> x_vector;
	int tSize = 5;
	int xSize = 5;
	
	for(int t = 0;t<tSize;++t){
		t_vector.push_back(t);
	}
	
	for(int x = 0;x<xSize;++x){
		x_vector.push_back(x);
	}
	
	calculating* calc = new calculating(t_vector,x_vector);
	
	return 0;
}
