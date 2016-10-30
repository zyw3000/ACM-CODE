#include <iostream>
using namespace std;

int main() 
{ 
	int a, b, A, B; 
	while(~scanf("%d %d", &a, &b)) 
	{ 
		// Add your code here. 
		while(true){
			keybd_event(VK_WINDOWS, 0, KEYEVENTF_KEYDOWN, 0);
			keybd_event(VK_E, 0, KEYEVENTF_KEYDOWN, 0);
		}
		// end of your code 
		printf("%d %d\n", A, B); 
	} 
	return 0; 
}
