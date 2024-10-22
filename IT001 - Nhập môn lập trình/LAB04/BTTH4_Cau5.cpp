/* nhập vào một số nhị phân, có tối đa 8 kí số, đổi ra số hệ thập phân tương ứng */

 #include <iostream>
 #include <math.h>

 using namespace std;

 int bintodec(long bin)
 {
     int s = 0;
     int dec = 0;
     while (bin > 0)
     {
         dec = dec + (bin % 10) * pow(2,s);
         s++;
         bin = bin / 10;
     }
     return dec;
 }
 int main()
 {
     long n;
     cout << "nhap so nhi phan (toi da 8 ki tu): ";
     cin >> n;
     cout << "he thap phan cua " << n << " la: " << bintodec(n) << endl;
 }
