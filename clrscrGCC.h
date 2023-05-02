#ifdef _WIN32
#define clrstr "clr"
#endif
#define clrstr "clear"

void clrscr()
{
    system(clrstr);
}
