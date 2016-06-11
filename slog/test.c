#include "slog.h"

void fun()
{
    slog(debug, "enter");
    slog(debug, "leave");
}

int main()
{
    setLogLevel(debug);

    slog_error("enter");
    fun();

    int i = 10000;

    slog(fatal, "ret = %d, &i = 0x%p", 100, &i);

    slog_error("leave");
}
