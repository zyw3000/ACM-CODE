//列出时间（h:m:s）与度数(rh:rm:rs)之间的方程：
//rs=6*s;          rm=6*m+s/10;           rh=30*h+0.5*m+s/120;
//各针之间的角度如下：
//rm-rs=6*m+(0.1-6)*s;       rh-rs=30*h+0.5*m+(1/120)-6)*s;       rh-rm=30*h+(0.5-6)*m+((1/120)-0.1)*s;



#include <iostream>
using namespace std;

const double vs_m = 59. / 10, vm_h = 11. / 120, vs_h = 719. / 120;
const double ts_m = 3600. / 59, tm_h = 43200. / 11, ts_h = 43200. / 719;

double min3(double a, double b, double c)
{
	double min = a;
    if( b < min )
        min = b;
    if( c < min ) 
        min = c;
    return min;
}

double max3(double a, double b, double c)
{
	double max = a;
    if( b > max )
        max = b;
    if( c > max )
        max = c;
    return max;
}

int main() 
{
	double D;
	double ans;
	while(cin>>D && D!=-1)
	{
		ans = 0;
		double fs_m = D / vs_m, ls_m = (360-D) / vs_m;
		double fm_h = D / vm_h, lm_h = (360-D) / vm_h;
		double fs_h = D / vs_h, ls_h = (360-D) / vs_h;
		
		for(double ft1 = fs_h, et1 = ls_h; et1 <= 43200.000001; ft1 += ts_h, et1 += ts_h)
		{
			for(double ft2 = fm_h, et2 = lm_h; et2 <= 43200.000001; ft2 += tm_h, et2 += tm_h)
			{
				if(ft2 > et1) break;
				if(et2 < ft1) continue;
				for(double ft3 = fs_m, et3 = ls_m; et3 <= 43200.000001; ft3 += ts_m, et3 += ts_m)
				{
					if(ft3 > et1 || ft3 > et2) break;
					if(et3 < ft1 || et3 < ft2) continue;
					double begin = max3(ft1,ft2,ft3);
					double end = min3(et1,et2,et3);
					ans += (end - begin);
				}
			}
		}
		ans /= 432;
		printf("%.3lf\n",ans);
	}
	return 0;
}
