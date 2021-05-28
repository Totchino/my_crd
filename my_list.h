#ifndef MY_LIST_H
#define MY_LIST_H
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_key_s {
    long long int key;
    long long int data_value;
    struct list_key_s *next;
} list_key_t;

#endif

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(const char *str)
{
int i;  
for (i=0 ; str[i] != '\0' ;++i ) 
{
my_putchar(str[i]);
}  
}


long long int my_pow(int mult)
{
   int i = 0;
   int result = 1;
   for (i=0; i < mult; ++i)
   { 
      result = result * 10;
   }
   return(result);
}

int compteur(const char *str)
{
    int i = 0;
    int j = 0;
    while ((str[i] <= '0') || (str[i] >= '9'))
    {     
       ++i;
    }
   
    while ((str[i] >= '0') && (str[i] <= '9'))
    {
       ++j;
       ++i;
    }       
    return(j);
}

long long int my_getnbr(const char *str)
{
    int i = 0;

    long long int unite;
    long long int nbr = 0;
    int signe = 1;
    int chiffre = compteur(str) - 1;
    while ((str[i] <= '0') || (str[i] >= '9'))
    {     
       ++i;
    }
   
    if (str[i-1] == '-')
    {
    signe = -1;
    }
   

    while ((str[i] >= '0') && (str[i] <= '9'))
    {
       unite = str[i] - 48;
       if (chiffre > 0)
       {
       nbr = nbr + unite * my_pow(chiffre);
       --chiffre;
       }
       else
       {
       nbr = nbr + unite;
       }
       ++i;
    }      
    return(nbr * signe); 
}


int nb_word(const char *str)
{
    int count_space = 0;
    int i;
 for ( i = 0; str[i] != '\0'; ++i )
 { 
     if ( str[i] == ' ' )
    {
        ++count_space;
    }
 }
 if ( i == 0 )
    {
        return(0);
    }
 return( count_space + 1);
}

int my_strlen(const char *str)
{
 int i;
 for ( i = 0; str[i] != '\0' || str[i] != ' '; ++i );
 return(i);
}

char **my_str_to_word_array(const char *str)
{
   int nb = nb_word(str);
   char **tab = malloc(sizeof(char*) * (nb + 1)); 
   int i = 0;
   int j = 0;

   
   while (i < nb_word(str))
    {
       int str_len = 0;
       
       while (str[j] != ' ' && str[j] != '\0') /* boucle qui compte le nb de caractères par mots */
       {
           ++j;
           ++str_len;
       }
    

       tab[i] = malloc(sizeof(char) * (str_len + 1));  /* allocation de la chaine de caractère */
    int k = 0;
       while (str[j - str_len] != ' ' && str[j - str_len] != '\0')
       {
           tab[i][k] = str[j - str_len];
           ++j;
           ++k;
       }
       tab[i][k + 1] = '\0';

       j = j - str_len + 1;
       ++i;
    }
   
   tab[i+1] = NULL;
   return(tab);
}

void my_putnbr(long long nb)
{
    if (nb < 0)
        {
            my_putchar('-');
            nb = nb * -1;
        }
    if (nb >= 10)
        {
            my_putnbr(nb / 10);
            my_putchar((nb % 10) + '0');
        }
    else
        {
            my_putchar(nb + '0');
        }
}    

list_key_t *my_delete_nodes(list_key_t**list, long long int check_key)
{
    list_key_t *var = *list;
    if (var == NULL)
    {
        my_putnbr(-1);
        my_putchar('\n');
        return var;
    }

    if (var->key == check_key)
    {
         my_putnbr(var->data_value);
         my_putchar('\n');
        *list = var->next;
        return var;
    }

    while (var->next != NULL)
    {
        if (var->next->key == check_key)
        {
            my_putnbr(var->next->data_value);
            var->next = var->next->next;
            return var;
        }
        
        var = var->next;

        if (var == NULL)
        {
            return var;
        }
    }
    my_putnbr(-1);
    my_putchar('\n');
    return var;
}



