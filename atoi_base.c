
int to_lower(char c)
{
    if (c >= 'A' && 'F' >= c)
        c += 32;
    return c; 
}

int get_digit(char c, int str_base)
{
    int max_digit;
    if (str_base <= 10)
        max_digit = str_base + '0';
    else
        max_digit = str_base - 10 + 'a';

    if (c >= '0' && '9' >= c && c <= max_digit)
        return (c = c - '0');
    else if (c >= 'a' && 'f' >= c && c <= max_digit)
        return (c = 10 + c - 'a');
    else
        return (-1);
}


int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
		sign = -1;

	if (*str == '-' || *str == '+') {
		str++;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base + (digit * sign);
		str++;
	}
	return (result);
}

int main(void)
{
    char *c = "1234";
    printf("%d", ft_atoi_base(c, 16));
}