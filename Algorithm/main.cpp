#include "Define.h"

char str[10000000];

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int sn;//�����־
	//int Involution;//�˷����
	cout << "����ݶ�Ӧ�Ĺ���ѡ����Ӧ�ı�ţ�" << endl;
	cout << "1Ϊ���⣬2��ֵ��3Ϊ����" << endl;
	cout << "1��2�������߲�����3Ϊ���߲��������û�ע��" << endl;
	cout << "ѡ��1��2ʱ��������in.txt����ö�Ӧ��ָ��" << endl;
	cout << "1�������ļ��д���Ҫ���ɵ���Ŀ����" << endl;
	cout << "2�������ļ���ֱ��������Ŀ��ע�ⲻҪ�пո�ָ�" << endl;
	cout << "������ָ�" << endl;
	//���ļ�
	while (~scanf("%d", &sn)) {
		if (sn == 1) {
			//���⣬����������ļ���
			freopen("in.txt", "r", stdin);
			freopen("out.txt", "w", stdout);
			int num, len;
			cin >> num;//����������ҪС��1000
			char s[1000] = { 0 };//��ʱ���飬������ÿһ�����ɵ���ʽ
			for (int i = 0; i < num; i++) {
				memset(s, 0, sizeof(s));
				Create_problems(s);
				strcat(str, s);
			}
			len = strlen(str);
			//��ӡ
			cout << str;
			fclose(stdin);
			fclose(stdout);
		}
		else if (sn == 2) {
			//������Ŀ���
			freopen("in.txt", "r", stdin);
			freopen("out.txt", "w", stdout);
			char Infix[MAXX] = { 0 };//��׺
			char Suffix[MAXX] = { 0 };//��׺
			char temp[MAXX] = { 0 };//��ʱ���飬��������˷������
			int len, pos = 0;
			while (gets_s(str, MAXX) != NULL) {
				len = strlen(str);
				strcpy(Infix, str);

				//��**ת����^
				for (int i = 0; i < len; i++) {
					if (str[i] == '*'&&str[i + 1] == '*') {
						temp[pos++] = '^';
						i++;
					}
					else {
						temp[pos++] = str[i];
					}
				}

				From_Infix_to_Suffix(temp, Suffix);
				//cout << Suffix << endl;
				while(Suffix[strlen(Suffix) - 1] == ' ') 
					Suffix[strlen(Suffix) - 1] = '\0';
				double Right_Answer = Suffix_Value(Suffix);
				//float_to_fraction(Right_Answer);
				memset(Infix, 0, sizeof(Infix));
				memset(temp, 0, sizeof(temp));
				memset(Suffix, 0, sizeof(Suffix));
				pos = 0;
				cout << Right_Answer << endl;
			}
		}
		else if (sn == 3) {
			//���ߴ���
			int num = 0, score = 0, len;
			cout << "������Ŀ����:" << endl;
			cin >> num;
			for (int i = 0; i < num; i++) {
				char s[1000] = { 0 };
				char Suffix[1005] = { 0 };
				char ans[10] = { 0 };
				double answer;
				Create_problems(s);
				cout << "��" << i + 1 << "�⣺" << s << endl;
				cout << "�����(�𰸿����÷�������С����ʾ):" << endl;
				scanf("%s", ans);	//����𰸣�����Ϊ��/�ŵı��ʽ 
				answer = atof(ans);
				len = strlen(ans);

				for (int i = 0; i < len; i++) {
					if (ans[i] == '/') { //����
						if (ans[0] == '-') {
							From_Infix_to_Suffix(ans + 1, Suffix);
							answer = -1 * Suffix_Value(Suffix);
						}
						else {
							From_Infix_to_Suffix(ans, Suffix);
							answer = Suffix_Value(Suffix);
						}
					}
				}

				s[strlen(s) - 1] = '\0';
				From_Infix_to_Suffix(s, Suffix);
				double Right_Answer = Suffix_Value(Suffix);
				if (fabs(answer - Right_Answer) < MINN) {
					cout << "Right!" << endl;
					score++;
				}
				else {
					cout << "Wrong!" << endl << "The Right Answer is ";
					int n1, n2;
					if (_Fraction(n1, n2, Right_Answer) == true) {
						cout << n1 << '/' << n2 << endl;
					}
					else cout << Right_Answer << endl;
				}
				memset(str, '\0', sizeof(str));
			}
			cout << "�÷֣�" << score << "/" << num << endl;
			break;
		}
		cout << endl;
		cout << "������ָ�" << endl;
	}
	return 0;
}