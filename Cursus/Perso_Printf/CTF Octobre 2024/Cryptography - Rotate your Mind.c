/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cryptography - Rotate your Mind.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:42:50 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/29 23:28:41 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

int main(void)
{
    char s[] = "synt75{e3g46_4f_i6el_f4zcyr}";
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' - 13 + 26) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' - 13 + 26) % 26 + 'A';
        else if (s[i] >= '0' && s[i] <= '9')
            s[i] = (s[i] - '0' - 3 + 10) % 10 + '0';
        write(1, &s[i], 1);
        i++;
    }
    return 0;
}


