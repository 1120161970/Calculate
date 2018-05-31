#include "Define.h"

char str[10000000];

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int sn;//输入标志
	//int Involution;//乘方标记
	cout << "请根据对应的功能选择相应的编号：" << endl;
	cout << "1为出题，2求值，3为答题" << endl;
	cout << "1和2都是离线操作，3为在线操作，请用户注意" << endl;
	cout << "选择1和2时，请先在in.txt输入好对应的指令" << endl;
	cout << "1则是在文件中打上要生成的题目个数" << endl;
	cout << "2则是在文件中直接输入题目，注意不要有空格分格" << endl;
	cout << "请输入指令：" << endl;
	//打开文件
	while (~scanf("%d", &sn)) {
		if (sn == 1) {
			//出题，结果保存在文件中
			freopen("in.txt", "r", stdin);
			freopen("out.txt", "w", stdout);
			int num, len;
			cin >> num;//输入数据量要小于1000
			char s[1000] = { 0 };//临时数组，用来存每一次生成的算式
			for (int i = 0; i < num; i++) {
				memset(s, 0, sizeof(s));
				Create_problems(s);
				strcat(str, s);
			}
			len = strlen(str);
			//打印
			cout << str;
			fclose(stdin);
			fclose(stdout);
		}
		else if (sn == 2) {
			//输入题目求解
			freopen("in.txt", "r", stdin);
			freopen("out.txt", "w", stdout);
			char Infix[MAXX] = { 0 };//中缀
			char Suffix[MAXX] = { 0 };//后缀
			char temp[MAXX] = { 0 };//临时数组，用来处理乘方运算符
			int len, pos = 0;
			while (gets_s(str, MAXX) != NULL) {
				len = strlen(str);
				strcpy(Infix, str);

				//将**转换成^
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
			//读者答题
			int num = 0, score = 0, len;
			cout << "输入题目数量:" << endl;
			cin >> num;
			for (int i = 0; i < num; i++) {
				char s[1000] = { 0 };
				char Suffix[1005] = { 0 };
				char ans[10] = { 0 };
				double answer;
				Create_problems(s);
				cout << "第" << i + 1 << "题：" << s << endl;
				cout << "输入答案(答案可以用分数或者小数表示):" << endl;
				scanf("%s", ans);	//输入答案，可能为带/号的表达式 
				answer = atof(ans);
				len = strlen(ans);

				for (int i = 0; i < len; i++) {
					if (ans[i] == '/') { //分数
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
			cout << "得分：" << score << "/" << num << endl;
			break;
		}
		cout << endl;
		cout << "请输入指令：" << endl;
	}
	return 0;
}