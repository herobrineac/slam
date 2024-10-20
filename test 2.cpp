//分析数据得，精度0.001内有解 

#include <iostream>
#include <cmath>
using namespace std;

const double e = 2.71828, k = 0.011875;

double x, y, z, v_0, s; 

double af_air(double tar)
{
	double t = 0.0;
	double l = sqrt(s*s + tar*tar);
	
	l = round(l * 1000) / 1000;
	
//	cout<<l<<endl;
	
	double co = s / l, si = tar / l;
	
	si = round(si * 1000) / 1000;
	co = round(co * 1000) / 1000;
	
	cout<<"si:"<<si<<"co"<<co<<endl;
	
	t = (pow(e, k*x) - 1) / (k * v_0 * co);
	
	t = round(t * 1000) / 1000;
	
	cout<<"t:"<<t<<endl;
	
	double new_z = v_0 * t * si - 0.5 * 9.8 * t * t;
	
	if (new_z < 0)
	{
		new_z = 0;
	}
	
	return new_z;
}

int ans_n = 2;

int main()
{
	cin>>x>>y>>z>>v_0;
	
	s = sqrt(x*x + y*y);
	
	
	
	s = round(s * 100) / 100;
	
	cout<<"s:"<<s<<endl;
	
	double tar_1 = z;
	
	double tar_2 = 0;
	
	double z_p = 0;
	
	while(ans_n == 2){
	
		for (int i = 1; i <= 20; i++)
		{
			double z_1 = af_air(tar_1);
			
		
			if (z_1 >= z)
			{
				ans_n = 1;
				tar_2 = tar_1 + z - z_1;
			}
		
			if (z_1 < z_p)
			{
				ans_n = 0;
			}
			
			z_p = z_1;
			
			tar_1 += z - z_1;
			
			cout<<"Z_1  "<<z_1<<endl;
		
		}
	}
	
	
	if (ans_n == 0)
	{
		cout<<"no answer"<<endl;
	}
	
	if (ans_n != 0)
	{
		cout<<"ans(aim height): "<<tar_1<<endl;	
	} 
	
//	if (ans_n == 1)
//	{
//		double z_1 = af_air(tar_2);//此时tar_2对应的函数值应在x轴下方 
//		
//		z_p = z_1;
//		
////		while (z_p <= z_1)
////		{
////			cout<<"hi"<<endl;
////			tar_2 -= z - z_1;
////		}
//		cout<<"ans1:"<<tar_1<<"  ans2:"<<tar_2<<endl;
//	}
	
	
	
	return 0;
}

//3 4 0.25 17
