# string

<br/>

<a id="description"></a>
## 🏷️ Description

*If you never know failure, you will never know success 💫* </br>

This project is dedicated to the implementation of the string class. It's task for C++ course by MIPT. We can see task-requirements is contains in [Task](#task). You should use [Table of Contents](#️table_of_contents) to navigate here. The main steps in development we can find in [To do](#to_do). If you want to contact me, look in [Contact](#contact).<br/>

Probably, I will add other useful and more complex features to this implementation in the future ⌛ 

<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="solutions_and_techniques"></a>
## 🎯 Solutions and Techniques

- Implementation encapsulation principle using class methods.
- Implementation information hiding principle using access specifiers.
- Idiomatic implementation class constructors (copy-and-swap idiom, member initializer list, only non-trivial actions in bogy).
- Use the #pragma preprocessor directive for header guards.
- Well-designed class, id est there are no friend, mutable and etc bad keyword.
- Use sanitizers and valgrind for find memory bugs and undefined behaviour.
- Following the idiomatic C++ style (not use C functions such as memset, use std toolkit). 
- Use clang-tidy linter for general static code analysis.
- Use clang-format for reformat code following the Google C++ Code Style.
- Use cpplint linter for static code analysis of conforms to Google C++ Code Style. 
- Implementation the rule of three.
- Everything is covered by unit tests.
- Use basic rules and idioms for operator overloading.   
- Writing quality code using practicing “Make It Work, Make It Right, Make It Fast”.

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

## String

В этой задаче вам нужно реализовать класс динамически расширяющейся строки.
Проблема стековых и выделяемых в куче строк заключается в том, что они имеют фиксированный размер
и не умеют автоматически расширяться при необходимости (в отличие, например, от `str` в Python).
Кроме того, при выделении памяти в динамической области возникает потребность в
ручном отслеживании возможных утечек памяти, что накладывает дополнительные сложности на процесс разработки.

Эти проблемы можно обойти, используя ООП функционал C++. В частности, механизм
инкапсуляции позволяет реализовать методы добавления элементов, при вызове которых
строка будет автоматически расширяться, создавая иллюзию неограниченного контейнера.
А механизмы работы с ресурсами гарантируют своевременное выделение и очищение памяти.

