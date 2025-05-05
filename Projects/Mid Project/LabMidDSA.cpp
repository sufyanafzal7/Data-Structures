#include <iostream>
#include <string>

using namespace std;

struct TrainEvent {
    string trainID;
    int timeStamp;
    string status; 
};

class TrainSchedule {


private:
    TrainEvent events[100]; 
    int size; 

public:
    TrainSchedule() {
        size = 0;
    }





    void insert(string trainID, int timeStamp, string status) {
        TrainEvent event;
        event.trainID = trainID;
        event.timeStamp = timeStamp;
        event.status = status;

        events[size] = event;
        size++;

        int i = size - 1;
        while (i > 0 && events[i].timeStamp < events[i - 1].timeStamp) {
            TrainEvent temp = events[i];
            events[i] = events[i - 1];
            events[i - 1] = temp;
            i--;
        }
    }






    void ascendingOrder() {
        if (size == 0) {
            cout << "No train events scheduled." << endl;
            return;
        }

        cout << "Train Events in Ascending Order of Time:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Train ID: " << events[i].trainID << ", TimeStamp: " << events[i].timeStamp << ", Status: " << events[i].status << endl;
        }
    }






    void findTrain() {
        if (size == 0) {
            cout << "No train events available." << endl;
            return;
        }

        cout << "Train Event with Minimum TimeStamp:" << endl;
        cout << "Train ID: " << events[0].trainID << ", TimeStamp: " << events[0].timeStamp << ", Status: " << events[0].status << endl;
    }
};







int main() {
    TrainSchedule schedule;

    schedule.insert("TrainA", 1500, "Arrival");
    schedule.insert("TrainB", 1200, "Departure");
    schedule.insert("TrainC", 1300, "Arrival");

    schedule.ascendingOrder();

    schedule.findTrain();

    return 0;
}
