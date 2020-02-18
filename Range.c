#include <stdio.h>

double range(int data[], int length)
{
int i;
int minimum, maximum, difference;
minimum = data[0];
maximum = data[0];


for (i=0; i < length; i++){
data[i] = maximum;
}
difference = maximum - data[0];




difference = maximum - minimum;
printf("%d", &difference);



}

int main(){
int data[]={36, 12, 25, 19, 46, 32, 22};

return range(data, 6);

}




