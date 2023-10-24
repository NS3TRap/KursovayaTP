#include <userinterfacescreen.h>

int main()
{
    UserInterfaceScreen* uis = new UserInterfaceScreen();
    uis->interact();
    delete uis;
    return 0;
}