Здесь естественным образом возникает разделение понятий "размера" строке (size) и
ее "вместимости" (capacity). С++ в каждый момент времени позволяет поддерживать
массивы конечной вместимости, при этом фактический размер (количество добавленных элементов)
может быть меньше этого значения.
*Почему бы постоянно не поддерживать равенство между этими величинами?* - это не эффективно.
Допустим, мы добавляем элементы по одному. Тогда при каждом обновлении будет
происходить перевыделение исходной памяти с последующим копированием всех старых элементов в новый буфер.
Легко видеть, что в этом случае общее число копирований будет квадратичным образом зависеть от числа добавленных элементов.
Оказыватся, что, если при каждом переполнении массива увеличивать его вместимость
в константное число раз, то можно добиться линейной зависимости числа операций над
массивом от числа добавляемых элементов (https://en.wikipedia.org/wiki/Dynamic_array#Geometric_expansion_and_amortized_cost).
В вашем решении будет проверяться корректность работы данной схемы при множителе
равном 2 (то есть, если фактический размер изменяется так: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> ..., то
вместимость меняется следующим образом: 0 -> 1 -> 2 -> 4 -> 4 -> 8 -> ...).


### Details

От вас требуется реализовать класс `String` - упрощенный аналог `std::string`.
Класс должен поддерживать следующий функционал:
* Конструктор по умолчанию - создает пустую строку, никакой памяти не выделяется! ☑️
* Конструктор, принимающий `size` и `character` (именно в этом порядке) - создает строку длины `size`,
  заполненный символами `character` ☑️
* Конструктор от `const char*`, для того, чтобы узнать длину C-style строки, используйте функцию `strlen` ☑️
* Правило "трех":
    1. Конструктор копирования ☑️
    2. Копирующий оператор присваивания ☑️
    3. Деструктор ☑️
* Метод `Clear()` - устанавливает размер в 0, деаллокации выделенной памяти при этом НЕ происходит ☑️
* Метод `PushBack(character)` - добавляет букву `character` в конец строки ☑️
* Метод `PopBack()` - удаляет последнюю букву. В случае пустой строки должен 
  ничего не делать, хотя для `std::string` это будет UB ☑️
* Метод `Resize(new_size)` - изменяет размер на `new_size`. Если вместимость 
  не позволяет хранить столько символов, то выделяется новый буфер с вместимостью `new_size`. ☑️
* Метод `Resize(new_size, character)` - то же, что и `Resize(new_size)`, но в случае `new_size > size` 
  заполняет недостающие элементы значением `character`. ☑️
* Метод `Reserve(new_cap)` - изменяет вместимость на `max(new_cap, текущая вместимость)` 
  (если new_cap <= текущая вместимость, то делать ничего не нужно). Размер при этом не изменяется. ☑️
* Метод `ShrinkToFit()` - уменьшает `capacity` до `size` (если `capacity` > `size`) ☑️
* Метод `Swap(other)` - обменивает содержимое с другой строкой `other`. Должен работать за O(1) ☑️
* Константный и неконстантный оператор доступа по индексу []. Неконстантный должен
  позволять изменять полученный элемент (`a[1] = 5`) ☑️
* Методы `Front()` и `Back()` - доступ к первому и послeднему символам (тоже по две версии). ☑️
* Метод `Empty()` - `true`, если строка пустая (размер 0). ☑️
* Метод `Size()` - возвращает размер. ☑️
* Метод `Capacity()` - возвращает вместимость. ☑️
* Метод `Data()` - возвращает указатель на начало массива. ☑️
* Операторы сравнения (`<`, `>`, `<=`, `>=`, `==`, `!=`), задающие лексикографический порядок. ☑️
* Операторы + и += для конкатенации строк. Например, `"ab" + "oba" = "aboba"`. Операция `s += t` должна работать за `O(|t|)`!!! Иначе не дождетесь итогов тестирования и спалите тестирующие сервера ☑️
* Оператор умножения на число. Принимает строку `str` и число `n` (именно в таком порядке) и вернет строку вида `str +  ... + str` (`n` раз). 
  Сложность по времени должна быть O(длины результата). Умножение числа на строку должно приводить ошибку компиляции!
  Загадка о лектора по алгоритмам - не возникло ли у вас аналогии с каким-то известным вам алгоритмом?) ☑️

* Операторы ввода из потока и вывода в поток. ☑️
* Метод `std::vector<String> Split(const String& delim = " ")` - аналог сплита в питоне. ☑️
* Метод `String Join(const std::vector<String>& strings)` - аналог джоина в питоне. ☑️

### Notes

1. Решение должно состоять из двух файлов: `string.hpp` с объявлением класса и его методов и `string.cpp` с определением всего необходимого. ☑️

2. В этой задаче запрещается использование стандартной библиотеки C++ кроме как `std::vector` только для `Split` и `Join`. Если нужны какие-либо служебные классы или функции, реализуйте их самостоятельно. ☑️

3. Проверка устроена таким образом, что требует от вас жесткого следования принятым (выше)
   сигнатурам и именованиям сущностей (то есть никакие `MyString`, `__string_`, `push_back`, `superSolver3000` не пройдут).
   Если вы реализовали требуемый функционал не полностью или интерфейс отличается от заявленного,
   в ответ вы получите ошибку компиляции. ☑️

4. В тесты включены проверки функциональности (методы работают так как требует условие),
   проверка эффективности реализации (что значит эффективно описано выше),
   проверка корректности работы с памятью (утечки памяти, обращения к памяти
   не принадлежащей процессу будут приводить к провалу) ☑️


<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="to_do"></a>
## 📌 To do 

- README ✅
- Task 👌
- Tests ✅
- Code style and formatting ✅
- Backward compatibility with C strings 💤 

**Note: ✅ - perfect, 👌 - done, 🔄 - in progress, 💤 - waiting for** 

<p align="right"><a href="#string">Back to top ⬆️</a></p>


<a id="contact"></a>
## 📫 Contact  

Vladislav Pakhomov - [@VlPakhomov](https://t.me/VlPakhomov) - [vladislavpakhomov03@gmail.com](mailto:vladislavpakhomov03@gmail.com)

Project Link: https://github.com/VlPakhomov/mipt-cpp/string

<p align="right"><a href="#string">Back to top ⬆️</a></p>

