#include <bits/stdc++.h>
using namespace std;
//�������̾��ǰѽ�λ�Ͳ���λ��������ֿ����ۼӲ���λ�ģ�ֱ�����ý�λΪֹ
int solve(int a, int b) {
    while(b != 0) {           //b����0��ʾȫ���ۼӵ�a��
        int cxor = a ^ b;     //��ʾ���ý�λ��λ
        int cand = a & b;     //��ʾҪ��λ��λ
        b = cand << 1;        //�ѽ�λ���ֵ����b
        a = cxor;             //���ۼӵ�ֵ����a
    }
    return a;
}
int main() {
    int a, b;
    while(cin >> a >> b) {
        cout << solve(a, b) << endl;
    }
}
