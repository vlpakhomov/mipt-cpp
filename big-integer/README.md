# big-integer

<br/>

<a id="description"></a>
## 🏷️ Description

*You have to expect things of yourself before you can do them 💫* </br>

This project is dedicated to the implementation of the big-integer class. It's task for C++ course by MIPT. We can see task-requirements is contains in [Task](#task). You should use [Table of Contents](#️table_of_contents) to navigate here. The main steps in development we can find in [To do](#to_do). If you want to contact me, look in [Contact](#contact).<br/>

Probably, I will add other useful and more complex features to this implementation in the future ⌛ 

<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="solutions_and_techniques"></a>
## 🎯 Solutions and Techniques

- Implementation encapsulation principle using class methods.
- Implementation information hiding principle using access specifiers.
- Use the #pragma preprocessor directive for header guards.
- Use sanitizers and valgrind for find memory bugs and undefined behaviour.
- Following the C++ style (not use C functions such as memset, use std toolkit). 
- Use basic rules and idioms for operator overloading.   

<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="table_of_contents"></a>
## 🗂️ Table of Contents 
- [Description](#️-description)
- [Solutions and Techniques](#-solutions-and-techniques)
- [Table of Contents](#️-table-of-contents)
- [Task](#-task)
- [To do](#-to-do)
- [Contact](#-contact)


<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="task"></a>
## 📄 Task 

## BigInteger

В этой задаче вам предстоит написать гигачада из мира чисел - BigInteger.

### Details

Класс должен поддерживать следующий функционал:
* Конструирование из std::string, int64_t. ☑️
* Сложение, вычитание, умножение, деление и остаток по модулю (и их assignment версии). 
  Деление должно работать не дольше, чем за O(n^2). Деление на 0 считать UB. ☑️
* Инкремент, декремент (префиксный, постфиксный), унарный минус -num (унарный плюс не надо). 
  Префиксный инкремент и декремент должны работать за O(1) в среднем. ☑️
* Операторы сравнения (`<`, `>`, `<=`, `>=`, `==`, `!=`). ☑️
* Операторы ввода из потока и вывода в поток. ☑️
* Метод ToString() возвращающий строковое представление числа. ☑️
* Опционально - литеральный суффикс bi для написания литералов типа BigInteger. ☑️

### Notes

1. Решение должно состоять из двух файлов: `big-integer.hpp` с объявлением класса и его методов и `big-integer.cpp` с определением всего необходимого. ☑️

2. Проверка устроена таким образом, что требует от вас жесткого следования принятым (выше)
   сигнатурам и именованиям сущностей (то есть никакие `MyBigInteger`, `__biginteger__`,`superSolver3000` не пройдут).
   Если вы реализовали требуемый функционал не полностью или интерфейс отличается от заявленного,
   в ответ вы получите ошибку компиляции. ☑️

3. В тесты включены проверки функциональности (методы работают так как требует условие),
   проверка эффективности реализации (что значит эффективно описано выше),
   проверка корректности работы с памятью (утечки памяти, обращения к памяти
   не принадлежащей процессу будут приводить к провалу) ☑️

4. В тестах есть проверки на то, что числа -0 не должно быть. Вместо него должен быть просто 0. ☑️

<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="to_do"></a>
## 📌 To do 

- README 👌
- Task ✅ 
- Tests ✅
- Code style and formatting 💤 
- Small object optimisation 💤
- Copy on write optimisation 💤


**Note: ✅ - perfect, 👌 - done, 🔄 - in progress, 💤 - waiting for** 

<p align="right"><a href="#string">Back to top ⬆️</a></p>


<a id="contact"></a>
## 📫 Contact  

Vladislav Pakhomov - [@VlPakhomov](https://t.me/VlPakhomov) - [vladislavpakhomov03@gmail.com](mailto:vladislavpakhomov03@gmail.com)

Project Link: https://github.com/VlPakhomov/mipt-cpp

<p align="right"><a href="#string">Back to top ⬆️</a></p>