list_key_t *my_push_front_to_list(long long int check_key, long long int check_value, list_key_t *list)
{
list_key_t *tmp = malloc(sizeof(list_key_t));
tmp->key = check_key; 
tmp->data_value = check_value;
tmp->next = list;
// my_putnbr(check_key);
// my_putchar('\n');
return (tmp);
}

void print_list(list_key_t *list)
{
    while (list != NULL)
    {
    printf("key   : %lli\nvalue : %lli\n\n", list->key, list->data_value);
    list = list->next;
    }
}

int my_strcmp (const char* s1, const char* s2)
{
    while (*s1 != '\0' && (*s1 == *s2)) {s1++; s2++;}
    return (s1==s2) ? 0 : (*(unsigned char *)s1 - *(unsigned char *)s2);
}

list_key_t *insert_command(list_key_t *list, long long int check_key, long long int check_value)
{
        list_key_t *var = list;
        while (list != NULL)
        {
            if (check_key == list->key)
            {
                list->data_value = check_value;
                my_putnbr(list->key);
                my_putchar('\n');
                return list;
            }
            else
            {
                list = list->next;
            }
        }
        list = var;
        list = my_push_front_to_list(check_key, check_value, list);
        my_putnbr(check_key);
        my_putchar('\n');
        // print_list(list);
        return list;
    }
    


void look_up_command(list_key_t *list, long long int check_key)
{
        if ( list == NULL )
        {
        my_putnbr(-1);
        my_putchar('\n');
        return;
        }
        while ( list != NULL )
        {
            if ( check_key == list->key )
            {
            my_putnbr(list->data_value);   
            my_putchar('\n');
            return;
            }
            else
            {
            list = list->next;  
            }
        }
        my_putnbr(-1);
        my_putchar('\n');
        return;
    
}

list_key_t *removal_command(list_key_t *list, long long int check_key)
{
        my_delete_nodes(&list, check_key);
        return list;
}
    

char *my_readline(void)
{
  size_t n = 0;
  char *ret = NULL;
  ssize_t result = getline(&ret, &n, stdin);

  if (result <= 0) {
    free(ret);
    return NULL;
  }
  if (ret[result - 1] == '\n') {
    ret[result - 1] = '\0';
  }
  return ret;
}


list_key_t *tri(char *line, list_key_t *list)
{   
    char **tab = my_str_to_word_array(line);
    char *premier_element = tab[0];
    char *deuxieme_element_d = tab[1];
    char *deuxieme_element_int = tab[1];
    
    long long int check_key = my_getnbr(premier_element); 
    
    if ( nb_word(line) == 1 )
        {
        look_up_command(list, check_key);
        return list;  
        }

    if ( nb_word(line) == 2 && my_strcmp(deuxieme_element_d,"D") == 0)
        {
        list = removal_command(list, check_key);
        // printf("coucou\n");
        return list;
        }

    if (deuxieme_element_int == NULL || (my_strcmp(deuxieme_element_int, "D") == 0))  
    {
        // printf("coucou\n");
        return list;
    }  

    long long int check_value = my_getnbr(deuxieme_element_int);
    if ((nb_word(line) == 2))
    {
        list = insert_command(list, check_key, check_value);
        return list;
    }    
    return list;
}    

char *check_line_int() 
{
    int correct;
    int indice;
    char *test;
 do
   { 
       correct = 1;
       indice = 0;
       test = my_readline();
       
       int nb = nb_word(test);
       while(test[indice] != '\0')
       {
          if ((test[indice] < '0' || test[indice] > '9') && nb < 3 && test[indice] != ' ' && test[indice] != 'D')
               correct = 0;     
          indice++;
       }
       if (correct == 0) 
           my_putstr("erreur, recommencez\n");
    }while(correct == 0);
    return test;
}

