#include "Dialog.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    Dialog dialog;
    dialog.run();
    return 0;
}