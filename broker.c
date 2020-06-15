#include <stdio.h>

int main(void){
  float og_commission, rival_commission, value, share;

  printf("Enter number of shares: ");
  scanf("%f", &value);

  printf("Price per share: ");
  scanf("%f", &share);

  if (value < 2500.0f) {
    og_commission = 30.00f + .0017f * value;    
  } else if (value < 6250.0f){
    og_commission = 56.0f + .0066f * value;
  } else if (value < 20000.0f) {
    og_commission = 76.0f + .0034f * value;
  } else if (value < 50000.0f) {
    og_commission = 100.0f + .0022f * value;
  } else if (value < 500000.0f) {
    og_commission = 155.0f + .0011f * value;
  } else {
    og_commission = 255.0f + .0009f * value;
  }
  
  if (og_commission < 39.0f)
    og_commission = 39.0f;


  if (value < 2000) {
    rival_commission = 33.0f + .0003f * share;
  } else {
    rival_commission = 33.0f + .0002f * share;    
  }

  printf("\nOriginal Commission: $%.2f\n", og_commission);
  printf("Rival Commission: $%.2f\n", rival_commission);
  return 0;
}
