string DecimalToBinary(int num)
{
    string str;
    while (num) {
        if (num & 1) // 1
            str += '1';
        else // 0
            str += '0';
        num >>= 1; // Right Shift by 1
    }
    reverse(str.begin(),str.end());
    return str;
}
