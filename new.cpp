#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandom(int min, int max) {
return min + (rand() % (max - min + 1));
}

int main() {
srand(time(0));

const int NUM_HORSES = 4;
const int POWER_INCREMENT = 5;
const int POWER_THRESHOLD = 10;

char horses[NUM_HORSES] = {'X', 'M', 'T', 'D'};
int power[NUM_HORSES] = {5, 5, 5, 5};
int steps[NUM_HORSES] = {0, 0, 0, 0};

bool raceOver = false;

for (int i = 0; i < NUM_HORSES; ++i) {
cout << string(steps[i], '-') << horses[i] << string(20 - steps[i], '.') << "|" <<
endl;
}

cout << "Which horse do you think will win? (X, M, T, D): ";
char guess;
cin >> guess;

while (!raceOver) {
for (int i = 0; i < NUM_HORSES; ++i) {
power[i] += getRandom(1, 5);

if (power[i] >= POWER_THRESHOLD * (steps[i] + 1)) {
steps[i]++;

}

if (steps[i] >= 20) {
raceOver = true;
}
}

system("cls");

for (int i = 0; i < NUM_HORSES; ++i) {
cout << string(steps[i], '-') << horses[i] << string(20 - steps[i], '.') << "|" <<
endl;
}

if (raceOver) {
int winnerIndex = 0;
for (int i = 1; i < NUM_HORSES; ++i) {
if (steps[i] > steps[winnerIndex]) {
winnerIndex = i;
}
}

if (guess == horses[winnerIndex]) {
cout << "Congratulations! You guessed the winner!" << endl;
} else {

cout << "Sorry, the winner was horse " << horses[winnerIndex] << endl;
}
}
}

return 0;
}