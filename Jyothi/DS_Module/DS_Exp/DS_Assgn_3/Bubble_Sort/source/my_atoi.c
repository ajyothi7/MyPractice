// function to convert ascii to integer

unsigned int my_atoi(char str[])
{
    unsigned int index;
    unsigned int num;

    num = 0;

    for(index = 0; str[index] >= '0' && str[index] <= '9'; ++index)
        num = 10 * num + (str[index]-'0');

	if((str[index] < '0' || str[index] > '9') && (str[index] != '\0')) //if you encounter any char other than 0 - 9 
		return -1;

    return num;
}

