# matrix

<br/>

<a id="description"></a>
## 🏷️ Description

*If people knew how hard I worked to get my mastery, it wouldn't seem so wonderful after all 💫*

This project is dedicated to the implementation of the matrix class. It's task for C++ course by MIPT. We can see task-requirements is contains in [Task](#task). 
You should use [Table of Contents](#️table_of_contents) to navigate here. The main steps in development we can find in [To do](#to_do). If you want to contact me, look in [Contact](#contact).<br/>

Probably, I will add other useful and more complex features to this implementation in the future ⌛ 

<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="solutions_and_techniques"></a>
## 🎯 Solutions and Techniques

- Implementation static polymorphism using C++ templates.
- Implementation information hiding principle using access specifiers.
- Implementation matrix taking into account mathematical rule (Trace for non square matrix will cause CE, 
        same for arithmetic operators of matrices with ivalid shape) using partial template specialization and inheritance.
- Idiomatic implementation class constructors (copy-and-swap idiom, member initializer list, only non-trivial actions in bogy).
- Use the #pragma preprocessor directive for header guards.
- Apply using-declaration for introduces a constructors of a base class into the derived class.
- Well-designed class, id est there are no friend, mutable and etc bad keyword.
- Use curiously recurring template pattern for using parent's operators overloading in child during the inheritance.  
- Use sanitizers and valgrind for find memory bugs and undefined behaviour. 
- Following the idiomatic C++ style (not use C functions such as memset, use std toolkit).
- Use clang-tidy linter for general static code analysis.
- Use clang-format for reformat code following the Google C++ Code Style.
- Use cpplint linter for static code analysis of conforms to Google C++ Code Style. 
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

## Matrix

В рамках данной задачи вам предстоит реализовать класс `Matrix<size_t N, size_t M, typename T = int64_t>` - класс матрицы с
заданными размерами и типом элементов на этапе компиляции.


### Details

Операции, которые должны поддерживаться над матрицей:
* Конструктор по умолчанию заполняет матрицу `T()`. ☑️
* Конструктор от `std::vector<std::vector<T>>`, заполняющий матрицу элементами вектора. Гарантируется, что размеры вектора будут совпадать с размерами в шаблонах. ☑️
Гарантируется, что размеры вектора будут совпадать с размерами в шаблонах
* Конструктор от `T elem`. Заполняет всю матрицу `elem`. ☑️
* Сложение, вычитание, операторы +=, -=. Сложение и вычитание матриц несоответствующих размеров не должно компилироваться. ☑️
Гарантируется, что типы в матрицах в тестах будут поддерживать соответствующие операции.
* Умножение на элемент типа T (гарантируется, что оператор * определен для T). ☑️
* Умножение двух матриц. Попытка перемножить матрицы несоответствующих размеров должна приводить к ошибке компиляции. ☑️
* Метод `Transposed()`, возвращающий транспонированную матрицу. ☑️
* Метод `Trace()` - вычислить след матрицы. Вычисление следа от неквадратной матрицы не должно компилироваться. Подумайте, как это реализовать! ☑️
* Оператор `(i, j)`, возвращающий элемент матрицы в _i_-й строке и в _j_-м столбце. Необходимо уметь менять значение для неконстантных матриц. ☑️
* Оператор проверки на равенство. ☑️

Гарантируется, что в ходе вычисления все элементы лежат в диапазоне типа `T`.

### Notes

1. Решение должно состоять из двух файлов: `matrix.hpp` с объявлением класса и его методов и `matrix.cpp` с определением всего необходимого. ☑️

2. В данной задаче запрещено использовать слова static_assert и constexpr, если вдруг вы такое знаете. ☑️

3. В данной задаче разрешено использовать `std::vector<T>`. ☑️

4. Проверка устроена таким образом, что требует от вас жесткого следования принятым (выше)
   сигнатурам и именованиям сущностей (то есть никакие `MyMatrix`, `__matrix_`,  `superSolver3000` не пройдут).
   Если вы реализовали требуемый функционал не полностью или интерфейс отличается от заявленного,
   в ответ вы получите ошибку компиляции. ☑️

5. В тесты включены проверки функциональности (методы работают так как требует условие),
   проверка эффективности реализации (что значит эффективно описано выше),
   проверка корректности работы с памятью (утечки памяти, обращения к памяти
   не принадлежащей процессу будут приводить к провалу) ☑️


<p align="right"><a href="#string">Back to top ⬆️</a></p>

<a id="to_do"></a>
## 📌 To do 

- README 👌
- Task ✅
- Tests ✅
- Code style and formatting 🔄
- Curiously recurring template pattern ✅

**Note: ✅ - perfect, 👌 - done, 🔄 - in progress, 💤 - waiting for** 

<p align="right"><a href="#string">Back to top ⬆️</a></p>


<a id="contact"></a>
## 📫 Contact  

Vladislav Pakhomov - [@VlPakhomov](https://t.me/VlPakhomov) - [vladislavpakhomov03@gmail.com](mailto:vladislavpakhomov03@gmail.com)

Project Link: https://github.com/VlPakhomov/mipt-cpp

<p align="right"><a href="#string">Back to top ⬆️</a></p>

