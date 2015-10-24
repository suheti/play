// CS1010 AY2015/6 Semester 1
// PE1 Ex2: amicable.c
// Name: Zhang Ying
// Matriculation number: A0142939W
// plab-id: plab0183
// Discussion group: T32
// Description: This program checks the number of full amicable pairs and number of half amicable
// pairs of number in the given range

#include <stdio.h>

void countPairs(int lower, int upper, int results[]);
int sumFactors(int number);

// Do NOT change the main function at all!
int main(void){
	int lower, upper, results[2] = {0};

	printf("Enter range: ");
	scanf("%d %d", &lower, &upper);

	countPairs(lower, upper, results);

	printf("Number of full pairs: %d\n", results[0]);
	printf("Number of half pairs: %d\n", results[1]);

	return 0;
}

void countPairs(int lower, int upper, int results[]){
	// Remember to assign the calculated number of full pairs to results[0],
	// and the calculated number of half pairs to results[1]

	int i, j;

	//first loop checks for full pairs

	for (i=lower;i<upper;i++) {
		if (sumFactors(i)>=lower && sumFactors(i) <=upper) {
			for (j=lower;j<=upper;j++) {
				if (sumFactors(i) == j && sumFactors(j) == i && j>i) {
					results[0]++;
				}
			}
		}
	}

	//second loop checks for half pairs, where the other half pair is less
	//than lower bound

	for (i=0;i<lower;i++) {
		if(sumFactors(i) >= lower) {
			for (j=lower;j<=upper;j++) {
				if (sumFactors(i) == j && sumFactors(j) == i) {
					results[1]++;
				}
			}
		}
	}
	//third loop checks for half pairs where the other half pair is more
	//than upper bound (I CANNOT)

	for (i=lower;i<=upper;i++) {
		if(sumFactors(i) > upper){
			for(j=upper;j<sumFactors(i);j++) {
				if(sumFactors(i) == j) {
					results[1]++;
				}
			}
		}
	}



}
// Function computes the sum of proper factors in a given number, which do not include itself.
// precond: number > 0
int sumFactors(int number){
	int i, sum=0;
	for (i=1;i<number;i++) {
		if (number%i==0) {
			sum += i;
		}
	}

	return sum; // stub
}

