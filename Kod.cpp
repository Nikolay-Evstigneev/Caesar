# include  < строка >
# включить  < iostream >
# include  < Windows.h >
используя  пространство имен  std ;
int  main ()
{
	setlocale (LC_ALL, « русский » );
	строка строка, ответ, команда;
	символ char ;
	int sh;
	cout << " Введите шаг сдвига: " << endl;
	cin >> sh;
	делать
	{
		cout << " Введите encode для кодирования или decode для расшифровки: " << endl;
		cin >> команда;
		если (команда == " декодировать " ) sh * = - 1 ;

	} while ((команда! = " кодировать " ) и (команда! = " декодировать " ));
	cout << " Введите строку: " << endl;
	cin >> line;
	ответ. изменить размер (строка. длина ());
	для ( int i = 0 ; i <line. length (); i ++)
	{
		если ((строка [i]> 96 ) и ((строка [i] < 123 ))
		{
			символ = строка [i] + = sh;
			символ = символ ( 97 + ( 26 * ( 1 - (символ / 97 ))) + ((символ - 97 )% 26 ));
			ответ [i] = символ;
		}
		else  if ((строка [i]> 64 ) и (строка [i] < 91 )) {
			символ = строка [i] + = sh;
			символ = символ ( 64 + ( 26 * ( 1 - (символ / 64 ))) + ((символ - 64 )% 26 ));
			ответ [i] = символ;
		}

		еще 
		{
			ответ [i] = строка [i];
		}
	}
	cout << " Oтвет: " << ответ;
}
