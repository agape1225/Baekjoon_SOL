#include <cstdio>
#define SIZE 500000

int card[SIZE];
int input[SIZE];
int buff[SIZE];


int lower_bound(int data, int left, int right) {
	
	if (left <= right) {
		int mid = (left + right) / 2;
		if (mid - 1 >= 0) {
			if (card[mid] >= data && card[mid - 1] < data)
				return mid;
			else {
				if (card[mid] < data)
					return lower_bound(data, mid + 1, right);
				else
					return lower_bound(data, left, mid - 1);
			}
		}
		else
			return 0;
	}
	else 
		return left;
}

int upper_bound(int data, int left, int right) {

	if (left <= right) {
		int mid = (left + right) / 2;
		if (mid - 1 >= 0) {
			if (card[mid] > data && card[mid - 1] <= data)
				return mid;
			else {
				if (card[mid] <= data)
					return upper_bound(data, mid + 1, right);
				else
					return upper_bound(data, left, mid - 1);
			}
		}
		else
			return 0;
	}
	else
		return left;
}

void sort(int left, int right, int mid) {

	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (card[i] <= card[j])
			buff[k++] = card[i++];
		else
			buff[k++] = card[j++];
	}

	if (i <= mid) {
		while (i <= mid)
			buff[k++] = card[i++];
	}
	else if(j <= right){
		while (j <= right)
			buff[k++] = card[j++];
	}

	for (int l = left; l <= right; l++) {
		card[l] = buff[l];
	}

}

void marge(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		marge(left, mid);
		marge(mid + 1, right);
		sort(left, right, mid);

	}
}

int main(void) {

	int card_size;

	scanf_s("%d", &card_size);

	for (int i = 0; i < card_size; i++) {
		scanf_s("%d", &card[i]);
	}

	int input_size;
	scanf_s("%d", &input_size);

	for (int i = 0; i < input_size; i++) {
		scanf_s("%d", &input[i]);
	}


	marge(0, card_size - 1);

	//for (int i = 0; i < card_size; i++) {
	//	printf("%d ", card[i]);
	//}

	//printf("\n");

	
	//printf("\n");

	for (int i = 0; i < input_size; i++) {
		int upper = upper_bound(input[i], 0, card_size - 1);
		int lower = lower_bound(input[i], 0, card_size - 1);

		//printf("\n%3d: (%3d,%3d)", input[i], upper, lower);
		if (upper == 0 && lower == 0) {
			if (input[i] == card[0])
				upper++;
		}
		printf("%d ", upper - lower);
	}

	//printf("\n%d", index);
	//printf("\n%d", upper);
	//printf("\n%d", lower);

	printf("\n");

	return 0;


}