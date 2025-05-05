#include<iostream>
using namespace std;

struct FlightNode {
    int row;       
    int col;       
    int value;    
    FlightNode* next; 
    FlightNode* prev;  
};

class SparseMatrix {
private:
    FlightNode* first;
    FlightNode* last;  

public:
    SparseMatrix() {
        first= NULL;
        last= NULL;
    }

    void addFlight(int row, int col, int value) {
        if (value == 0) 
            return; 
        
        FlightNode* newNode = new FlightNode;
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (first == NULL)
            first=last=newNode;
        else{
            last->next =newNode;
            newNode->prev=last; 
            last=newNode;
        }
    }

    SparseMatrix transpose() {
        SparseMatrix transposedMatrix;
        FlightNode* temp = first;

        while (temp!= NULL) {
            transposedMatrix.addFlight(temp->col, temp->row, temp->value);
            temp=temp->next;
        }
        return transposedMatrix;
    }

    SparseMatrix add(SparseMatrix otherMatrix) {
        SparseMatrix resultMatrix;
        FlightNode* temp1 =first;
        FlightNode* temp2 =otherMatrix.first;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->row == temp2->row && temp1->col==temp2->col){
                resultMatrix.addFlight(temp1->row, temp1->col, temp1->value + temp2->value);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } 
            else if(temp1->row < temp2->row || (temp1->row == temp2->row && temp1->col < temp2->col)) {
                resultMatrix.addFlight(temp1->row, temp1->col, temp1->value);
                temp1 = temp1->next;
            } 
            else {
                resultMatrix.addFlight(temp2->row, temp2->col, temp2->value);
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            resultMatrix.addFlight(temp1->row, temp1->col, temp1->value);
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            resultMatrix.addFlight(temp2->row, temp2->col, temp2->value);
            temp2 = temp2->next;
        }

        return resultMatrix;
    }

    SparseMatrix multiply(SparseMatrix otherMatrix) {
        SparseMatrix resultMatrix;

        FlightNode* temp1 = first;
        while (temp1 != NULL) {
            FlightNode* temp2 = otherMatrix.first;

            while (temp2 != NULL) {
                if (temp1->col == temp2->row) {
                    resultMatrix.addFlight(temp1->row, temp2->col, temp1->value * temp2->value);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return resultMatrix;
    }

    void printMatrix(int numAirports) {
        FlightNode* temp = first;

        for (int i = 0; i < numAirports; i++) {
            for (int j = 0; j < numAirports; j++) {
                bool found = false;
                temp = first;
                while (temp != NULL) {
                    if (temp->row == i && temp->col == j) {
                        cout << temp->value << " ";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix week1;
    week1.addFlight(0, 1, 3);
    week1.addFlight(0, 3, 4);
    week1.addFlight(1, 2, 5);
    week1.addFlight(1, 3, 7);
    week1.addFlight(3, 1, 2);
    week1.addFlight(3, 2, 6);

    cout << "Week 1 Flight Matrix:" << endl;
    week1.printMatrix(4);

    SparseMatrix week2;
    week2.addFlight(0, 1, 1);
    week2.addFlight(1, 2, 3);
    week2.addFlight(1, 3, 1);
    week2.addFlight(3, 0, 1);

    cout << "Week 2 Flight Matrix:" << endl;
    week2.printMatrix(4);

    SparseMatrix totalFlights = week1.add(week2);
    cout << "Total Flights Matrix (Week1 + Week2):" << endl;
    totalFlights.printMatrix(4);

    SparseMatrix transposedMatrix = week1.transpose();
    cout << "Transposed Flight Matrix (Week 1):" << endl;
    transposedMatrix.printMatrix(4);

    SparseMatrix multiplyMetrix=week1.multiply(week2);
    cout<<"Multiply:"<<endl;
    multiplyMetrix.printMatrix(4);

    return 0;
}
