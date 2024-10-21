int chartostring(char a)
{
    if (a == '0')
        return 0;
    if (a == '1')
        return 1;
    if (a == '2')
        return 2;
    if (a == '3')
        return 3;
    if (a == '4')
        return 4;
    if (a == '5')
        return 5;
    if (a == '6')
        return 6;
    if (a == '7')
        return 7;
    if (a == '8')
        return 8;
    if (a == '9')
        return 9;
    return -1;
}
int baseballScore(string ops)
{
    /*TODO*/
    int stackk[int(ops.length())];
    for (int i = 0; i < int(ops.length()); i++)
        stackk[i] = 0;
    int curr = 0;
    for (int i = 0; i < int(ops.length()); i++)
    {
        if (isdigit(ops[i]))
        {
            stackk[curr] = chartostring(ops[i]);
            curr++;
        }
        else if (ops[i] == 'C')
        {
            stackk[curr] = 0;
            curr--;
        }
        else if (ops[i] == 'D')
        {
            stackk[curr] = stackk[curr - 1] * 2;
            curr++;
        }
        else if (ops[i] == '+')
        {
            stackk[curr] = stackk[curr - 1] + stackk[curr - 2];
            curr++;
        }
    }
    int total = 0;
    for (int i = 0; i < int(ops.length()); i++)
        total += stackk[i];
    return total;
}