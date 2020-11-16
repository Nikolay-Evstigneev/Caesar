# include  < string >
# include  < iostream >
# include  < Windows.h >
# include  <ctime>
# include  <fstream>
using namespace std; //блок библиотек
string time() 
{
	char str[26];
	time_t result = time(NULL);
	ctime_s(str, sizeof str, &result);
	return str;
}
int  main()
{
	string path = "log.txt";
	setlocale(LC_ALL, "Russian");
	string line, answer, command, rule;
	char symbol ;
	int sh;
	bool T; //описание переменных
	ofstream fout(path, ios_base::app);
	fout << "Program is started : " << time();
	do
	{
		T = true;
		cout << "Введите шаг сдвига: ";
		getline(cin, rule); //ввод данных
		for (int i = 0; i < rule.length(); i++) {
			if ((!isdigit(rule[i])) and (rule[i] != '-')) {
				T = false;
				cout << "Неверный ввод. Введите только целое число." << endl;
				break;
			}
		}
	} while (!T); //проверка ввода
	sh = atoi(rule.c_str());
	do
	{
		cout << "Введите encode для кодирования или decode для расшифровки: " << endl;
		getline(cin, command); //получение команды
		if (command == "decode") { sh *= -1; } //блок ввода команды
		else if (command != "encode") 
		{
			cout << "Неверный ввод. Попробуйте снова." << endl;
			fout << "Invalid enter.: " << time();
		}
	}
	while ((command!= "encode") and(command!= "decode"));
	cout << "Введите строку: " << endl;
	getline(cin, line); //ввод строки
	answer.resize(line.length());
	for(int i = 0; i < line.length(); i++) //блок работы со строкой
	{
		if((line[i] > 96) and((line[i] < 123)))
		{
			symbol = line[i] += sh;
			symbol = char(97 + (26 * (1 - (symbol / 97))) + ((symbol - 97) % 26));
			answer[i] = symbol;
		}
		else  if ((line[i] > 64) and(line[i] < 91)) {
		symbol = line[i] += sh;
		symbol = char(64 + (26 * (1 - (symbol / 64))) + ((symbol - 64) % 26));
		answer[i] = symbol;
		}
		else
		{
			answer[i] = line[i]; //присваивание
		}
	}
	cout << "Oтвет: " << answer; //вывод измененной строки
	if (command == "encode") {
		fout << "Line is encoded : " << time();
	}
	else {
		fout << "Line is decoded : " << time();
	}
	fout << "Program finished : " << time();
	fout << endl;
	fout.close();
}
