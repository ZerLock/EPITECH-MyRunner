/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** j'ai passé 7h de ma journée dessus
*/

int my_getnbr(char const *str)
{
    long int number;
    int i;
    int sign;

    number = 1000000;
    number -= 1000000;
    i = 0;
    sign = 1;
    while (str[i] == 45 || str[i] == 43) {
        if (str[i] == 45)
            sign *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        number = number * 10 + (str[i] - 48);
        i++;
        if ((number > 2147483647 || number < -2147483648))
            return (0);
    }
    return (number * sign);
}
