#include <iostream>
#include <cstdlib>

using namespace std;

int mutex = 1;
int full = 0;
int emptySlots = 10, x = 0;

//to produce an item and add it to the buffer
void producer() {
    --mutex;
    ++full;   
    --emptySlots;
    x++;
    cout << "\nProducer produces item " << x << endl;
    ++mutex;
}

//to consume an item and remove it from the buffer
void consumer() {
    --mutex;
    --full;
    ++emptySlots;
    cout << "\nConsumer consumes item " << x << endl;
    x--;
    ++mutex;
}

int main() {
    int n, i;
    while (true) {
        cout << "\n1. Press 1 for Producer";
        cout << "\n2. Press 2 for Consumer";
        cout << "\n3. Press 3 for Exit";
        cout << "\nEnter your choice: ";
        cin >> n;

        switch (n) {
        case 1:
            if (mutex == 1 && emptySlots != 0) {
                producer();
            } else {
                cout << "Buffer is full" << endl;
            }
            break;

        case 2:
            if (mutex == 1 && full != 0) {
                consumer();
            } else {
                cout << "Buffer is emptySlots!" << endl;
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}
