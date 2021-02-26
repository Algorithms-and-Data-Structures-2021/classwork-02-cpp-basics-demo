#include <iostream>  // cout

using namespace std;

void pass_by_const_value(int const const_arg) {
    // невозможно изменить значение 'const_arg'
    // const_arg = 0;
}

void pass_by_pointer_to_const(int const *ptr_to_const) {
    // невозможно изменить значение, на которое ссылается указатель
    // *ptr_to_const = 0;

    // но можем изменить то, куда ссылается указатель (т.е. значение указателя)
    ptr_to_const = nullptr;
}

void pass_by_reference_to_const(int const &ref_to_const) {
    // невозможно изменить значение
    // ref_to_const = 0;
}

int main() {

    {  // ключевое слово const - константа времени выполнения (runtime)

        // переменная с неизменяемым значением (константная переменная)
        int const const_var = 1;

        // изменение значения константной переменной (не сработает, ошибка компиляции)
        // const_var = 2;

        // указатель на константную переменную (читаем тип справа налево)
        int const *ptr_to_const = &const_var;

        // попытка сохранения адреса константной переменной
        // в указатель на неконстантную переменную (не сработает, ошибка компиляции)
        // int* pointer = &const_var;

        // чтение значения по указателю на константную переменную
        int const_var_copy = *ptr_to_const;  // происходит копирование значения 'const_var' в 'const_var_copy'

        // изменение значения константной переменной через указатель (не сработает, ошибка компиляции)
        // *ptr_to_const = 1;

        // ссылка на константную переменную (читаем тип справа налево)
        int const &ref_to_const = const_var;

        // неконстантная ссылка не может ссылаться на константную переменную (ошибка компиляции)
        // int &ref_to_const = const_var

        // чтение значения по ссылке на константную переменную
        int ref_const_copy = ref_to_const;  // происходит копирование значения 'const_var' в

        // изменение значения переменной через ссылку (не сработает, ошибка компиляции)
        // ref_to_const = 2;

        int var = 0;

        // взятие указателя и ссылки на неконстантную переменную
        // case: передача аргумента в функцию с запретом на изменение его значения
        int const *ptr_to_var = &var;
        int const &ref_to_var = var;

        // создание ссылки на константное значение (литерал или выражение)
        // что здесь происходит?
        // 1. автоматически выделяется память под значение 3 (переменная типа int)
        // 2. создается ссылка на участок памяти с константным значением 3
        // 3. пока ссылка жива - жив и выделенный участок памяти под значение 3
        int const &ref_to_value = 3;
        int const &ref_to_exp = 2 + const_var;

        // константный указатель (читаем тип справа налево)
        int *const const_ptr = &var;

        // изменение значения указателя (т.е. адреса на который он указывает)
        // ошибка компиляции
        // const_ptr = nullptr;

        // изменение значения переменной (т.е. запись данных по участку памяти)
        *const_ptr = 3;
    }

    {  // передача аргументов по константному значению, указателю и ссылке на константное значение

        int var = 0;
        int const const_var = 0;

        // передача по константному значению
        pass_by_const_value(var);
        pass_by_const_value(const_var);
        pass_by_const_value(25);

        // передача по указателю на константное значение
        pass_by_pointer_to_const(&var);
        pass_by_pointer_to_const(&const_var);

        // передача по ссылке на константное значение
        pass_by_reference_to_const(var);
        pass_by_reference_to_const(const_var);
        pass_by_reference_to_const(25);

    }

    return 0;
}
