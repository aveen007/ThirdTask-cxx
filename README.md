# secondTask c++
Нормальный конструктор вызывается, когда мы инициализируем новые объекты Number
```c++
    Number n1(1);
    Number n2(2);
```
Оператор копирования присваивания вызывается, когда правой стороной операции присваивания является lvalue (хранящийся в памяти, а не временный)
```c++
    n1 = n2;
```
Оператор перемещения присваивания вызывается, когда правой стороной операции присваивания является временное rvalue, которое собирается уничтожить
```c++
    Number n3;
    n3= Number(2);
```
Конструктор копирования вызывается, когда элементы добавляются в вектор в функции processVector, потому что создается копия члена класса, который добавляется, когда мы выполняем инструкцию pushback.
```c++
        Number num = Number(a);
        numbers.push_back(num);
```
Конструктор перемещения вызывается, когда добавляется более одного элемента в вектор, так как функция pushback, вероятно, не находит достаточно места в текущем векторе для выделения нового элемента, и поэтому создается новая копия с большими размерами, и старые элементы перемещаются в новую память.
```c++
        Number num = Number(a);
        numbers.push_back(num);
```
Деструктор вызывается, когда мы удаляем члены класса или каждый раз, когда временные члены класса уничтожаются.
Функция, используемая для обработки векторов
```c++
   void procesVector(std::vector<Number> numbers, int len) {
    if (len > 10 || len < 5) return;
    for (int i = 0; i < len; i++) {
        int a;
        std::cin >> a ;
        Number num = Number(a);

        numbers.push_back(num);
    }
    for (Number num : numbers) {
        print(num);

    }

}
```
Функция, используемая для обработки списков
```c++
void procesList(std::list<Number> numbers, int len) {
    if (len > 10 || len < 5) return;
    for (int i = 0; i < len; i++) {
        int a;
        std::cin >> a ;
        Number num = Number(a);
        numbers.push_back(num);
    }
    for (Number num : numbers) {
        print(num);

    }

}
```
переопределение оператора сложения
```c++
Number& Number::operator + (const Number& number) {
    if (this != &number) {
        number_value += number.number_value;
        number_name = translate(number_value);
    }
    std::cout << "addition copy operator" << std::endl;

    return *this;

}
// addition move operator 

Number& Number::operator +(const Number&& number) noexcept {
    if (this != &number) {

        number_value += number.number_value;
        number_name = translate(number_value);
        //number_name = std::move(number.number_name);
    }
    std::cout << "addition move operator" << std::endl;

    return *this;
}
```
Передача членов класса и возврат их, как по ссылке, так и без
```c++
Number add(Number num1, Number num2) {
    return num1+num2;
}
Number& addByreference(Number & num1, Number &num2) {

    return num1+num2;
}
```
чтобы перевести цифры в слова
```c++

string translate(int num) {
    if (num == 0) {
        return "zero";
    }

    std::vector<std::string> belowTwenty = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };
    std::vector<std::string> tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    std::string words = "";

    if (num >= 1000) {
        words += belowTwenty[num / 1000] + " thousand ";
        num %= 1000;
    }

    if (num >= 100) {
        words += belowTwenty[num / 100] + " hundred ";
        num %= 100;
    }

    if (num >= 20) {
        words += tens[num / 10] + " ";
        num %= 10;
    }

    if (num > 0) {
        words += belowTwenty[num] + " ";
    }

    return words.substr(0, words.size() - 1); // Remove the trailing space
}
```

** для определения, пожалуйста, смотрите Number.h
** для реализации, пожалуйста, смотрите Number.cpp
** для файла, использующего класс Number, пожалуйста, смотрите secondTaskc++.cpp

## консольный вывод
```none
Normal constructor
Normal constructor
assigmenet copy operator
Copy constructor
Copy constructor
addition copy operator
Copy constructor
destructor
destructor
4 four
destructor
Normal constructor
Copy constructor
2 two
destructor
2 two
destructor
5
100
Normal constructor
Copy constructor
destructor
22
Normal constructor
Copy constructor
Move constructor
destructor
destructor
34
Normal constructor
Copy constructor
Move constructor
Move constructor
destructor
destructor
destructor
66
Normal constructor
Copy constructor
Move constructor
Move constructor
Move constructor
destructor
destructor
destructor
destructor
101
Normal constructor
Copy constructor
Move constructor
Move constructor
Move constructor
Move constructor
destructor
destructor
destructor
destructor
destructor
Copy constructor
Copy constructor
100 one hundred
destructor
destructor
Copy constructor
Copy constructor
22 twenty two
destructor
destructor
Copy constructor
Copy constructor
34 thirty four
destructor
destructor
Copy constructor
Copy constructor
66 sixty six
destructor
destructor
Copy constructor
Copy constructor
101 one hundred one
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor

C:\Users\D34\Source\Repos\secondTask-c-\x64\Debug\secondTask c++.exe (process 10568) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

```

