#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    int heartRate;
    int sysBP;
    int spo2;
    int priorityScore; // 1 (Highest) to 5 (Lowest)
};

class TriageEngine {
public:
    int calculatePriority(int hr, int bp, int ox) {
        // Simple logic based on ESI concepts
        if (ox < 85 || (hr > 140 || hr < 40)) return 1; // Resuscitation
        if (ox < 92 || bp > 180) return 2;             // Emergent
        if (hr > 110 || bp > 150) return 3;            // Urgent
        return 4;                                      // Non-urgent
    }

    void processPatient(string name, int hr, int bp, int ox) {
        Patient p = {name, hr, bp, ox, calculatePriority(hr, bp, ox)};
        displayTriageCard(p);
    }

private:
    void displayTriageCard(Patient p) {
        cout << "\n------------------------------------" << endl;
        cout << "   HOSPITAL TRIAGE ASSIGNMENT       " << endl;
        cout << "------------------------------------" << endl;
        cout << "PATIENT: " << p.name << endl;
        cout << "VITALS: HR " << p.heartRate << " | BP " << p.sysBP << " | SpO2 " << p.spo2 << "%" << endl;
        cout << "PRIORITY LEVEL: " << p.priorityScore << endl;
        cout << "ACTION: " << (p.priorityScore == 1 ? "IMMEDIATE INTERVENTION" : "MOVE TO WAITING AREA") << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    TriageEngine engine;
    
    // Simulating a critical patient
    engine.processPatient("Patient_Alpha", 155, 190, 88);
    
    // Simulating a stable patient
    engine.processPatient("Patient_Beta", 75, 120, 98);

    return 0;
}
