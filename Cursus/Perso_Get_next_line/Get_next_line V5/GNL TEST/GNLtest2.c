#include "get_next_line.h"

char *ft_strdup(const char *s)
{
    char *dup;
    int len;
    
    len = ft_strlen(s);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    while (*s)
        *dup++ = *s++;
    *dup = '\0';
    return (dup - len);
}

void ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = '\0';
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1];
    char *line;
    char *temp;
    int byte_read;

    // Vérifications de base
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    line = NULL;
    
    // Si le buffer static contient des données
    if (buff[0])
    {
        line = ft_strdup(buff); // Il faudra créer cette fonction
        ft_bzero(buff, BUFFER_SIZE + 1); // Et celle-ci aussi
    }
    
    // Lecture jusqu'à trouver \n ou EOF
    while (1)
    {
        // Si on a déjà un \n, on peut sortir
        if (line && ft_strchr(line, '\n'))
            break;
            
        // Lecture du fichier
        byte_read = read(fd, buff, BUFFER_SIZE);
        if (byte_read <= 0)
            break;
            
        // Terminer le buffer
        buff[byte_read] = '\0';
        
        // Joindre au résultat
        temp = line;
        line = ft_strjoin(line, buff);
        free(temp);
    }
    
    // Gestion des cas d'erreur et fin de fichier
    if (!line || line[0] == '\0')
    {
        free(line);
        return (NULL);
    }
    
    return (line);
}