## Модуль quadratic_equation

Реализует функции:
* solve_equation - вычисление корней квадратного уравнения ax^2+bx+c=0

Сборка:
* make, make all: библиотека quadratic_equation.a
* make gcov_report: подготовка и запуск тестов, формирование отчёта о покрытии
* make test: подготовка и запуск тестов
* make valgrind_check: подготовка тестов и их запуск при помощи valgrind (отчёт о проверке доступен в src/unit_tests/build/RESULT_VALGRIND.txt)

Входные параметры:
* Вещественные числа типа double (исключая NAN, INF)
* Указатели на корни уравнения x1, x2

Результат:
| Сценарий                       | Результат            | Код выполнения функции |
| :----------------------------- | :------------------- | ---------------------: |
| a = 0                          | Один корень, x1 = x2 |                      1 |
| D = 0                          | Один корень, x1 = x2 |                      1 |
| D < 0                          | Нет корней           |                      2 |
| D > 0                          | Два корня x1, x2     |                      0 |
| a,b,c null/inf или x1, x2 NULL | Ошибка вычисления    |                     -1 |

