/* **************************************************************************

    * File Name : Primary_Arithmetic.cpp

    * Creation Date : 2018-08-29 09:30:54

    * Last Modified : 2018-08-29 11:04:10

    * Created By : Samuel Chi <Yu-Ning Chi>

************************************************************************** */
#include <iostream>
using namespace std;

int main()
{
    long long inputNum_1, inputNum_2; //輸入的兩數
    int count; //計算進位次數
    int index = 0; //暫存陣列的位置，並初始化
    int carry; //查看是否有進位
    int countTmpAry[100000]; //暫存進位次數的陣列

    for(int k = 0; k < 100000; k++)
        countTmpAry[k] = -1; //初始化陣列
    while(cin >> inputNum_1 >> inputNum_2)
    {
        count = 0; //初始化次數
        carry = 0; //初始化進位
        if(inputNum_1 == 0 && inputNum_2 == 0)
            break; //若兩數皆為0則結束輸入
        while(1)
        {
            if(inputNum_1 == 0 && inputNum_2 == 0)
        		break; //當兩數都處理完畢則結束
            else if((inputNum_1 % 10 + inputNum_2 % 10 + carry) >= 10)
            {
                count++; //次數加1
            	carry = 1; //進位
            }
            else
				carry = 0; //無進位
            inputNum_1 /= 10; //刪除最後一位數
            inputNum_2 /= 10; //刪除最後一位數
        }
        countTmpAry[index++] = count; //將次數放入暫存陣列
    }
    for(int j = 0; countTmpAry[j] != -1; j++)
    {
        if(countTmpAry[j] == 0) //若次數為0
            cout << "No carry operation.\n";
        else if(countTmpAry[j] == 1) //若次數為1
            cout << "1 carry operation.\n";
        else //若次數非0非1
            cout << countTmpAry[j] << " carry operations.\n";
    }
    return 0;
}
