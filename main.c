#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

// Функция для получения текущего размера стека
void get_stack_size() {
    struct rlimit rl;
    if (getrlimit(RLIMIT_STACK, &rl) == 0) {
        printf("Текущий размер стека: %ld байт\n", rl.rlim_cur);
    } else {
        perror("Ошибка при получении размера стека");
    }
}

// Функция для установки нового размера стека
void set_stack_size(rlim_t new_size) {
    struct rlimit rl;
    rl.rlim_cur = new_size;
    rl.rlim_max = new_size;
    if (setrlimit(RLIMIT_STACK, &rl) == 0) {
        printf("Новый размер стека установлен: %ld байт\n", new_size);
    } else {
        perror("Ошибка при установке размера стека");
    }
}

int main() {
    // Получаем текущий размер стека
    get_stack_size();

    // Устанавливаем новый размер стека (например, 8 МБ)
    set_stack_size(8 * 1024 * 1024);

    // Получаем обновленный размер стека
    get_stack_size();

    // Восстанавливаем исходный размер стека (например, 16 МБ)
    set_stack_size(4 * 1024 * 1024);

    // Получаем обновленный размер стека
    get_stack_size();

    return 0;
}
