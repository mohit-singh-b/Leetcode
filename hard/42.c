int trap(int* height, int heightSize) {
    int max=0, max2=max,m, i , j , cs=0 ,tarea,barea,rarea=0; 

    for ( i = 1 ; i < heightSize ; i++)
    {   

        if(height[i] >= height[max]){
            max2 = max;
            max = i;
            tarea = (max-max2-1)*height[max2];
            barea = (cs );
            rarea += tarea - barea;
            cs = 0;
        }
        else 
            cs+=height[i];
    }
    printf("Done\n");
   m = max;
   max = heightSize-1;
   max2 = max;
   cs = 0;
   for ( i=heightSize-2 ; i >=m ; i--)
   {
        
        if(height[i] >= height[max]){
            max2 = max;
            max = i;
            tarea = (max2-max-1)*height[max2];
            barea = (cs );
            rarea += tarea - barea;
            cs = 0;
        }
        else 
            cs+=height[i];
   }
    return rarea;
}