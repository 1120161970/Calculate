#include "Define.h"

char fuhao[8] = "(+-*/^)";

void Create_problems(char s[]) {
	int n[10] = { 0 }, num;//操作数以及个数
	char f[5] = { 0 };//运算符
	int f_flag;//运算符标志
	int bkflag = 0;//括号
	int pos = 0, inovation_1 = 0;//位置,乘方不能超过一个
	char change[10] = { 0 };

	num = rand() % 4 + 2;
	for (int i = 0; i < num; i++) n[i] = rand() % 50;
	itoa(n[0], change, 10);
	strcpy(s, change);
	pos += strlen(change);
	for (int i = 1; i < num; i++, bkflag+=2) {
		if (bkflag % 2 == 0 && bkflag < MAXX) 
			bkflag += rand() % 2;
		if (!inovation_1) f_flag = rand() % 5 + 1;
		else {
			f_flag = rand() % 5 + 1;
			while (f_flag == 5) f_flag = rand() % 5 + 1;
		}
		if (f_flag == 5) inovation_1 = 1;
		f[0] = fuhao[f_flag];//选择运算符
		strcat(s, f);
		pos++;
		
		if (bkflag % 2 == 1 && bkflag < MAXX && i < num - 1) {
			s[pos++] = '(';
			bkflag = MAXX + 2;
		}
		itoa(n[i], change, 10);
		strcat(s, change);
		pos += strlen(change);
		if (bkflag == MAXX + 4) {
			s[pos++] = ')';
			bkflag = MAXX + 5;
		}
	}
	if (bkflag > MAXX && bkflag % 2 == 0) {
		s[pos++] = ')';
	}
	s[pos++] = '\n';
}

void From_Infix_to_Suffix(char* Infix, char* Suffix) {
	//中缀转后缀
	char st[1005] = { 0 };//运算符栈
	int sn = 0, top = 0, i = 0;
	while (Infix[i] != '\0') {
		if (Infix[i] >= '0'&&Infix[i] <= '9') {
			Suffix[sn++] = Infix[i];
		}
		else if (!top || Infix[i] == '(') {
			st[top++] = Infix[i];
			if (Suffix[sn - 1] != ' ')
				Suffix[sn++] = ' ';
		}
		else if (Infix[i] == ')') {
			while (st[top - 1] != '(') {
				if (Suffix[sn - 1] != ' ') 
					Suffix[sn++] = ' ';
				Suffix[sn++] = st[top - 1];
				top--;
			}
			top--;
		}
		else if (Infix[i] == ' ') {
			if (Suffix[sn - 1] != ' ')
				Suffix[sn++] = ' ';
		}
		else {
			//+-*/^
			while (Judge(Infix[i], st[top - 1]) == true && top > 0) {
				if (Suffix[sn - 1] != ' ')
					Suffix[sn++] = ' ';
				Suffix[sn++] = st[top - 1];
				top--;
			}
			st[top++] = Infix[i];
			if (Suffix[sn - 1] != ' ')
				Suffix[sn++] = ' ';
		}
		i++;
	}
	while (top) {
		if (Suffix[sn - 1] != ' ')
			Suffix[sn++] = ' ';
		Suffix[sn++] = st[--top];
	}
	Suffix[sn] = '\0';
}

bool Judge(char c1, char c2) {
	int n1 = 0, n2 = 0;
	for (int i = 0; i < 7; i++) {
		if (c1 == fuhao[i]) n1 = i;
		if (c2 == fuhao[i]) n2 = i;
	}
	if (n2 >= n1) return true;
	else if (n1 == 2 && n2 == 1) return true;
	else if (n1 == 4 && n2 == 3) return true;
	else return false;
}

