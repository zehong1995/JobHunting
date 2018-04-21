class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int x = (int)array.size() - 1;
        int y = 0;
        while(x >= 0 && y < array[x].size()) {
            if (target == array[x][y]) {
                return true;
            } else if (target > array[x][y]) {
                y++;
            } else {
                x--;
            }
        }
        return false;
    }
};
/*
���⣺
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

˼·��
��Ϊ��֤�ϸ���������Կ��Դ����½ǳ���
target���ڵ�ǰֵ�������ƣ�
targetС�ڵ�ǰֵ��������
target���ڵ�ǰֵ���򷵻�true
ע��߽����⣬��Ϊ����һ��vector��̬���飬��һ����֤�����̶�
���Ӷ�ΪO(n+m)

*/
