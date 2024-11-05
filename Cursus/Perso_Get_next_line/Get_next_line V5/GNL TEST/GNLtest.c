#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 5

char *add_back_buffer(char *line, char *buff, int buff_len)
{
    char *temp;
    int total_len;
    int i = 0;
    int j = 0;

    total_len = buff_len + (line ? strlen(line) : 0);
    temp = malloc(sizeof(char) * (total_len + 1));
    if (!temp)
        return (NULL);

    // Copie de la ligne existante dans temp
    if (line != NULL)
    {
        while (line[i] != '\0')
        {
            temp[i] = line[i];
            i++;
        }
        free(line); // Libérer la mémoire de l'ancienne ligne
    }

    // Copie du buffer dans temp
    while (j < buff_len)
    {
        temp[i] = buff[j];
        i++;
        j++;
    }

    temp[i] = '\0'; // Ajout du caractère nul à la fin de la chaîne
    return (temp);
}

char *get_next_line(int fd)
{
    int i;
    int byte_read;
    char *combined_line;
    static char buff[BUFFER_SIZE];
    static int buff_index = 0;
    static int buff_size = 0;

    combined_line = NULL;

    while (1)
    {
        // Si le buffer est vide, lire une nouvelle portion du fichier
        if (buff_index >= buff_size)
        {
            byte_read = read(fd, buff, BUFFER_SIZE);
            if (byte_read <= 0)
                break;
            buff_size = byte_read;
            buff_index = 0;
        }

        // Trouver la position de la nouvelle ligne
        i = buff_index;
        while (i < buff_size && buff[i] != '\n')
            i++;

        // Ajouter le contenu du buffer jusqu'à la nouvelle ligne à la ligne combinée
        combined_line = add_back_buffer(combined_line, buff + buff_index, i - buff_index);

        // Si une nouvelle ligne est trouvée, mettre à jour l'index du buffer et retourner la ligne
        if (i < buff_size && buff[i] == '\n')
        {
            buff_index = i + 1;
            break;
        }

        // Si aucune nouvelle ligne n'est trouvée, lire plus de données
        buff_index = buff_size;
    }

    return combined_line;
}

int main(void)
{
    int fd1;
    char *line;

    fd1 = open("test.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("open");
        return (1);
    }

    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd1);
    return (0);
}