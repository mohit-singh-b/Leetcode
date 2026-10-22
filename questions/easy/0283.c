void moveZeroes(int* nums, int numsSize) {

int length = 0 ,i = 0 , j = -1   ;

while ( i < numsSize)
{
    if ( *(nums + i ) == 0)
    {
        length++;
        if ( j == -1 )
        {
            j = i ;
        }
    }

    else 
    {
        if ( j != -1)
        {
            *(nums + j) = *(nums + i);
            j++;
        }
    }


    i++;


}    

for ( i = 0 ; i < length ; i++)
{ 
    *(nums + j + i ) = 0 ;
}
 

}