double Suffix_Value(char* Suffix) {
	//后缀表达式求值
	double st[1005] = { 0 }, tem = 0.0;
	int top = 0, i = 0;
	while (Suffix[i] != '\0') {
		if (Suffix[i] >= '0' && Suffix[i] <= '9') {
			tem = tem * 10 + Suffix[i] - '0';
		}
		else if (Suffix[i] == ' ') {
			st[top++] = tem;
			tem = 0.0;
		}
		else {
			int n1;
			for (int j = 1; j <= 5; j++) {
				//top变化
				if (Suffix[i] == fuhao[j]) {
					n1 = j;
					break;
				}
			}
			//对栈顶两个操作数经常比较
			if (n1 == 1) tem = st[top - 2] + st[top - 1];
			else if (n1 == 2) tem = st[top - 2] - st[top - 1];
			else if (n1 == 3) tem = st[top - 2] * st[top - 1];
			else if (n1 == 4) {
				if (st[top - 1])
					tem = st[top - 2] / st[top - 1];
				else
					cout << "除数不能为0" << endl;
			}
			else if (n1 == 5) tem = pow(st[top - 2], st[top - 1]);
			top -= 2;
		}
		i++;
	}
	st[0] = tem;
	return st[0];
}

bool _Fraction(int &x, int &y, double num) {
	double res;
	double Fraction[35][30] = {
		//简化形式相同的统一表示为0
		//每一行中注释中表示的都是第一次出现的有效浮点数
		{0},{0},
		{0.500000},// 1/2
		{0.333333, 0.666667},// 1/3,2/3
		{0.250000 ,0 ,0.750000},// 1/4,3/4
		{0.200000 ,0.400000 ,0.600000 ,0.800000},// 1/5,2/5,3/5,4/5
		{0.166667 ,0 ,0 ,0 ,0.833333},// 1/6,5/6
		{0.142857 ,0.285714 ,0.428571 ,0.571429 ,0.714286 ,0.857143},// 1/7,2/7,3/7,4/7,5/7,6/7
		{0.125000 ,0, 0.375000 ,0 ,0.625000 ,0 ,0.875000 }, // 1/8,3/8,5/8,7/8
		{0.111111 ,0.222222 ,0 ,0.444444 ,0.555556 ,0 ,0.777778 ,0.888889}, //1/9,2/9,4/9,5/9,7/9,8/9
		{0.100000 ,0 ,0.300000 ,0 ,0.500000 ,0 ,0.700000 ,0 ,0.900000}, //1/10,3/10,5/10,7/10,9/10
		{0.083333, 0, 0, 0, 0.416667, 0, 0.583333, 0, 0, 0.916667}, //1/12,5/12,7/12,11/12,
		{0.076923, 0.153846, 0.230769, 0.307692, 0.384615, 0.461538, 0.538462, 0.615385, 0.692308, 0.769231, 0.846154, 0.923077},
			//1/13,2/13,3/13,4/13,5/13,6/13,7/13,8/13,9/13,10/13,11/13,12/13
		{0.071429, 0, 0.214286, 0, 0, 0, 0, 0, 0.642857, 0, 0.785714, 0, 0.928571},
			//1/14,3/14,5/14,9/14,11/14,13/14
		{0.066667, 0.133333, 0, 0.266667, 0, 0, 0.466667, 0.533333, 0, 0, 0.733333, 0, 0.866667, 0.933333},
			//1/15,2/15,4/15,7/15,8/15,0,11/15,13/15,14/15
		{0.062500, 0, 0.187500, 0, 0.312500, 0, 0.437500, 0, 0.562500, 0, 0.687500, 0, 0.812500, 0, 0.937500},
			//1/16,3/16,5/16,7/16,9/16,11/16,13/16,15/16
		{0.058824, 0.117647, 0.176471, 0.235294, 0.294118, 0.352941, 0.411765, 0.470588, 0.529412, 0.588235, 0.647059, 0.705882, 0.764706, 0.823529, 0.882353, 0.941176},
			//1/17,2/17,3/17,4/17,5/17,6/17,7/17,8/17,9/17,10/17,11/17,12/17,13/17,14/17,15/17,16/17
		{0.055556, 0, 0, 0, 0.277778, 0, 0.388889, 0, 0, 0, 0.611111,0, 0.722222, 0, 0, 0, 0.944444},
			//1/18,5/18,7/18,11/18,13/18,17/18
	};
	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < i; j++) {
			if (num - Fraction[i][j] < MINN) {
				x = i;
				y = j;
				return true;
			}
		}
	}
	return false;
}