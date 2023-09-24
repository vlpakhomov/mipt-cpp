# geometry

<br/>

<a id="description"></a>
## 🏷️ Description

*If people knew how hard I worked to get my mastery, it wouldn't seem so wonderful after all 💫*

This project is dedicated to the implementation set of geometric classes. It's task for C++ course by MIPT. We can see task-requirements is contains in [Task](#task). 
You should use [Table of Contents](#️table_of_contents) to navigate here. The main steps in development we can find in [To do](#to_do). If you want to contact me, look in [Contact](#contact).<br/>

Probably, I will add other useful and more complex features to this implementation in the future ⌛ 

<p align="right"><a href="#geometry">Back to top ⬆️</a></p>

<a id="solutions_and_techniques"></a>
## 🎯 Solutions and Techniques

- Implementation static polymorphism using C++ templates.
- Implementation information hiding principle using access specifiers.
- Implementation matrix taking into account mathematical rule (Trace for non square matrix will cause CE, 
        same for arithmetic operators of matrices with ivalid shape) using partial template specialization and inheritance).
- Idiomatic implementation class constructors (copy-and-swap idiom, member initializer list, only non-trivial actions in bogy).
- Apply using-declaration for introduces a constructors of a base class into the derived class.
- Well-designed class, id est there are no friend, mutable and etc bad keyword.
- Use curiously recurring template pattern for using parent's operators overloading in child during the inheritance.   
- Following the idiomatic C++ style (not use C functions such as memset, use std toolkit).
- Use clang-tidy linter for general static code analysis.
- Use clang-format for reformat code following the Google C++ Code Style.
- Use cpplint linter for static code analysis of conforms to Google C++ Code Style. 
- Everything is covered by unit tests.
- Use basic rules and idioms for operator overloading.   
- Writing quality code using practicing “Make It Work, Make It Right, Make It Fast”.

<p align="right"><a href="#geometry">Back to top ⬆️</a></p>

<a id="table_of_contents"></a>
## 🗂️ Table of Contents 
- [Description](#️-description)
- [Solutions and Techniques](#-solutions-and-techniques)
- [Table of Contents](#️-table-of-contents)
- [Task](#-task)
- [To do](#-to-do)
- [Contact](#-contact)


<p align="right"><a href="#geometry">Back to top ⬆️</a></p>

<a id="task"></a>
## 📄 Task 

## Geometry

В данной задаче вам необходимо реализовать набор классов для решения геометрических задач на плоскости. 
Все координаты предполагаются целочисленными.

### Details

1. Класс Vector для вектора на плоскости, необходимо реализовать следующие методы и перегрузить соответствующие операторы:
* Конструктор по умолчанию (создает нулевой вектор)
* Конструктор от двух целочисленных переменных (создает вектор с соответствующими координатами)
* Оператор * для скалярного произведения
* Оператор ^ для векторного произведения
* Операторы сложения/разности с другим вектором, соответственно реализовать операторы += и -=
* Оператор умножения на число (сделать так, чтобы были допустимы как умножение вектора на число, так и числа на вектор), реализовать оператор *=
* Унарный оператор минус для получения вектора в противоположном направлении
* Методы GetX() и GetY() для получения соответствующих координат

2. Создать набор классов - фигур, которые наследуются от абстрактного класса IShape для работы с двумерными примитивами:
* Point или точка (создается из двух координат типа int64_t)
* Segment или отрезок (создается из двух Point)
* Line или прямая (создается из двух Point)
* Ray или луч (создается из двух Point)
* Circle или окружность (создается из Point и радиуса типа size_t)

3. В каждом классе должны быть геттеры:
* Point: GetX, GetY (координаты)
* Segment: GetA, GetB (начало, конец отрезка)
* Line: GetA, GetB, GetC где a b c это коэффициенты уравнения прямой ax + by + c с точностью до множителя (то есть 10x + 20y + 30 это тоже самое что 5x + 10y + 15)
* Ray: GetA - точка начала и GetVector - направляющий вектор
* Circle: GetCentre и GetRadius

4. В базовом классе предусмотреть следующие методы: 
* Point: GetX, GetY (координаты)
* Segment: GetA, GetB (начало, конец отрезка)
* Line: GetA, GetB, GetC где a b c это коэффициенты уравнения прямой ax + by + c с точностью до множителя (то есть 10x + 20y + 30 это тоже самое что 5x + 10y + 15)
* Ray: GetA - точка начала и GetVector - направляющий вектор
* Circle: GetCentre и GetRadius

В производных классах необходимо реализовать эти методы.

### Notes

1. Решение должно состоять из двух файлов для: `geometry.hpp` с объявлением всех классов и их методов и `geometry.cpp` с определением всего необходимого. 

2. В данной задаче нужно определить все классы, методы, функции так, 
    чтобы предложенный тестирующий код выводил ожидаемый результат в 
    соответствии с общепринятой семантикой (в частности, обратите внимание, 
    что тестирующий код требует перегрузки операции разности двух точек).

3. Проверка устроена таким образом, что требует от вас жесткого следования принятым (выше)
   сигнатурам и именованиям сущностей (то есть никакие `MyPoint`, `__point_`,  `superSolver3000` не пройдут).
   Если вы реализовали требуемый функционал не полностью или интерфейс отличается от заявленного,
   в ответ вы получите ошибку компиляции. 

4. В тесты включены проверки функциональности (методы работают так как требует условие),
   проверка эффективности реализации (что значит эффективно описано выше),
   проверка корректности работы с памятью (утечки памяти, обращения к памяти
   не принадлежащей процессу будут приводить к провалу) 


<p align="right"><a href="#geometry">Back to top ⬆️</a></p>

<a id="to_do"></a>
## 📌 To do 

- README 🔄
- Task 🔄
- Tests 💤
- Code style and formatting 💤
- Curiously recurring template pattern 💤

**Note: ✅ - perfect, 👌 - done, 🔄 - in progress, 💤 - waiting for** 

<p align="right"><a href="#geometry">Back to top ⬆️</a></p>


<a id="contact"></a>
## 📫 Contact  

Vladislav Pakhomov - [@VlPakhomov](https://t.me/VlPakhomov) - [vladislavpakhomov03@gmail.com](mailto:vladislavpakhomov03@gmail.com)

Project Link: https://github.com/VlPakhomov/mipt-cpp

<p align="right"><a href="#geometry">Back to top ⬆️</a></p>

