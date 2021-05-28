#include "my_list.h"

int main()
{
    char *line;
    list_key_t *list = NULL;

    
    line = check_line_int();
    
    while ( line != NULL )
    {
        list = tri(line, list);
        line = check_line_int();
    }

    return 0;
}